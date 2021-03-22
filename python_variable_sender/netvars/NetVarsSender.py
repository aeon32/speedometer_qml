# -*- coding: latin-1 -*-


import struct
import re
import socket

class NetVarsSender:
    """Interface für Netzwerkvariablen von CoDeSys 2.x"""
     
    # konstanten
    TELEGRAM_IDENT_3S = 0x33532D00

    # the empty localIface-string represents INADDR_ANY
    def __init__(self, addr, port, localIface=''):
        self.netIface = localIface
        self.netAddr = addr
        self.netPort = port


        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

    def close(self):
        self.sock.close()

    def send(self, dataPacks):
        for data in dataPacks:
            #print("sending data")
            self.sock.sendto(data, (self.netAddr, self.netPort))

