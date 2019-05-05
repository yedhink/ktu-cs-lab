#!/usr/bin/env python3
# coding=utf-8
import socket
from time import sleep
from threading import Thread

all_cl = {}
IP_ADDR = "172.16.104.6"


def Post(owner, msg, client):
    for each in all_cl.keys():
        if each != owner:
            all_cl[each].send(msg.encode())


def Get(server, client, owner):
    while True:
        try:
            c_msg = client.recv(1000)
            c_msg = c_msg.decode()
            if c_msg == "Exit":
                client.close()
                return 0
            if c_msg != None or c_msg != "":
                print("\nClient> {}\nServer> ".format(c_msg))
                Post(owner, c_msg, client)
        except ex:
            print("nothing recevied")


def main():
    server = socket.socket()
    server.bind((IP_ADDR, 8081))
    server.listen(5)
    print("Server Running at {}...".format(IP_ADDR))
    while True:
        try:
            client, addr = server.accept()
            uniq_id = addr[1]
            all_cl[uniq_id] = client
            print("\n{} has joined the chat".format(addr))
            t1 = Thread(target=Get, args=(server, client, uniq_id))
            t1.start()
        except KeyboardInterrupt:
            print("Closing connection...")
            server.close()
            break
    file.close()


if __name__ == "__main__":
    main()
