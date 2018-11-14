
// Generated from IEC61131.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "IEC61131Visitor.h"


/**
 * This class provides an empty implementation of IEC61131Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  IEC61131BaseVisitor : public IEC61131Visitor {
public:

  virtual antlrcpp::Any visitVar_block_global(IEC61131Parser::Var_block_globalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_block(IEC61131Parser::Var_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleType(IEC61131Parser::SimpleTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayType(IEC61131Parser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPointerType(IEC61131Parser::PointerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_type(IEC61131Parser::Array_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange(IEC61131Parser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPointer_type(IEC61131Parser::Pointer_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_declaration(IEC61131Parser::Variable_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_initializer(IEC61131Parser::Variable_initializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(IEC61131Parser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_literal(IEC61131Parser::Boolean_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_literal(IEC61131Parser::Numeric_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_literal(IEC61131Parser::Integer_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString_literal(IEC61131Parser::String_literalContext *ctx) override {
    return visitChildren(ctx);
  }


};

