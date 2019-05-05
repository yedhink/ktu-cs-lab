#!/usr/bin/env python3
# coding=utf-8
import socket
from threading import Thread

all_cl = []


def Post(server, client):
    while True:
        msg = input("Server> ")
        for each in all_cl:
            each.send(msg.encode())


def Get(server, client):
    while True:
        c_msg = client.recv(1000)
        if c_msg != None or c_msg != "":
            print("\nClient> {}\nServer> ".format(c_msg.decode()))


def main():
    server = socket.socket()
    server.bind(("172.16.104.14", 8080))
    server.listen(5)
    print("Server Running...")
    while True:
        try:
            client, addr = server.accept()
            print("Our client = {}".format(client))
            all_cl.append(client)
            if addr != "" or addr != None:
                print("\n{} has joined the chat".format(addr))
                t1 = Thread(target=Post, args=(server, client))
                t2 = Thread(target=Get, args=(server, client))
                t1.start()
                t2.start()
        except KeyboardInterrupt:
            print("Closing connection...")
            break
    server.close()


if __name__ == "__main__":
    main()
