
// Generated from IEC61131.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  IEC61131Parser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, Binary_literal = 22, Octal_literal = 23, Decimal_literal = 24, 
    Pure_decimal_digits = 25, Hexadecimal_literal = 26, Floating_point_literal = 27, 
    Static_string_literal = 28, ID = 29, WS = 30, Block_comment = 31, Attribute = 32, 
    Line_comment = 33
  };

  enum {
    RuleVar_block_global = 0, RuleVar_block = 1, RuleType_rule = 2, RuleArray_type = 3, 
    RuleRange = 4, RulePointer_type = 5, RuleVariable_declaration = 6, RuleVariable_initializer = 7, 
    RuleLiteral = 8, RuleBoolean_literal = 9, RuleNumeric_literal = 10, 
    RuleInteger_literal = 11, RuleString_literal = 12
  };

  IEC61131Parser(antlr4::TokenStream *input);
  ~IEC61131Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Var_block_globalContext;
  class Var_blockContext;
  class Type_ruleContext;
  class Array_typeContext;
  class RangeContext;
  class Pointer_typeContext;
  class Variable_declarationContext;
  class Variable_initializerContext;
  class LiteralContext;
  class Boolean_literalContext;
  class Numeric_literalContext;
  class Integer_literalContext;
  class String_literalContext; 

  class  Var_block_globalContext : public antlr4::ParserRuleContext {
  public:
    IEC61131Parser::Variable_declarationContext *variable_declarationContext = nullptr;;
    std::vector<Variable_declarationContext *> variables;;
    Var_block_globalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_declarationContext *> variable_declaration();
    Variable_declarationContext* variable_declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_block_globalContext* var_block_global();

  class  Var_blockContext : public antlr4::ParserRuleContext {
  public:
    bool input;
    bool output;
    bool temp;
    IEC61131Parser::Variable_declarationContext *variable_declarationContext = nullptr;;
    std::vector<Variable_declarationContext *> variables;;
    Var_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_declarationContext *> variable_declaration();
    Variable_declarationContext* variable_declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_blockContext* var_block();

  class  Type_ruleContext : public antlr4::ParserRuleContext {
  public:
    Type_ruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Type_ruleContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Type_ruleContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimpleTypeContext : public Type_ruleContext {
  public:
    SimpleTypeContext(Type_ruleContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::tree::TerminalNode *ID();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ArrayTypeContext : public Type_ruleContext {
  public:
    ArrayTypeContext(Type_ruleContext *ctx);

    IEC61131Parser::Array_typeContext *array = nullptr;
    Array_typeContext *array_type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  PointerTypeContext : public Type_ruleContext {
  public:
    PointerTypeContext(Type_ruleContext *ctx);

    IEC61131Parser::Pointer_typeContext *pointer = nullptr;
    Pointer_typeContext *pointer_type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Type_ruleContext* type_rule();

  class  Array_typeContext : public antlr4::ParserRuleContext {
  public:
    IEC61131Parser::RangeContext *rangeContext = nullptr;;
    std::vector<RangeContext *> ranges;;
    IEC61131Parser::Type_ruleContext *type = nullptr;;
    Array_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RangeContext *> range();
    RangeContext* range(size_t i);
    Type_ruleContext *type_rule();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_typeContext* array_type();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    IEC61131Parser::Integer_literalContext *lbound = nullptr;;
    IEC61131Parser::Integer_literalContext *ubound = nullptr;;
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Integer_literalContext *> integer_literal();
    Integer_literalContext* integer_literal(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RangeContext* range();

  class  Pointer_typeContext : public antlr4::ParserRuleContext {
  public:
    IEC61131Parser::Type_ruleContext *type = nullptr;;
    Pointer_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_ruleContext *type_rule();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Pointer_typeContext* pointer_type();

  class  Variable_declarationContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *idToken = nullptr;;
    std::vector<antlr4::Token *> names;;
    IEC61131Parser::Type_ruleContext *type = nullptr;;
    IEC61131Parser::Variable_initializerContext *initializer = nullptr;;
    Variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    Type_ruleContext *type_rule();
    Variable_initializerContext *variable_initializer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variable_declarationContext* variable_declaration();

  class  Variable_initializerContext : public antlr4::ParserRuleContext {
  public:
    Variable_initializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variable_initializerContext* variable_initializer();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Numeric_literalContext *numeric_literal();
    String_literalContext *string_literal();
    Boolean_literalContext *boolean_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralContext* literal();

  class  Boolean_literalContext : public antlr4::ParserRuleContext {
  public:
    Boolean_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Boolean_literalContext* boolean_literal();

  class  Numeric_literalContext : public antlr4::ParserRuleContext {
  public:
    Numeric_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_literalContext *integer_literal();
    antlr4::tree::TerminalNode *Floating_point_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Numeric_literalContext* numeric_literal();

  class  Integer_literalContext : public antlr4::ParserRuleContext {
  public:
    Integer_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Binary_literal();
    antlr4::tree::TerminalNode *Octal_literal();
    antlr4::tree::TerminalNode *Decimal_literal();
    antlr4::tree::TerminalNode *Pure_decimal_digits();
    antlr4::tree::TerminalNode *Hexadecimal_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Integer_literalContext* integer_literal();

  class  String_literalContext : public antlr4::ParserRuleContext {
  public:
    String_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Static_string_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  String_literalContext* string_literal();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

