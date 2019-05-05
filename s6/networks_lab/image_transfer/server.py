#!/usr/bin/env python3
# coding=utf-8
import socket
from threading import Thread
import base64
from os import listdir

IP_ADDR = "172.16.104.6"
PORT = 8081
all_cl = []
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind((IP_ADDR, PORT))


def Post(file_name):
    img = open(file_name, "rb+")
    image = base64.b64encode(img.read())
    for addr in all_cl:
        # server.sendto(image,addr)
        server.sendall(image)


def Get():
    while True:
        c_msg, client = server.recvfrom(1000)
        c_msg = c_msg.decode()
        if c_msg not in listdir(".") and c_msg != "":
            print("Server> Oops. File not found")
            server.sendto("no such file exists".encode(), client)
            continue
        all_cl.append(client)
        print("\n{} has requested for the image {}".format(client[0], c_msg))
        Post(c_msg)


def main():
    print("Server Running at {}...".format(IP_ADDR))
    try:
        t2 = Thread(target=Get)
        t2.start()
    except KeyboardInterrupt:
        print("Closing connection...")
        server.close()


if __name__ == "__main__":
    main()
