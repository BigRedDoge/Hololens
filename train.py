from ultralytics import YOLO

def main():
    # load model
    model = YOLO(r'C:\Users\Sean\Documents\Robotics\runs\segment\train6\weights\best.pt')
    # set to gpu
    model.to('cuda')

    # train
    for i in range(10):
        model.train(data='./cracks-dataset-9000/data.yaml', epochs=3)
        metrics = model.val()
        #results = model("dataset\test\images\1616.rf.c868709931a671796794fdbb95352c5a.jpg")
        path = model.export()

if __name__ == '__main__':
    main()