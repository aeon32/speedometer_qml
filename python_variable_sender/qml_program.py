# -*- coding: utf-8 -*-


import binascii
import struct
import socket
import datetime
import sys
import getopt
import time

from netvars.NetVarsSender import NetVarsSender
from netvars.VariableList import VariableList, VariableTypes, VariableListPacker


def createVarList():
    #varlist should be the same as one in gvl file
    vars = [ ('postNumber', VariableTypes.INT, 0),
             ('postMode', VariableTypes.INT, 1),
             ('postCounterFund', VariableTypes.INT, 2),
             ('cardType', VariableTypes.INT, 3),
             ('buttonActive', VariableTypes.INT, 2),
             ('amountReceived', VariableTypes.INT, 100),
             ('costWash', VariableTypes.INT, 10),
             ('costChange', VariableTypes.INT, 20),
             ('costActiveClean', VariableTypes.INT, 30),
             ('costFoam', VariableTypes.INT, 40),
             ('costShampoo', VariableTypes.INT, 50),
             ('costColdWater', VariableTypes.INT, 60),
             ('costHotWater', VariableTypes.INT, 70),
             ('costWax', VariableTypes.INT, 80),
             ('costOsmose', VariableTypes.INT, 90),
             ('costPause', VariableTypes.INT, 100),
             ('lockTop', VariableTypes.INT, 1),
             ('lockMid', VariableTypes.INT, 2),
             ('qrString0', VariableTypes.STRING, "t=20210322T2008&s=123.00&fn=9252440300238147&i=3&fp=3773188529&n=5".encode('utf-8')),
             ('qrString1', VariableTypes.STRING, "".encode('utf-8'))
    ]



    varList = VariableList(vars)
    return varList

def loadVarsFromGVLFile(fileName):
    from  iec61131parser.LoadGVLFile import LoadGVLFile
    global_vars = LoadGVLFile(fileName)

    varList = VariableList(global_vars)

    return varList



def main(argv):

    # the empty localIf-string represents INADDR_ANY
    localIf = 'lo'
    addr = '255.255.255.255'
    port = 1202
    cobId = 1

    #create object for codesys telegrams sending (actually, udp-socket)
    netVarsSender = NetVarsSender(addr, port, localIf)

    #create and fill VariableList instance - map-like object which stores net variables names, types and values
    varList = createVarList()

    #also it is possible to load varlist from gvl file:
    #varList = loadVarsFromGVLFile('test_data/NVL2UI.gvl')

    #create object for VariableList marshalling
    netVarsPacker = VariableListPacker(cobId)

    while True:
        #change net variables values
        varList['postMode'] = 900


        #marshal VariableList
        dataPacks = netVarsPacker.pack(varList)
        #send marshalled data
        netVarsSender.send(dataPacks)
        time.sleep(1)


if __name__ == '__main__':
    main(sys.argv[1:])

