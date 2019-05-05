#!/usr/bin/env python3
# coding=utf-8
import socket
from os import listdir
from threading import Thread
import base64

IP_ADDR = "172.16.104.6"
PORT = 8081
# max size 10kb
MAX_FILE_SIZE = 10000
extension = []
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


def RecvFromServer():
    while True:
        msg = ""
        flag = False
        serv = client.recvfrom(MAX_FILE_SIZE + 1)
        msg = serv[0].decode()
        if len(msg) > MAX_FILE_SIZE:
            print("\nFile cant be downloaded since it exceeds file size limit of 10kb")
            continue
        if msg == "no such file exists":
            print("\nThe requested file doesnt exist in the server\nClient> ", end="")
            continue
        print("\nImage received succesfully\nClient> ", end="")
        file = open(
            "received_image_{}.{}".format(len(listdir(".")), extension[0]), "wb+"
        )
        img = base64.b64decode(msg)
        file.write(img)
        file.close()


def SendToServer():
    while True:
        msg = input("Client> ")
        pos = -1
        for x, i in enumerate(msg):
            if i == ".":
                pos = x + 1
                break
        if pos == -1:
            print("*****Enter the filename as msg, like so :- img1.png*****")
        else:
            if len(extension) == 0:
                extension.append(msg[pos:])
            else:
                extension[0] = msg[pos:]
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
