import os, sys


r, w = os.pipe()
child = os.fork()


if child == 0:
    os.close(r)
    w1 = os.fdopen(w, "w")
    msg = input("Child> ")
    w1.write(msg)
else:
    os.close(w)
    r1 = os.fdopen(r, "r")
    print("Msg from child : {}".format(r1.read()))
