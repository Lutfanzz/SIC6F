import machine
import time
import network
import dht
import urequests

wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect("CTAF Sukoharjo","Bintang#1")

while not wlan.isconnected():
    print(".",end="")
    time.sleep(.1)

print("WLAN is connected")
UBIDOTS_ENDPOINT = "https://industrial.api.ubidots.com/api/v1.6/devices/esp32-dorminder/"
FLASK_ENDPOINT = "http://192.168.1.234:5003/save"


sensor = dht.DHT11(machine.Pin(15))
while True:
    sensor.measure()
    suhu = sensor.temperature()
    kelembaban = sensor.humidity()
    print(f"Suhu = {suhu} C, kelembaban = {kelembaban} %")
    
    data = {"suhu":suhu,"kelembaban":kelembaban}
    headers = {"Content-Type":"application/json","X-Auth-Token":"BBUS-7kchE2KvM3jSIBPuRNQfNqwzaawOfH"}
    response = urequests.post(UBIDOTS_ENDPOINT,json=data,headers=headers)
    
    print(f"response ubidots: {response.status_code}")
    response.close()
    
    
    headers = {"Content-Type":"application/json"}
    response = urequests.post(FLASK_ENDPOINT,json=data,headers=headers)
    
    print(f"response flask: {response.status_code}")
    response.close()
    
