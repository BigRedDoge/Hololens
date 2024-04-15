from ultralytics import YOLO
from PIL import Image
import cv2
import torch

# Initialize
model = YOLO('detection.onnx')
if torch.cuda.is_available():
    model.cuda()

# Image
img = cv2.imread('crack.jpeg')
# Inference
results = model.predict(img, conf=0.5, imgsz=[256, 320])

# display bounding box on imag
for result in results[0].boxes.xyxy:
    result = result.numpy()
    cv2.rectangle(img, (int(result[0]), int(result[1])), (int(result[2]), int(result[3])), (0, 255, 0), 2)

cv2.imshow('crack', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
