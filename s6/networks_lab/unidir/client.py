#!/usr/bin/env python3
# coding=utf-8
import socket


def main():
    while True:
        client = socket.socket()
        client.connect(("172.16.104.14", 8080))
        msg = client.recv(1000)

        if msg == b"Exit":
            print("Client is closing")
            client.close()
            break
        print("Message from Server : {}".format(msg))
        msg = input("Enter Message to Server : ")
        client.send(msg.encode())


if __name__ == "__main__":
    main()
