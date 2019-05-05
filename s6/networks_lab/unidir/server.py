import socket


def main():
    server = socket.socket()
    server.bind(("172.16.104.14", 8080))
    server.listen(5)
    while True:
        msg = input("Enter msg for client : ")
        client, addr = server.accept()
        client.send(msg.encode())
        c_msg = client.recv(1000)
        if c_msg != None or c_msg != "":
            print("Message from client : {}".format(c_msg))
    server.close()


if __name__ == "__main__":
    main()
