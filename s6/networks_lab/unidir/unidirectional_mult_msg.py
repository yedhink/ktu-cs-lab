#!/usr/bin/env python3
# coding=utf-8
import socket


def main():
    client = socket.socket()
    client.connect(("172.16.104.14", 8080))

    while True:
        msg = client.recv(1000)
        if msg == b"Exit":
            print("Client is closing")
            break
        print(msg)

    client.close()


if __name__ == "__main__":
    main()
