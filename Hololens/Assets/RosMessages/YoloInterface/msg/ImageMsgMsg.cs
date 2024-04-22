//Do not edit! This file was generated by Unity-ROS MessageGeneration.
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Unity.Robotics.ROSTCPConnector.MessageGeneration;

namespace RosMessageTypes.YoloInterface
{
    [Serializable]
    public class ImageMsgMsg : Message
    {
        public const string k_RosMessageName = "yolo_interface/ImageMsg";
        public override string RosMessageName => k_RosMessageName;

        //  This message contains an uncompressed image
        //  (0, 0) is at top-left corner of image
        public uint height;
        //  image height, that is, number of rows
        public uint width;
        //  image width, that is, number of columns
        //  The legal values for encoding are in file include/sensor_msgs/image_encodings.hpp
        //  If you want to standardize a new string format, join
        //  ros-users@lists.ros.org and send an email proposing a new encoding.
        public string encoding;
        //  Encoding of pixels -- channel meaning, ordering, size
        //  taken from the list of strings in include/sensor_msgs/image_encodings.hpp
        public byte is_bigendian;
        //  is this data bigendian?
        public uint step;
        //  Full row length in bytes
        public byte[] data;
        //  actual matrix data, size is (step * rows)

        public ImageMsgMsg()
        {
            this.height = 0;
            this.width = 0;
            this.encoding = "";
            this.is_bigendian = 0;
            this.step = 0;
            this.data = new byte[0];
        }

        public ImageMsgMsg(uint height, uint width, string encoding, byte is_bigendian, uint step, byte[] data)
        {
            this.height = height;
            this.width = width;
            this.encoding = encoding;
            this.is_bigendian = is_bigendian;
            this.step = step;
            this.data = data;
        }

        public static ImageMsgMsg Deserialize(MessageDeserializer deserializer) => new ImageMsgMsg(deserializer);

        private ImageMsgMsg(MessageDeserializer deserializer)
        {
            deserializer.Read(out this.height);
            deserializer.Read(out this.width);
            deserializer.Read(out this.encoding);
            deserializer.Read(out this.is_bigendian);
            deserializer.Read(out this.step);
            deserializer.Read(out this.data, sizeof(byte), deserializer.ReadLength());
        }

        public override void SerializeTo(MessageSerializer serializer)
        {
            serializer.Write(this.height);
            serializer.Write(this.width);
            serializer.Write(this.encoding);
            serializer.Write(this.is_bigendian);
            serializer.Write(this.step);
            serializer.WriteLength(this.data);
            serializer.Write(this.data);
        }

        public override string ToString()
        {
            return "ImageMsgMsg: " +
            "\nheight: " + height.ToString() +
            "\nwidth: " + width.ToString() +
            "\nencoding: " + encoding.ToString() +
            "\nis_bigendian: " + is_bigendian.ToString() +
            "\nstep: " + step.ToString() +
            "\ndata: " + System.String.Join(", ", data.ToList());
        }

#if UNITY_EDITOR
        [UnityEditor.InitializeOnLoadMethod]
#else
        [UnityEngine.RuntimeInitializeOnLoadMethod]
#endif
        public static void Register()
        {
            MessageRegistry.Register(k_RosMessageName, Deserialize);
        }
    }
}
