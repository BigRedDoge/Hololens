import rclpy
from rclpy.node import Node
from ultralytics import YOLO
import numpy as np
import cv2

from yolo_interface.msg import ImageMsg, Yolo     


class HoloYoloSubPub(Node):

    def __init__(self):
        super().__init__('holoyolosubpub')
        self.subscription = self.create_subscription(
            ImageMsg,                                               
            'yolo_image',
            self.listener_callback,
            10)
        self.subscription
        self.publisher_ = self.create_publisher(ImageMsg, 'yolo_data', 10)
        print("Starting holo_yolo subscriber")
        self.model = YOLO('best.pt')

    def listener_callback(self, msg):
        #self.get_logger().info('I heard: "%d"' % msg.height) 
        #print(msg)
        image = np.asarray(bytearray(msg.data), dtype="uint8")
        image = cv2.imdecode(image, cv2.IMREAD_COLOR)
        #print(image)
        result = self.model.predict(image, conf=0.65)
        if result[0].masks:
            print(f"Found {str(len(result[0].masks))} cracks")
            for mask in result[0].masks:
                single_mask = mask.data[0].cpu().numpy()
                single_mask = cv2.resize(single_mask, (image.shape[1], image.shape[0]))
                image[single_mask > 0.5] = [0, 255, 0]
            #cv2.imwrite('detection.png', image)
            image = cv2.flip(image, 0)
            image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
            msg = ImageMsg()
            #msg.detections = len(result[0].masks)
            #msg.data = cv2.imencode('.png', image)[1].tobytes()
            msg.data = np.array(image).tobytes()
            #print(msg.data)
            msg.width = image.shape[1]
            msg.height = image.shape[0]
            msg.is_bigendian = 0
            msg.encoding = "rgb8"
            msg.step = 0
            self.publisher_.publish(msg)
                


def main(args=None):
    rclpy.init(args=args)

    holoyolo = HoloYoloSubPub()

    rclpy.spin(holoyolo)

    holoyolo.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
