#!/usr/bin/env python3
# coding=utf-8
import socket


def main():
    client = socket.socket()
    client.connect(("172.16.104.14", 8080))
    msg = client.recv(1000)
    print(
        """
            Message From Server client2:
            --------------------
            {}
            """.format(
            msg
        )
    )


if __name__ == "__main__":
    main()
