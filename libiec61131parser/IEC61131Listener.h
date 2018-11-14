
// Generated from IEC61131.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "IEC61131Parser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by IEC61131Parser.
 */
class  IEC61131Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterVar_block_global(IEC61131Parser::Var_block_globalContext *ctx) = 0;
  virtual void exitVar_block_global(IEC61131Parser::Var_block_globalContext *ctx) = 0;

  virtual void enterVar_block(IEC61131Parser::Var_blockContext *ctx) = 0;
  virtual void exitVar_block(IEC61131Parser::Var_blockContext *ctx) = 0;

  virtual void enterSimpleType(IEC61131Parser::SimpleTypeContext *ctx) = 0;
  virtual void exitSimpleType(IEC61131Parser::SimpleTypeContext *ctx) = 0;

  virtual void enterArrayType(IEC61131Parser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(IEC61131Parser::ArrayTypeContext *ctx) = 0;

  virtual void enterPointerType(IEC61131Parser::PointerTypeContext *ctx) = 0;
  virtual void exitPointerType(IEC61131Parser::PointerTypeContext *ctx) = 0;

  virtual void enterArray_type(IEC61131Parser::Array_typeContext *ctx) = 0;
  virtual void exitArray_type(IEC61131Parser::Array_typeContext *ctx) = 0;

  virtual void enterRange(IEC61131Parser::RangeContext *ctx) = 0;
  virtual void exitRange(IEC61131Parser::RangeContext *ctx) = 0;

  virtual void enterPointer_type(IEC61131Parser::Pointer_typeContext *ctx) = 0;
  virtual void exitPointer_type(IEC61131Parser::Pointer_typeContext *ctx) = 0;

  virtual void enterVariable_declaration(IEC61131Parser::Variable_declarationContext *ctx) = 0;
  virtual void exitVariable_declaration(IEC61131Parser::Variable_declarationContext *ctx) = 0;

  virtual void enterVariable_initializer(IEC61131Parser::Variable_initializerContext *ctx) = 0;
  virtual void exitVariable_initializer(IEC61131Parser::Variable_initializerContext *ctx) = 0;

  virtual void enterLiteral(IEC61131Parser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(IEC61131Parser::LiteralContext *ctx) = 0;

  virtual void enterBoolean_literal(IEC61131Parser::Boolean_literalContext *ctx) = 0;
  virtual void exitBoolean_literal(IEC61131Parser::Boolean_literalContext *ctx) = 0;

  virtual void enterNumeric_literal(IEC61131Parser::Numeric_literalContext *ctx) = 0;
  virtual void exitNumeric_literal(IEC61131Parser::Numeric_literalContext *ctx) = 0;

  virtual void enterInteger_literal(IEC61131Parser::Integer_literalContext *ctx) = 0;
  virtual void exitInteger_literal(IEC61131Parser::Integer_literalContext *ctx) = 0;

  virtual void enterString_literal(IEC61131Parser::String_literalContext *ctx) = 0;
  virtual void exitString_literal(IEC61131Parser::String_literalContext *ctx) = 0;


};

