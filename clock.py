import max7219.led as led 
import time
import os

device = led.sevensegment(cascaded=1)
device.brightness(15)

#device.write_text(0, "HELLO")
o = [6,66,96,48,24,12]
#device.brightness(15)
b=0
while True:
   for i in range(4):
      t=time.strftime("%H%M%S");
      #print(t);
      device.letter(deviceId=0, position=1, char=t[0], dot=i==0, redraw=True)
      device.letter(deviceId=0, position=2, char=t[1], dot=i==1, redraw=True)
      device.letter(deviceId=0, position=3, char=t[2], dot=i==2, redraw=True)
      device.letter(deviceId=0, position=4, char=t[3], dot=i==3, redraw=True)
      device.letter(deviceId=0, position=6, char=t[4], dot=False, redraw=True)
      device.letter(deviceId=0, position=7, char=t[5], dot=False, redraw=True)
      device.set_byte(deviceId=0, position=5, value=o[b], redraw=True);
      device.set_byte(deviceId=0, position=8, value=o[b], redraw=True);
      #device.letter(deviceId=0, position=7, char='7', dot=True, redraw=True)
      #device.letter(deviceId=0, position=8, char='8', dot=True, redraw=True)
      #device.write_number(deviceId=0, value=3145)
      b=b+1
      if  b>5:
          b=0
      time.sleep(0.25);
