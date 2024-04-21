from ultralytics import YOLO
import numpy as np
import cv2


print("test")
model = YOLO(r"C:\Users\Sean\Documents\Hololens\Assets\Application\best.pt")
print("test2")
image = cv2.imread(r"C:\Users\Sean\Documents\Hololens\Assets\Application\cracks.jpg")
result = model.predict(image, conf=0.1, device="cpu")
print(result)
