from ultralytics import YOLO
import torchvision.transforms as T
from PIL import Image
import cv2
import torch
import numpy as np


def main():
    model = YOLO(r'best.pt')
    if torch.cuda.is_available():
        model.to('cuda')

    model.conf = 0.05

    cap = cv2.VideoCapture(0)
    while True: 
        #ret, frame = cap.read()
        frame = cv2.imread('crack.jpeg')
        #frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        result = model.predict(frame, conf=0.4, verbose=False)

        if result[0].masks:
            for mask in result[0].masks:
                #print(mask)
                single_mask = mask.data[0].cpu().numpy()
                # Threshold the mask to get binary image
                _, thresh = cv2.threshold(single_mask, 0.5, 1, cv2.THRESH_BINARY)
                # Find contours in the binary image
                contours, _ = cv2.findContours(thresh.astype(np.uint8), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
                # Draw contours on the original frame
                cv2.drawContours(frame, contours, -1, (0,255,0), 3)

        cv2.imshow('frame', frame) 

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

if __name__ == '__main__':
    main()