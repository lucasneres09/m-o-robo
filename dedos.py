import cv2
from cvzone.HandTrackingModule import HandDetector
import serial
import time

# ⚠️ ajuste a porta
arduino = serial.Serial('COM8', 9600)
time.sleep(2)

cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=1)

while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)

    if hands:
        hand = hands[0]
        fingers = detector.fingersUp(hand)

        # ✔ lógica NORMAL (SEM inverter aqui)
        msg = f"{fingers[0]},{fingers[1]},{fingers[2]},{fingers[3]},{fingers[4]}\n"
        arduino.write(msg.encode())

    cv2.imshow("Mao Robo", img)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break