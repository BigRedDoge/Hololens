from ultralytics import YOLO
import cv2

model = YOLO(r"\Assets\Application\best.pt")
image = cv2.imread(r"\Assets\Application\cracks.jpg")
result = model.predict(image, conf=0.1)
