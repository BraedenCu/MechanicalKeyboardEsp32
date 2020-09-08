import socket
from connectionInformation import ip, port
import time 

receivingData = True

if __name__ == '__main__':

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ip, port))

    while(receivingData==True):
        #keep running while connected to a client
        data = s.recv(1024)
        print(repr(data))
        print("receiving")
        time.sleep(1)
    
    s.close()

    