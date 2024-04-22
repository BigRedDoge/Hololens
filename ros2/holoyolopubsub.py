import rclpy
from rclpy.node import Node

from yolo_interface.msg import ImageMsg                       


class HoloYoloSubPub(Node):

    def __init__(self):
        super().__init__('holoyolosubpub')
        self.subscription = self.create_subscription(
            ImageMsg,                                               
            'camera',
            self.listener_callback,
            10)
        self.subscription

    def listener_callback(self, msg):
            self.get_logger().info('I heard: "%d"' % msg.height) 


def main(args=None):
    rclpy.init(args=args)

    holoyolo = HoloYoloSubPub()

    rclpy.spin(holoyolo)

    holoyolo.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()