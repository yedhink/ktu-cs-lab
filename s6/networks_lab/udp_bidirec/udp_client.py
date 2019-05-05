#!/usr/bin/env python3
# coding=utf-8
import socket
from threading import Thread

IP_ADDR = "172.16.104.14"
PORT = 8081
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


def RecvFromServer():
    while True:
        serv = client.recvfrom(1000)
        msg = serv[0]
        if msg == b"Exit":
            print("Client is closing")
            client.close()
        print("\nServer> {}\nClient> ".format(msg.decode()))


def SendToServer():
    while True:
        msg = input("Client> ")
        client.sendto(msg.encode(), (IP_ADDR, PORT))


def main():
    print("UDP Client Running...")
    try:
        t1 = Thread(target=RecvFromServer, args=())
        t2 = Thread(target=SendToServer, args=())
        t1.start()
        t2.start()
    except KeyboardInterrupt:
        print("Closing connection...")
        client.close()


if __name__ == "__main__":
    main()
