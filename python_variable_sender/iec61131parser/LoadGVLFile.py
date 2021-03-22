import xml.etree.ElementTree
import xml.dom.minidom

import antlr4.FileStream
import antlr4.InputStream
import antlr4.CommonTokenStream

import iec61131parser.IEC61131Lexer
import iec61131parser.IEC61131Parser

#Parse GVL file, reads VAR_GLOBAL section, returns list of tuples (varname, vartype)
def LoadGVLFile(fileName):
    gvlParsedFile = xml.etree.ElementTree.parse(fileName)
    root = gvlParsedFile.getroot()
    declarations = root.findtext("./Declarations")
    if declarations is None:
        raise xml.etree.ElementTree.ParseError("GVL file doesn't have declarations section")

    declarations = declarations.replace("\n", "\r\n")

    inputFileStream = antlr4.InputStream(declarations)
    lexer = iec61131parser.IEC61131Lexer.IEC61131Lexer(inputFileStream)
    tokens = antlr4.CommonTokenStream(lexer)
    tokens.fill()

    parser = iec61131parser.IEC61131Parser.IEC61131Parser(tokens)

    var_block = parser.var_block_global()

    global_vars = []

    if var_block is not None:
        for variable in var_block.variables:
            for name in variable.names:
                name = name.text
                type = variable.type_decl.name.text
                global_vars.append( (name,type) )

    return global_vars


