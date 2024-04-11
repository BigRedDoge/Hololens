namespace YoloHolo.Services
{
    public class YoloSegmentationItem : YoloItem
    {
        public float[,] SegmentationMask { get; protected set; }

        internal YoloSegmentationItem(Tensor tensorData, int segIndex, IYoloClassTranslator translator)
        {
            // Assuming tensorData holds the segmentation mask data
            SegmentationMask = new float[tensorData.height, tensorData.width];

            for (var i = 0; i < tensorData.height; i++)
            {
                for (var j = 0; j < tensorData.width; j++)
                {
                    SegmentationMask[i, j] = tensorData[i, j, segIndex, 0];
                }
            }

            var classProbabilities = new List<float>();
            /* this is i=5 in the YoloV8Item class */
            for (var i = 0; i < tensorData.channels; i++)
            {
                classProbabilities.Add(tensorData[0, 0, segIndex, i]);
            }
            var maxIndex = classProbabilities.Any() ? classProbabilities.IndexOf(classProbabilities.Max()) : 0;
            MostLikelyObject = translator.GetName(maxIndex);
        }
    }
}