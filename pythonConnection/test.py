import socket
from connectionInformation import ip, port
import time 
import pyautogui as py
import requests
import json 

url = 'https://thesimpsonsquoteapi.glitch.me/quotes'

receivingData = True

def pressKey(key):
    py.press(key)

def getQuote():
    response = requests.get(url)
    if response.status_code == '404':
        print('could not find website')
    else:
        x = response.json()
        p = json.loads(response.text)
        y = p[0]['quote']
        #make sure quote can fit on lcd
        if (len(y) < 60):
            return y
        else:
            #get new quote
            getQuote()

        
if __name__ == '__main__':
  
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ip, port))

    #send quote to esp32
    q = getQuote()
    s.sendto(q.encode(),(ip, port))

    while(receivingData==True):
        #keep running while connected to a host
        data = s.recv(1024)
        print(repr(data))
        pressKey(data)

    #close connection if no longer receivign data from host
    s.close()

    
