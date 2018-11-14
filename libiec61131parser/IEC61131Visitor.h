
// Generated from IEC61131.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "IEC61131Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by IEC61131Parser.
 */
class  IEC61131Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by IEC61131Parser.
   */
    virtual antlrcpp::Any visitVar_block_global(IEC61131Parser::Var_block_globalContext *context) = 0;

    virtual antlrcpp::Any visitVar_block(IEC61131Parser::Var_blockContext *context) = 0;

    virtual antlrcpp::Any visitSimpleType(IEC61131Parser::SimpleTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(IEC61131Parser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitPointerType(IEC61131Parser::PointerTypeContext *context) = 0;

    virtual antlrcpp::Any visitArray_type(IEC61131Parser::Array_typeContext *context) = 0;

    virtual antlrcpp::Any visitRange(IEC61131Parser::RangeContext *context) = 0;

    virtual antlrcpp::Any visitPointer_type(IEC61131Parser::Pointer_typeContext *context) = 0;

    virtual antlrcpp::Any visitVariable_declaration(IEC61131Parser::Variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitVariable_initializer(IEC61131Parser::Variable_initializerContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(IEC61131Parser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_literal(IEC61131Parser::Boolean_literalContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_literal(IEC61131Parser::Numeric_literalContext *context) = 0;

    virtual antlrcpp::Any visitInteger_literal(IEC61131Parser::Integer_literalContext *context) = 0;

    virtual antlrcpp::Any visitString_literal(IEC61131Parser::String_literalContext *context) = 0;


};

