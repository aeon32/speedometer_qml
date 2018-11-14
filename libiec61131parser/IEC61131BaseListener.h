
// Generated from IEC61131.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "IEC61131Listener.h"


/**
 * This class provides an empty implementation of IEC61131Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  IEC61131BaseListener : public IEC61131Listener {
public:

  virtual void enterVar_block_global(IEC61131Parser::Var_block_globalContext * /*ctx*/) override { }
  virtual void exitVar_block_global(IEC61131Parser::Var_block_globalContext * /*ctx*/) override { }

  virtual void enterVar_block(IEC61131Parser::Var_blockContext * /*ctx*/) override { }
  virtual void exitVar_block(IEC61131Parser::Var_blockContext * /*ctx*/) override { }

  virtual void enterSimpleType(IEC61131Parser::SimpleTypeContext * /*ctx*/) override { }
  virtual void exitSimpleType(IEC61131Parser::SimpleTypeContext * /*ctx*/) override { }

  virtual void enterArrayType(IEC61131Parser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(IEC61131Parser::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterPointerType(IEC61131Parser::PointerTypeContext * /*ctx*/) override { }
  virtual void exitPointerType(IEC61131Parser::PointerTypeContext * /*ctx*/) override { }

  virtual void enterArray_type(IEC61131Parser::Array_typeContext * /*ctx*/) override { }
  virtual void exitArray_type(IEC61131Parser::Array_typeContext * /*ctx*/) override { }

  virtual void enterRange(IEC61131Parser::RangeContext * /*ctx*/) override { }
  virtual void exitRange(IEC61131Parser::RangeContext * /*ctx*/) override { }

  virtual void enterPointer_type(IEC61131Parser::Pointer_typeContext * /*ctx*/) override { }
  virtual void exitPointer_type(IEC61131Parser::Pointer_typeContext * /*ctx*/) override { }

  virtual void enterVariable_declaration(IEC61131Parser::Variable_declarationContext * /*ctx*/) override { }
  virtual void exitVariable_declaration(IEC61131Parser::Variable_declarationContext * /*ctx*/) override { }

  virtual void enterVariable_initializer(IEC61131Parser::Variable_initializerContext * /*ctx*/) override { }
  virtual void exitVariable_initializer(IEC61131Parser::Variable_initializerContext * /*ctx*/) override { }

  virtual void enterLiteral(IEC61131Parser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(IEC61131Parser::LiteralContext * /*ctx*/) override { }

  virtual void enterBoolean_literal(IEC61131Parser::Boolean_literalContext * /*ctx*/) override { }
  virtual void exitBoolean_literal(IEC61131Parser::Boolean_literalContext * /*ctx*/) override { }

  virtual void enterNumeric_literal(IEC61131Parser::Numeric_literalContext * /*ctx*/) override { }
  virtual void exitNumeric_literal(IEC61131Parser::Numeric_literalContext * /*ctx*/) override { }

  virtual void enterInteger_literal(IEC61131Parser::Integer_literalContext * /*ctx*/) override { }
  virtual void exitInteger_literal(IEC61131Parser::Integer_literalContext * /*ctx*/) override { }

  virtual void enterString_literal(IEC61131Parser::String_literalContext * /*ctx*/) override { }
  virtual void exitString_literal(IEC61131Parser::String_literalContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

