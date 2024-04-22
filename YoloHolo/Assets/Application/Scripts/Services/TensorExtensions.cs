using System;
using System.Collections.Generic;
using System.Linq;
using Unity.Barracuda;
using UnityEngine;

namespace YoloHolo.Services
{
    public static class TensorExtensions
    {
        /*
         * This method is used to get the Yolo data from the tensor.
         * It takes the tensor, a translator, the minimum probability, the overlap threshold, and the Yolo version.
         * It returns a list of Yolo items.
        */
        public static List<YoloItem> GetYoloData(this Tensor tensor, IYoloClassTranslator translator, 
            float minProbability, float overlapThreshold, YoloVersion version = YoloVersion.V7)
        {
            if (version == YoloVersion.V7)
            {
                return tensor.ProcessV7Item(translator, minProbability, overlapThreshold, version);
            }
            if (version == YoloVersion.V8)
            {
                return tensor.ProcessV8Item(translator, minProbability, overlapThreshold, version);
            }

            throw new ArgumentException($"Unsupported Yolo version {version}");
        }

        public static List<YoloSegmentationItem> GetYoloData(this Tensor tensor, IYoloClassTranslator translator,
            float minProbability, YoloVersion version = YoloVersion.Segmentation)
        {
            if (version == YoloVersion.SEGMENTATION)
            {
                return tensor.ProcessSegmentationItem(translator, minProbability, version);
            }
            throw new ArgumentException($"Unsupported Yolo version {version}");
        }


        private static List<YoloSegmentationItem> ProcessSegmentationItem(this Tensor tensor, IYoloClassTranslator translator,
            float minProbability, YoloVersion version)
        {
            float maxConfidence = 0;
            var masksMeetingConfidenceLevel = new List<YoloSegmentationItem>();
            for (var i = 0; i < tensor.width; i++)
            {
                var yoloItem = new YoloSegmentationItem(tensor, i, translator, version);
                maxConfidence = yoloItem.Confidence > maxConfidence ? yoloItem.Confidence : maxConfidence;
                if (yoloItem.Confidence > minProbability)
                {
                    masksMeetingConfidenceLevel.Add(yoloItem);
                }
            }

            Debug.Log($"max confidence = {maxConfidence}");

            return FindMostLikelySegObject(masksMeetingConfidenceLevel, overlapThreshold);
        }

        private static List<YoloItem> ProcessV7Item(this Tensor tensor, IYoloClassTranslator translator,
            float minProbability, float overlapThreshold, YoloVersion version)
        {
            float maxConfidence = 0;
            var boxesMeetingConfidenceLevel = new List<YoloItem>();
            for (var i = 0; i < tensor.channels; i++)
            {
                var yoloItem = YoloItem.Create(tensor, i, translator, version);
                maxConfidence = yoloItem.Confidence > maxConfidence ? yoloItem.Confidence : maxConfidence;
                if (yoloItem.Confidence > minProbability)
                {
                    boxesMeetingConfidenceLevel.Add(yoloItem);
                }
            }

            Debug.Log($"max confidence = {maxConfidence}");

            return FindMostLikelyObject(boxesMeetingConfidenceLevel, overlapThreshold);
        }

        /*
         * This method is used to find the most likely object.
         * It takes a tensor (camera), class translator, minimum class probability, overlap threshold, and yolo version.
         * It loops through the tensor and creates a new YoloItem fo each
         *  if the confidence is greater than the minimum probability it adds it to the list of boxesMeetingConfidenceLevel.
         * returns the most likely object.
        */
        private static List<YoloItem> ProcessV8Item(this Tensor tensor, IYoloClassTranslator translator,
            float minProbability, float overlapThreshold, YoloVersion version)
        {
            float maxConfidence = 0;
            var boxesMeetingConfidenceLevel = new List<YoloItem>();
            for (var i = 0; i < tensor.width; i++)
            {
                var yoloItem = YoloItem.Create(tensor, i, translator, version);
                maxConfidence = yoloItem.Confidence > maxConfidence ? yoloItem.Confidence : maxConfidence;
                if (yoloItem.Confidence > minProbability)
                {
                    boxesMeetingConfidenceLevel.Add(yoloItem);
                }
            }

            Debug.Log($"max confidence = {maxConfidence}");

            return FindMostLikelyObject(boxesMeetingConfidenceLevel, overlapThreshold);
        }

        /*
         * This method is used to find the most likely object.
         * It takes a list of Yolo items and an overlap threshold.
         * It finds the most likely object in the list of boxesMeetingConfidenceLevel.
         * returns the result.
        */
        private static List<YoloItem> FindMostLikelyObject(List<YoloItem> boxesMeetingConfidenceLevel, float overlapThreshold)
        {
            var result = new List<YoloItem>();
            var recognizedTypes = boxesMeetingConfidenceLevel.Select(b => b.MostLikelyObject).Distinct();
            foreach (var objType in recognizedTypes)
            {
                var boxesOfThisType = boxesMeetingConfidenceLevel.Where(b => b.MostLikelyObject == objType).ToList();
                result.AddRange(RemoveOverlappingBoxes(boxesOfThisType, overlapThreshold));
            }

            return result;
        }

        private static List<YoloSegmentationItem> FindMostLikelySegObject(List<YoloSegmentationItem> masksMeetingConfidenceLevel)
        {
            var result = new List<YoloSegmentationItem>();
            var recognizedTypes = masksMeetingConfidenceLevel.Select(b => b.MostLikelyObject).Distinct();
            foreach (var objType in recognizedTypes)
            {
                var masksOfThisType = masksMeetingConfidenceLevel.Where(b => b.MostLikelyObject == objType).ToList();
                result.AddRange(masksOfThisType);
            }

            return result;
        }


        // Code below largely courtesy of ChatGPT
        private static List<YoloItem> RemoveOverlappingBoxes(
            List<YoloItem> boxesMeetingConfidenceLevel, 
            float overlapThreshold)
        {
            // sort the boxesMeetingsConfidenceLevel by their confidence score in descending order  
            boxesMeetingConfidenceLevel.Sort((a, b) => b.Confidence.CompareTo(a.Confidence));
            var selectedBoxes = new List<YoloItem>();

            // loop through each box and check for overlap with higher-confidence boxesMeetingsConfidenceLevel  
            while (boxesMeetingConfidenceLevel.Count > 0)
            {
                var currentBox = boxesMeetingConfidenceLevel[0];
                selectedBoxes.Add(currentBox);
                boxesMeetingConfidenceLevel.RemoveAt(0);

                // compare the current box with all remaining boxesMeetingsConfidenceLevel  
                for (var i = 0; i < boxesMeetingConfidenceLevel.Count; i++)
                {
                    var otherBox = boxesMeetingConfidenceLevel[i];
                    var overlap = ComputeIoU(currentBox, otherBox);
                    if (overlap > overlapThreshold)
                    {
                        // remove the box if it has a high overlap with the current box  
                        boxesMeetingConfidenceLevel.RemoveAt(i);
                        i--;
                    }
                }
            }

            return selectedBoxes;
        }

        private static float ComputeIoU(YoloItem boxA, YoloItem boxB)
        {
            var xA = Math.Max(boxA.TopLeft.x, boxB.TopLeft.y);
            var yA = Math.Max(boxA.TopLeft.y, boxA.TopLeft.y);
            var xB = Math.Min(boxA.BottomRight.x, boxB.BottomRight.x);
            var yB = Math.Min(boxA.BottomRight.y, boxB.BottomRight.y);

            var intersectionArea = Math.Max(0, xB - xA + 1) * Math.Max(0, yB - yA + 1);
            var boxAArea = boxA.Size.x * boxA.Size.y;
            var boxBArea = boxB.Size.y * boxB.Size.y;
            var unionArea = boxAArea + boxBArea - intersectionArea;

            return intersectionArea / unionArea;
        }
    }
}
