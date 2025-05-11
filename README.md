# Automated Weapon Detection 
## Overview
The project contains two files of code, python and C++ (arduino) which are used to automate weapon sensing remotely without the use of any sensors. Intead, a camera CCTV is used as the primary physical equipment and its feed is given the sensor abilities by the use of the YOLO object detection machine learning model.
The python code is compiled on Jupyter Notebook as IDE which serves the main purpose o training the custom model on images of weapons and using openCV to obtain the camera feed. It also calls the ardiuno code into action if certain conditions are met. The C++ code serves the purpose of running the feedback equipment which is the GSM module for reporting the findings. 
## Components
### Software
1. YOLO ML model
2. yaml file
3. Jupyter Notebook
4. Arduino IDE
5. OpenCV
6. LabelImg
7. Kaggle dataset
### Hardware
1. CCTV IP camera (Digital)
2. Arduino controller
3. Processor (Computer)
4. Servo motor (Optional)
5. GSM module
6. Power supply
## Use
The LabelImg is used for image annotation, labelling the images and creating the bounding boxes around the target training objects.
The yaml file is used for giving the file root dircetory for the training process to find the dataset location during training and also contains the list of target labels. i.e. person, gun, etc
OpenCV is used to obtain the camera feed ans subject its output to modifictaions via python
Kaggle dataset offers the images used for model training
Jupyter is the IDE used for pyhton
A digital CCTV camera is recommended because unlike an analogue camera is does not need additional equipmet for conversion of data from analogue. Also, it pairs directly either via WiFi or Ethernet cable
The computer processor determines the model size one will use, the number of iterations in training and the batch size. Otherwise the training process will be slow taking up to a week.
Power supply to the camera, to the GSM module, and processor

## Challenges
YOLO works best with still or common backgrounds. this means the backgound used in training should be be the same to use in the implementation. This is a significant basis for its accuracy, which if met, it remains the best accuracy model of object detection. 
Occlusion of the object being detected affects accuracy.



