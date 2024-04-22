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
        self.publisher_ = self.create_publisher(Yolo, 'yolo_data', 10)
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
            msg = Yolo()
            msg.detections = len(result[0].masks)
            self.publisher_.publish(msg)
            for mask in result[0].masks:
                single_mask = mask.data[0].cpu().numpy()
                


def main(args=None):
    rclpy.init(args=args)

    holoyolo = HoloYoloSubPub()

    rclpy.spin(holoyolo)

    holoyolo.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
