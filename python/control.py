import serial
import keyboard
import time

ser = serial.Serial('COM4', 115200)

def send_command(command):
    ser.write(command.encode()) 
    response = ser.readline().decode().strip()  
    print(response)

try:
    while True:
        if keyboard.is_pressed('g'):
            print("Stepper motor: GO")
            send_command('G')
            time.sleep(0.1) 
        elif keyboard.is_pressed('s'):
            print("Stepper motor: STOP")
            send_command('S')
            time.sleep(0.1)  

except KeyboardInterrupt:
    print("\nExiting...")
    ser.close()
