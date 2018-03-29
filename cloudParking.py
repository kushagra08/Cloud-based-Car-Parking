import httplib2
import serial

ser = serial.Serial('COM3', 9600,timeout=2)
a=0    
while True:
    ch=(ser.readline().strip())
    r=list(ch)
    t=''
    for i in range(len(ch)):
        t+=chr(r[i])
    print(t)
    conn = httplib2.Http()
    if(t=="Occupied"):
        a=1
        conn.request("https://api.thingspeak.com/update?api_key=PIF4AY4XL5JRVUKH&field1=1")
    else:
        a=0
        conn.request("https://api.thingspeak.com/update?api_key=PIF4AY4XL5JRVUKH&field1=0")
    print("a=",a)
   
