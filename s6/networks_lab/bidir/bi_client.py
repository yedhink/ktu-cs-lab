#!/usr/bin/env python3
# coding=utf-8
import socket
from threading import Thread

client = socket.socket()
client.connect(("172.16.104.14", 8080))


def RecvFromServer():
    while True:
        msg = client.recv(1000)
        if msg == b"Exit":
            print("Client is closing")
            client.close()
        print("\nServer> {}\nClient> ".format(msg.decode()))


def SendToServer():
    while True:
        msg = input("Client> ")
        client.send(msg.encode())


def main():
    print("Client Running...")
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
