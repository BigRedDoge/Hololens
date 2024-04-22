using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.YoloInterface;

public class CameraPublisher : MonoBehaviour
{
    public Camera cam;
    public string topicName = "yolo_image";
    public int frameRate = 1;

    [SerializeField]
    private int cameraFPS = 1;

    [SerializeField]
    private Vector2Int requestedCameraSize = new(896, 504);

    private ROSConnection ros;
    //private Texture2D texture;
    private byte[] image;
    private int width;
    private int height;

    private WebCamTexture webCamTexture;

    void Start()
    {
        ros = ROSConnection.GetOrCreateInstance();
        ros.RegisterPublisher<ImageMsgMsg>(topicName);

        webCamTexture = new WebCamTexture(requestedCameraSize.x, requestedCameraSize.y, cameraFPS);
        webCamTexture.Play();

        //width = cam.pixelWidth;
        //height = cam.pixelHeight;
        //renderTexture = new Texture2D(width, height, TextureFormat.RGB24, false);
        image = new byte[width * height * 3];

        InvokeRepeating("PublishImage", 0, 1.0f / frameRate);
    }

    void PublishImage()
    {
        //actualCameraSize = new Vector2Int(webCamTexture.width, webCamTexture.height);
        var renderTexture = new RenderTexture(webCamTexture.width, webCamTexture.height, 24);
        
        //var cameraTransform = Camera.main.CopyCameraTransForm();
        Graphics.Blit(webCamTexture, renderTexture);

        Texture2D texture = new Texture2D(renderTexture.width, renderTexture.height, TextureFormat.RGB24, false);
        var oldRt = RenderTexture.active;
        RenderTexture.active = renderTexture;

        texture.ReadPixels(new Rect(0, 0, renderTexture.width, renderTexture.height), 0, 0);
        texture.Apply();

        RenderTexture.active = oldRt;

        byte[] imageBytes = texture.EncodeToPNG(); // Convert texture to bytes

        //byte[] bytes = new byte[width * height * 3];

        ImageMsgMsg msg = new ImageMsgMsg
        {
            height = (uint)height,
            width = (uint)width,
            encoding = "rgb8",
            is_bigendian = 0,
            step = (uint)(width * 3),
            data = imageBytes
        };

        ros.Publish(topicName, msg);
        Debug.Log("Published image");

        Destroy(texture);
    }

}