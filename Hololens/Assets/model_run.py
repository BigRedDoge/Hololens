from ultralytics import YOLO
import numpy as np
from PIL import Image


print("test")
model = YOLO(r"C:\Users\Sean\Documents\Hololens\Assets\Application\best.pt")
print("test2")
image = Image.open(r"C:\Users\Sean\Documents\Hololens\Assets\Application\cracks.jpg")
image = np.array(image)
result = model.predict(image, conf=0.1)
print(result)
