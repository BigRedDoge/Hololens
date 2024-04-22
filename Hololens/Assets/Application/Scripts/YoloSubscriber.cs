using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.YoloInterface;

public class YoloSubscriber : MonoBehaviour
{
    public string topicName = "yolo_data";
    private ROSConnection ros;
    private YoloMsg yoloMsg;

    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();
        ros.Subscribe<YoloMsg>(topicName, YoloDetection);
    }

    void YoloDetection(YoloMsg msg)
    {
        Debug.Log("Received Yolo detection");
        //Debug.Log("Number of cracks detected: " + msg.detections);
    }
}