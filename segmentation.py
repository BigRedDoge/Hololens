from ultralytics import YOLO
import torchvision.transforms as T
from PIL import Image
import cv2
import torch
import numpy as np


def main():
    model = YOLO('/Users/sean/Downloads/best.pt')
    if torch.cuda.is_available():
        model.to('cuda')

    model.conf = 0.05

    cap = cv2.VideoCapture(0)
    while True: 
        #ret, frame = cap.read()
        frame = cv2.imread('crack.jpeg')
        #frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        result = model.predict(frame, conf=0.5, verbose=False)
        #print(result)
        if result[0].masks:
            print("found mask")
            for mask in result[0].masks:
                #print(mask)
                single_mask = mask.data[0].cpu().numpy()
                single_mask = cv2.resize(single_mask, (frame.shape[1], frame.shape[0]))
                frame[single_mask > 0.5] = [0, 255, 0]
                # Draw mask in green on the frame
                cv2.imshow('frame', frame)

        cv2.imshow('frame', frame) 

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

if __name__ == '__main__':
    main()