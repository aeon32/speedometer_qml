# Generated from IEC61131.g4 by ANTLR 4.9
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .IEC61131Parser import IEC61131Parser
else:
    from IEC61131Parser import IEC61131Parser

# This class defines a complete listener for a parse tree produced by IEC61131Parser.
class IEC61131Listener(ParseTreeListener):

    # Enter a parse tree produced by IEC61131Parser#var_block_global.
    def enterVar_block_global(self, ctx:IEC61131Parser.Var_block_globalContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#var_block_global.
    def exitVar_block_global(self, ctx:IEC61131Parser.Var_block_globalContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#var_block.
    def enterVar_block(self, ctx:IEC61131Parser.Var_blockContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#var_block.
    def exitVar_block(self, ctx:IEC61131Parser.Var_blockContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#simpleType.
    def enterSimpleType(self, ctx:IEC61131Parser.SimpleTypeContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#simpleType.
    def exitSimpleType(self, ctx:IEC61131Parser.SimpleTypeContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#arrayType.
    def enterArrayType(self, ctx:IEC61131Parser.ArrayTypeContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#arrayType.
    def exitArrayType(self, ctx:IEC61131Parser.ArrayTypeContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#pointerType.
    def enterPointerType(self, ctx:IEC61131Parser.PointerTypeContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#pointerType.
    def exitPointerType(self, ctx:IEC61131Parser.PointerTypeContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#array_type.
    def enterArray_type(self, ctx:IEC61131Parser.Array_typeContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#array_type.
    def exitArray_type(self, ctx:IEC61131Parser.Array_typeContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#range_decl.
    def enterRange_decl(self, ctx:IEC61131Parser.Range_declContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#range_decl.
    def exitRange_decl(self, ctx:IEC61131Parser.Range_declContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#pointer_type.
    def enterPointer_type(self, ctx:IEC61131Parser.Pointer_typeContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#pointer_type.
    def exitPointer_type(self, ctx:IEC61131Parser.Pointer_typeContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#variable_declaration.
    def enterVariable_declaration(self, ctx:IEC61131Parser.Variable_declarationContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#variable_declaration.
    def exitVariable_declaration(self, ctx:IEC61131Parser.Variable_declarationContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#variable_initializer.
    def enterVariable_initializer(self, ctx:IEC61131Parser.Variable_initializerContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#variable_initializer.
    def exitVariable_initializer(self, ctx:IEC61131Parser.Variable_initializerContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#literal.
    def enterLiteral(self, ctx:IEC61131Parser.LiteralContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#literal.
    def exitLiteral(self, ctx:IEC61131Parser.LiteralContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#boolean_literal.
    def enterBoolean_literal(self, ctx:IEC61131Parser.Boolean_literalContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#boolean_literal.
    def exitBoolean_literal(self, ctx:IEC61131Parser.Boolean_literalContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#numeric_literal.
    def enterNumeric_literal(self, ctx:IEC61131Parser.Numeric_literalContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#numeric_literal.
    def exitNumeric_literal(self, ctx:IEC61131Parser.Numeric_literalContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#integer_literal.
    def enterInteger_literal(self, ctx:IEC61131Parser.Integer_literalContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#integer_literal.
    def exitInteger_literal(self, ctx:IEC61131Parser.Integer_literalContext):
        pass


    # Enter a parse tree produced by IEC61131Parser#string_literal.
    def enterString_literal(self, ctx:IEC61131Parser.String_literalContext):
        pass

    # Exit a parse tree produced by IEC61131Parser#string_literal.
    def exitString_literal(self, ctx:IEC61131Parser.String_literalContext):
        pass



del IEC61131Parser