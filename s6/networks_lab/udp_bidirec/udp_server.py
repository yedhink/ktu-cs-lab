#!/usr/bin/env python3
# coding=utf-8
import socket
from threading import Thread

IP_ADDR = "172.16.104.14"
PORT = 8081
all_cl = []
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind((IP_ADDR, PORT))


def Post():
    while True:
        msg = input("Server> ")
        for addr in all_cl:
            server.sendto(msg.encode(), addr)


def Get():
    while True:
        c_msg, client = server.recvfrom(1000)
        all_cl.append(client)
        print("\n{} has joined the chat".format(client[0]))
        if c_msg != None or c_msg != "":
            print("\nClient> {}\nServer> ".format(c_msg.decode()))


def main():
    print("Server Running at {}...".format(IP_ADDR))
    try:
        t1 = Thread(target=Post)
        t2 = Thread(target=Get)
        t1.start()
        t2.start()
    except KeyboardInterrupt:
        print("Closing connection...")
        server.close()


if __name__ == "__main__":
    main()
