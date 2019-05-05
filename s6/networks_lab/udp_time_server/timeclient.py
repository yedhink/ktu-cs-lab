#!/usr/bin/env python3
# coding=utf-8
import socket
from threading import Thread

IP_ADDR = "172.16.104.14"
PORT = 8081
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


def RecvFromServer():
    client.sendto(b"", (IP_ADDR, PORT))
    serv = client.recvfrom(1000)
    msg = serv[0]
    if msg == b"Exit":
        print("Client is closing")
        client.close()
    print("\System date : {}".format(msg.decode()))


def main():
    print("UDP Client Running...")
    try:
        RecvFromServer()
    except KeyboardInterrupt:
        print("Closing connection...")
        client.close()


if __name__ == "__main__":
    main()
