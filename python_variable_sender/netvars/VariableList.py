import enum
import struct

def defaultValue(type):
    return 0

class VariableTypes(enum.Enum):
    BOOL = 1  # unsigned 8 bit
    BYTE = 2  # unsigned 8 bit
    WORD = 3  # unsigned 16 bit
    DWORD = 4  # unsigned 32 bit
    SINT = 5  # signed 8 bit
    USINT = 6  # unsigned 8 bit
    INT = 7  # signed 16 bit
    UINT = 8  # unsigned 16 bit
    DINT = 9  # signed 32 bit
    UDINT = 10  # unsigned 32 bit
    DT = 11  # timestamp unsigned 32 bit
    REAL = 12  # float 32 bit
    LREAL = 13  # double 64 bit
    STRING = 14  # (scheinbar) immer 81 byte lang, jedoch nur bis zur ersten 0 gueltig

class Variable:
    def __init__(self, name, type, value):
        if not isinstance(type, VariableTypes):
            raise TypeError("Variable %s is not of VariableTypes" % (str(type),))
        self.name = name
        self.type = type
        self.value = value
        
    def pack(self):
        myData=b''
        if self.type == VariableTypes.BOOL:  # unsigned 8 bit
            myData = struct.pack('<B', self.value)
        elif self.type == VariableTypes.BYTE:  # unsigned 8 bit
            myData = struct.pack('<B', self.value)
        elif self.type == VariableTypes.WORD:  # unsigned 16 bit
            myData = struct.pack('<H', self.value)
        elif self.type == VariableTypes.DWORD:  # unsigned 32 bit
            myData = struct.pack('<L', self.value)
        elif self.type == VariableTypes.SINT:  # signed 8 bit
            myData = struct.pack('<b', self.value)
        elif self.type == VariableTypes.USINT:  # unsigned 8 bit
            myData = struct.pack('<B', self.value)
        elif self.type == VariableTypes.INT:  # signed 16 bit
            myData = struct.pack('<h', self.value)
        elif self.type == VariableTypes.UINT:  # unsigned 16 bit
            myData = struct.pack('<H', self.value)
        elif self.type == VariableTypes.DINT:  # signed 32 bit
            myData = struct.pack('<l', self.value)
        elif self.type == VariableTypes.UDINT:  # unsigned 32 bit
            myData = struct.pack('<L', self.value)
        elif self.type == VariableTypes.DT:  # timestamp unsigned 32 bit
            myData = struct.pack('<L', self.value)
        elif self.type == VariableTypes.REAL:  # float 32 bit
            myData = struct.pack('<f', self.value)
        elif self.type == VariableTypes.LREAL:  # double 64 bit
            myData = struct.pack('<d', self.value)
        elif self.type == VariableTypes.STRING:  # (scheinbar) immer 81 byte lang, jedoch nur bis zur ersten 0 gueltig
            # For packing, the string is truncated or padded with null bytes as appropriate to make it fit.
            myData = struct.pack('<81s', self.value)
        return myData

def strToType(typeName):
    try:
        type =  VariableTypes[typeName]
        return type
    except KeyError:
        raise ValueError("%s is not supported codesys type name" % (typeName,) )
    #pass
def defaultValue(type):
    res = None
    if type == VariableTypes.BOOL:  # unsigned 8 bit
        res = False
    elif (type == VariableTypes.BYTE or
         type == VariableTypes.WORD or
         type == VariableTypes.DWORD or
         type == VariableTypes.SINT or
         type == VariableTypes.USINT or
         type == VariableTypes.INT or
         type == VariableTypes.UINT or
         type == VariableTypes.DINT or
         type == VariableTypes.UDINT or
         type == VariableTypes.DT):
        res = 0

    elif type == VariableTypes.REAL or type == VariableTypes.LREAL :  # float 32 bit
        res = 0.0
    elif type == VariableTypes.STRING:
        res = ''
    return res



class VariableList:
    def __init__(self, variableList):
        self.var_map = {}
        self.var_list = [ ]

        for var in variableList:
            name = var[0]
            type = var[1]
            if isinstance(type, str):
                type = strToType(type)

            value = var[2] if len(var) == 3 else defaultValue(type)
            self.var_list.append(Variable(name, type, value))

        index = 0
        for var in self.var_list:
            self.var_map[var.name] = index
            index += 1

    def __getitem__(self, item):
        index = self.var_map[item]
        return self.var_list[ index] .value

    def __setitem__(self, key, value):
        index = self.var_map[key]
        self.var_list [index].value = value

    def __len__(self):
        return len(self.var_list)

    def __contains__(self, key):
        return key in self.var_map



class VariableListPacker():

    TELEGRAM_IDENT_3S = 0x33532D00
    ODSTATEFREE = 0

    def __init__(self, cobId):
        self.nextCounter = 0
        self.cobId = cobId

    def pack(self, variables):
        packs = []

        dwIdentity = self.TELEGRAM_IDENT_3S
        dwID = self.ODSTATEFREE

        nSubIndex = 0
        nItems = 0
        nLen = 0
        byFlags = 0
        byChecksum = 0

        data = b''
        myData = b''

        for var in variables.var_list:
            myData = var.pack()

            if (len(data) + len(myData)) >= 300:
                nLen = 20 + len(data)
                headerData = struct.pack('<LLhhhhHBB', dwIdentity, dwID, self.cobId, nSubIndex, nItems, nLen,
                                         self.nextCounter, byFlags, byChecksum)
                data = headerData + data
                packs.append(data)
                data = b''
                nItems = 0
                nSubIndex += 1

            data = data + myData
            nItems += 1

        if len(data):
            nLen = 20 + len(data)
            headerData = struct.pack('<LLhhhhHBB', dwIdentity, dwID, self.cobId, nSubIndex, nItems, nLen, self.nextCounter,
                                     byFlags, byChecksum)
            data = headerData + data
            packs.append(data)

        self.nextCounter += 1

        if self.nextCounter > 65535:
            self.nextCounter = 0

        return packs






