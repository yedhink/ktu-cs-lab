#!/usr/bin/env python3
# coding=utf-8
import socket
from threading import Thread
from datetime import datetime

IP_ADDR = "172.16.104.14"
PORT = 8081
all_cl = []
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind((IP_ADDR, PORT))


def Get():
    while True:
        c_msg, client = server.recvfrom(1000)
        print("\n{} has joined the chat".format(client[0]))
        msg = str(datetime.now())
        server.sendto(msg.encode(), client)


def main():
    print("Server Running at {}...".format(IP_ADDR))
    try:
        t1 = Thread(target=Get)
        t1.start()
    except KeyboardInterrupt:
        print("Closing connection...")
        server.close()


if __name__ == "__main__":
    main()
