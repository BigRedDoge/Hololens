using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.YoloInterface;
using UnityEngine.UI;


public class YoloSubscriber : MonoBehaviour
{
    public string topicName = "yolo_data";
    private ROSConnection ros;
    private YoloMsg yoloMsg;
    //public GameObject display;
    public RawImage display;

    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();
        ros.Subscribe<ImageMsgMsg>(topicName, YoloDetection);
        //display = GameObject.Find("Cube");
    }

    void YoloDetection(ImageMsgMsg msg)
    {
        Debug.Log("Received Yolo detection");
        //Debug.Log("Number of cracks detected: " + msg.detections);
        Texture2D texture = new Texture2D((int)msg.width, (int)msg.height, TextureFormat.RGB24, false);
        //texture.LoadImage(msg.data);
        texture.LoadRawTextureData(msg.data);
        texture.Apply();
        display.texture = texture;
        // Do something with the texture
        //GameObject objectToApplyTexture = GameObject.Find("ObjectName"); 
        //display.GetComponent<Renderer>().material.mainTexture = texture;
    }
}