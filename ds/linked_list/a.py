import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

led_pins = [2, 3, 4] 

for pin in led_pins:
    GPIO.setup(pin, GPIO.OUT)

while True:
    for pin in led_pins:
        GPIO.output(pin, GPIO.HIGH)  # Turn on LED
        print(f"LED {pin} on")
        time.sleep(1)
        GPIO.output(pin, GPIO.LOW)   # Turn off LED
        print(f"LED {pin} off")
        time.sleep(1)
    print("All LEDs off")
    time.sleep(1)