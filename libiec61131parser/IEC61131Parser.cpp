
// Generated from IEC61131.g4 by ANTLR 4.7


#include "IEC61131Listener.h"

#include "IEC61131Parser.h"


using namespace antlrcpp;
using namespace antlr4;

IEC61131Parser::IEC61131Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

IEC61131Parser::~IEC61131Parser() {
  delete _interpreter;
}

std::string IEC61131Parser::getGrammarFileName() const {
  return "IEC61131.g4";
}

const std::vector<std::string>& IEC61131Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& IEC61131Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Var_block_globalContext ------------------------------------------------------------------

IEC61131Parser::Var_block_globalContext::Var_block_globalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IEC61131Parser::Variable_declarationContext *> IEC61131Parser::Var_block_globalContext::variable_declaration() {
  return getRuleContexts<IEC61131Parser::Variable_declarationContext>();
}

IEC61131Parser::Variable_declarationContext* IEC61131Parser::Var_block_globalContext::variable_declaration(size_t i) {
  return getRuleContext<IEC61131Parser::Variable_declarationContext>(i);
}


size_t IEC61131Parser::Var_block_globalContext::getRuleIndex() const {
  return IEC61131Parser::RuleVar_block_global;
}

void IEC61131Parser::Var_block_globalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_block_global(this);
}

void IEC61131Parser::Var_block_globalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_block_global(this);
}

IEC61131Parser::Var_block_globalContext* IEC61131Parser::var_block_global() {
  Var_block_globalContext *_localctx = _tracker.createInstance<Var_block_globalContext>(_ctx, getState());
  enterRule(_localctx, 0, IEC61131Parser::RuleVar_block_global);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    match(IEC61131Parser::T__0);

    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IEC61131Parser::ID) {
      setState(27);
      dynamic_cast<Var_block_globalContext *>(_localctx)->variable_declarationContext = variable_declaration();
      dynamic_cast<Var_block_globalContext *>(_localctx)->variables.push_back(dynamic_cast<Var_block_globalContext *>(_localctx)->variable_declarationContext);
      setState(32);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(33);
    match(IEC61131Parser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_blockContext ------------------------------------------------------------------

IEC61131Parser::Var_blockContext::Var_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IEC61131Parser::Variable_declarationContext *> IEC61131Parser::Var_blockContext::variable_declaration() {
  return getRuleContexts<IEC61131Parser::Variable_declarationContext>();
}

IEC61131Parser::Variable_declarationContext* IEC61131Parser::Var_blockContext::variable_declaration(size_t i) {
  return getRuleContext<IEC61131Parser::Variable_declarationContext>(i);
}


size_t IEC61131Parser::Var_blockContext::getRuleIndex() const {
  return IEC61131Parser::RuleVar_block;
}

void IEC61131Parser::Var_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_block(this);
}

void IEC61131Parser::Var_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_block(this);
}

IEC61131Parser::Var_blockContext* IEC61131Parser::var_block() {
  Var_blockContext *_localctx = _tracker.createInstance<Var_blockContext>(_ctx, getState());
  enterRule(_localctx, 2, IEC61131Parser::RuleVar_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IEC61131Parser::T__2: {
        setState(35);
        match(IEC61131Parser::T__2);
        break;
      }

      case IEC61131Parser::T__3: {
         dynamic_cast<Var_blockContext *>(_localctx)->input = true; 
        setState(37);
        match(IEC61131Parser::T__3);
        break;
      }

      case IEC61131Parser::T__4: {
         dynamic_cast<Var_blockContext *>(_localctx)->output = true; 
        setState(39);
        match(IEC61131Parser::T__4);
        break;
      }

      case IEC61131Parser::T__5: {
         dynamic_cast<Var_blockContext *>(_localctx)->input = _localctx->output=true; 
        setState(41);
        match(IEC61131Parser::T__5);
        break;
      }

      case IEC61131Parser::T__6: {
         dynamic_cast<Var_blockContext *>(_localctx)->temp = true; 
        setState(43);
        match(IEC61131Parser::T__6);
        break;
      }

    default:
      throw NoViableAltException(this);
    }

    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IEC61131Parser::ID) {
      setState(46);
      dynamic_cast<Var_blockContext *>(_localctx)->variable_declarationContext = variable_declaration();
      dynamic_cast<Var_blockContext *>(_localctx)->variables.push_back(dynamic_cast<Var_blockContext *>(_localctx)->variable_declarationContext);
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    match(IEC61131Parser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_ruleContext ------------------------------------------------------------------

IEC61131Parser::Type_ruleContext::Type_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IEC61131Parser::Type_ruleContext::getRuleIndex() const {
  return IEC61131Parser::RuleType_rule;
}

void IEC61131Parser::Type_ruleContext::copyFrom(Type_ruleContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleTypeContext ------------------------------------------------------------------

tree::TerminalNode* IEC61131Parser::SimpleTypeContext::ID() {
  return getToken(IEC61131Parser::ID, 0);
}

IEC61131Parser::SimpleTypeContext::SimpleTypeContext(Type_ruleContext *ctx) { copyFrom(ctx); }

void IEC61131Parser::SimpleTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleType(this);
}
void IEC61131Parser::SimpleTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleType(this);
}
//----------------- ArrayTypeContext ------------------------------------------------------------------

IEC61131Parser::Array_typeContext* IEC61131Parser::ArrayTypeContext::array_type() {
  return getRuleContext<IEC61131Parser::Array_typeContext>(0);
}

IEC61131Parser::ArrayTypeContext::ArrayTypeContext(Type_ruleContext *ctx) { copyFrom(ctx); }

void IEC61131Parser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}
void IEC61131Parser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}
//----------------- PointerTypeContext ------------------------------------------------------------------

IEC61131Parser::Pointer_typeContext* IEC61131Parser::PointerTypeContext::pointer_type() {
  return getRuleContext<IEC61131Parser::Pointer_typeContext>(0);
}

IEC61131Parser::PointerTypeContext::PointerTypeContext(Type_ruleContext *ctx) { copyFrom(ctx); }

void IEC61131Parser::PointerTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointerType(this);
}
void IEC61131Parser::PointerTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointerType(this);
}
IEC61131Parser::Type_ruleContext* IEC61131Parser::type_rule() {
  Type_ruleContext *_localctx = _tracker.createInstance<Type_ruleContext>(_ctx, getState());
  enterRule(_localctx, 4, IEC61131Parser::RuleType_rule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(57);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IEC61131Parser::ID: {
        _localctx = dynamic_cast<Type_ruleContext *>(_tracker.createInstance<IEC61131Parser::SimpleTypeContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(54);
        dynamic_cast<SimpleTypeContext *>(_localctx)->name = match(IEC61131Parser::ID);
        break;
      }

      case IEC61131Parser::T__7: {
        _localctx = dynamic_cast<Type_ruleContext *>(_tracker.createInstance<IEC61131Parser::ArrayTypeContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(55);
        dynamic_cast<ArrayTypeContext *>(_localctx)->array = array_type();
        break;
      }

      case IEC61131Parser::T__13: {
        _localctx = dynamic_cast<Type_ruleContext *>(_tracker.createInstance<IEC61131Parser::PointerTypeContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(56);
        dynamic_cast<PointerTypeContext *>(_localctx)->pointer = pointer_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_typeContext ------------------------------------------------------------------

IEC61131Parser::Array_typeContext::Array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IEC61131Parser::RangeContext *> IEC61131Parser::Array_typeContext::range() {
  return getRuleContexts<IEC61131Parser::RangeContext>();
}

IEC61131Parser::RangeContext* IEC61131Parser::Array_typeContext::range(size_t i) {
  return getRuleContext<IEC61131Parser::RangeContext>(i);
}

IEC61131Parser::Type_ruleContext* IEC61131Parser::Array_typeContext::type_rule() {
  return getRuleContext<IEC61131Parser::Type_ruleContext>(0);
}


size_t IEC61131Parser::Array_typeContext::getRuleIndex() const {
  return IEC61131Parser::RuleArray_type;
}

void IEC61131Parser::Array_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_type(this);
}

void IEC61131Parser::Array_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_type(this);
}

IEC61131Parser::Array_typeContext* IEC61131Parser::array_type() {
  Array_typeContext *_localctx = _tracker.createInstance<Array_typeContext>(_ctx, getState());
  enterRule(_localctx, 6, IEC61131Parser::RuleArray_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(IEC61131Parser::T__7);
    setState(60);
    match(IEC61131Parser::T__8);
    setState(61);
    dynamic_cast<Array_typeContext *>(_localctx)->rangeContext = range();
    dynamic_cast<Array_typeContext *>(_localctx)->ranges.push_back(dynamic_cast<Array_typeContext *>(_localctx)->rangeContext);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IEC61131Parser::T__9) {
      setState(62);
      match(IEC61131Parser::T__9);
      setState(63);
      dynamic_cast<Array_typeContext *>(_localctx)->rangeContext = range();
      dynamic_cast<Array_typeContext *>(_localctx)->ranges.push_back(dynamic_cast<Array_typeContext *>(_localctx)->rangeContext);
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(IEC61131Parser::T__10);
    setState(70);
    match(IEC61131Parser::T__11);
    setState(71);
    dynamic_cast<Array_typeContext *>(_localctx)->type = type_rule();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

IEC61131Parser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IEC61131Parser::Integer_literalContext *> IEC61131Parser::RangeContext::integer_literal() {
  return getRuleContexts<IEC61131Parser::Integer_literalContext>();
}

IEC61131Parser::Integer_literalContext* IEC61131Parser::RangeContext::integer_literal(size_t i) {
  return getRuleContext<IEC61131Parser::Integer_literalContext>(i);
}


size_t IEC61131Parser::RangeContext::getRuleIndex() const {
  return IEC61131Parser::RuleRange;
}

void IEC61131Parser::RangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRange(this);
}

void IEC61131Parser::RangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRange(this);
}

IEC61131Parser::RangeContext* IEC61131Parser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 8, IEC61131Parser::RuleRange);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    dynamic_cast<RangeContext *>(_localctx)->lbound = integer_literal();
    setState(74);
    match(IEC61131Parser::T__12);
    setState(75);
    dynamic_cast<RangeContext *>(_localctx)->ubound = integer_literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pointer_typeContext ------------------------------------------------------------------

IEC61131Parser::Pointer_typeContext::Pointer_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IEC61131Parser::Type_ruleContext* IEC61131Parser::Pointer_typeContext::type_rule() {
  return getRuleContext<IEC61131Parser::Type_ruleContext>(0);
}


size_t IEC61131Parser::Pointer_typeContext::getRuleIndex() const {
  return IEC61131Parser::RulePointer_type;
}

void IEC61131Parser::Pointer_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointer_type(this);
}

void IEC61131Parser::Pointer_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointer_type(this);
}

IEC61131Parser::Pointer_typeContext* IEC61131Parser::pointer_type() {
  Pointer_typeContext *_localctx = _tracker.createInstance<Pointer_typeContext>(_ctx, getState());
  enterRule(_localctx, 10, IEC61131Parser::RulePointer_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(IEC61131Parser::T__13);
    setState(78);
    match(IEC61131Parser::T__14);
    setState(79);
    dynamic_cast<Pointer_typeContext *>(_localctx)->type = type_rule();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declarationContext ------------------------------------------------------------------

IEC61131Parser::Variable_declarationContext::Variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> IEC61131Parser::Variable_declarationContext::ID() {
  return getTokens(IEC61131Parser::ID);
}

tree::TerminalNode* IEC61131Parser::Variable_declarationContext::ID(size_t i) {
  return getToken(IEC61131Parser::ID, i);
}

IEC61131Parser::Type_ruleContext* IEC61131Parser::Variable_declarationContext::type_rule() {
  return getRuleContext<IEC61131Parser::Type_ruleContext>(0);
}

IEC61131Parser::Variable_initializerContext* IEC61131Parser::Variable_declarationContext::variable_initializer() {
  return getRuleContext<IEC61131Parser::Variable_initializerContext>(0);
}


size_t IEC61131Parser::Variable_declarationContext::getRuleIndex() const {
  return IEC61131Parser::RuleVariable_declaration;
}

void IEC61131Parser::Variable_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_declaration(this);
}

void IEC61131Parser::Variable_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_declaration(this);
}

IEC61131Parser::Variable_declarationContext* IEC61131Parser::variable_declaration() {
  Variable_declarationContext *_localctx = _tracker.createInstance<Variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 12, IEC61131Parser::RuleVariable_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    dynamic_cast<Variable_declarationContext *>(_localctx)->idToken = match(IEC61131Parser::ID);
    dynamic_cast<Variable_declarationContext *>(_localctx)->names.push_back(dynamic_cast<Variable_declarationContext *>(_localctx)->idToken);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == IEC61131Parser::T__9) {
      setState(82);
      match(IEC61131Parser::T__9);
      setState(83);
      dynamic_cast<Variable_declarationContext *>(_localctx)->idToken = match(IEC61131Parser::ID);
      dynamic_cast<Variable_declarationContext *>(_localctx)->names.push_back(dynamic_cast<Variable_declarationContext *>(_localctx)->idToken);
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    match(IEC61131Parser::T__15);
    setState(90);
    dynamic_cast<Variable_declarationContext *>(_localctx)->type = type_rule();
    setState(93);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == IEC61131Parser::T__16) {
      setState(91);
      match(IEC61131Parser::T__16);
      setState(92);
      dynamic_cast<Variable_declarationContext *>(_localctx)->initializer = variable_initializer();
    }
    setState(95);
    match(IEC61131Parser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_initializerContext ------------------------------------------------------------------

IEC61131Parser::Variable_initializerContext::Variable_initializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IEC61131Parser::LiteralContext* IEC61131Parser::Variable_initializerContext::literal() {
  return getRuleContext<IEC61131Parser::LiteralContext>(0);
}


size_t IEC61131Parser::Variable_initializerContext::getRuleIndex() const {
  return IEC61131Parser::RuleVariable_initializer;
}

void IEC61131Parser::Variable_initializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_initializer(this);
}

void IEC61131Parser::Variable_initializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_initializer(this);
}

IEC61131Parser::Variable_initializerContext* IEC61131Parser::variable_initializer() {
  Variable_initializerContext *_localctx = _tracker.createInstance<Variable_initializerContext>(_ctx, getState());
  enterRule(_localctx, 14, IEC61131Parser::RuleVariable_initializer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

IEC61131Parser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IEC61131Parser::Numeric_literalContext* IEC61131Parser::LiteralContext::numeric_literal() {
  return getRuleContext<IEC61131Parser::Numeric_literalContext>(0);
}

IEC61131Parser::String_literalContext* IEC61131Parser::LiteralContext::string_literal() {
  return getRuleContext<IEC61131Parser::String_literalContext>(0);
}

IEC61131Parser::Boolean_literalContext* IEC61131Parser::LiteralContext::boolean_literal() {
  return getRuleContext<IEC61131Parser::Boolean_literalContext>(0);
}


size_t IEC61131Parser::LiteralContext::getRuleIndex() const {
  return IEC61131Parser::RuleLiteral;
}

void IEC61131Parser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void IEC61131Parser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

IEC61131Parser::LiteralContext* IEC61131Parser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 16, IEC61131Parser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IEC61131Parser::T__20:
      case IEC61131Parser::Binary_literal:
      case IEC61131Parser::Octal_literal:
      case IEC61131Parser::Decimal_literal:
      case IEC61131Parser::Pure_decimal_digits:
      case IEC61131Parser::Hexadecimal_literal:
      case IEC61131Parser::Floating_point_literal: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        numeric_literal();
        break;
      }

      case IEC61131Parser::Static_string_literal: {
        enterOuterAlt(_localctx, 2);
        setState(100);
        string_literal();
        break;
      }

      case IEC61131Parser::T__18:
      case IEC61131Parser::T__19: {
        enterOuterAlt(_localctx, 3);
        setState(101);
        boolean_literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Boolean_literalContext ------------------------------------------------------------------

IEC61131Parser::Boolean_literalContext::Boolean_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IEC61131Parser::Boolean_literalContext::getRuleIndex() const {
  return IEC61131Parser::RuleBoolean_literal;
}

void IEC61131Parser::Boolean_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean_literal(this);
}

void IEC61131Parser::Boolean_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean_literal(this);
}

IEC61131Parser::Boolean_literalContext* IEC61131Parser::boolean_literal() {
  Boolean_literalContext *_localctx = _tracker.createInstance<Boolean_literalContext>(_ctx, getState());
  enterRule(_localctx, 18, IEC61131Parser::RuleBoolean_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    _la = _input->LA(1);
    if (!(_la == IEC61131Parser::T__18

    || _la == IEC61131Parser::T__19)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Numeric_literalContext ------------------------------------------------------------------

IEC61131Parser::Numeric_literalContext::Numeric_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IEC61131Parser::Integer_literalContext* IEC61131Parser::Numeric_literalContext::integer_literal() {
  return getRuleContext<IEC61131Parser::Integer_literalContext>(0);
}

tree::TerminalNode* IEC61131Parser::Numeric_literalContext::Floating_point_literal() {
  return getToken(IEC61131Parser::Floating_point_literal, 0);
}


size_t IEC61131Parser::Numeric_literalContext::getRuleIndex() const {
  return IEC61131Parser::RuleNumeric_literal;
}

void IEC61131Parser::Numeric_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric_literal(this);
}

void IEC61131Parser::Numeric_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric_literal(this);
}

IEC61131Parser::Numeric_literalContext* IEC61131Parser::numeric_literal() {
  Numeric_literalContext *_localctx = _tracker.createInstance<Numeric_literalContext>(_ctx, getState());
  enterRule(_localctx, 20, IEC61131Parser::RuleNumeric_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(114);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(107);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == IEC61131Parser::T__20) {
        setState(106);
        match(IEC61131Parser::T__20);
      }
      setState(109);
      integer_literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == IEC61131Parser::T__20) {
        setState(110);
        match(IEC61131Parser::T__20);
      }
      setState(113);
      match(IEC61131Parser::Floating_point_literal);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Integer_literalContext ------------------------------------------------------------------

IEC61131Parser::Integer_literalContext::Integer_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IEC61131Parser::Integer_literalContext::Binary_literal() {
  return getToken(IEC61131Parser::Binary_literal, 0);
}

tree::TerminalNode* IEC61131Parser::Integer_literalContext::Octal_literal() {
  return getToken(IEC61131Parser::Octal_literal, 0);
}

tree::TerminalNode* IEC61131Parser::Integer_literalContext::Decimal_literal() {
  return getToken(IEC61131Parser::Decimal_literal, 0);
}

tree::TerminalNode* IEC61131Parser::Integer_literalContext::Pure_decimal_digits() {
  return getToken(IEC61131Parser::Pure_decimal_digits, 0);
}

tree::TerminalNode* IEC61131Parser::Integer_literalContext::Hexadecimal_literal() {
  return getToken(IEC61131Parser::Hexadecimal_literal, 0);
}


size_t IEC61131Parser::Integer_literalContext::getRuleIndex() const {
  return IEC61131Parser::RuleInteger_literal;
}

void IEC61131Parser::Integer_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_literal(this);
}

void IEC61131Parser::Integer_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_literal(this);
}

IEC61131Parser::Integer_literalContext* IEC61131Parser::integer_literal() {
  Integer_literalContext *_localctx = _tracker.createInstance<Integer_literalContext>(_ctx, getState());
  enterRule(_localctx, 22, IEC61131Parser::RuleInteger_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IEC61131Parser::Binary_literal)
      | (1ULL << IEC61131Parser::Octal_literal)
      | (1ULL << IEC61131Parser::Decimal_literal)
      | (1ULL << IEC61131Parser::Pure_decimal_digits)
      | (1ULL << IEC61131Parser::Hexadecimal_literal))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_literalContext ------------------------------------------------------------------

IEC61131Parser::String_literalContext::String_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IEC61131Parser::String_literalContext::Static_string_literal() {
  return getToken(IEC61131Parser::Static_string_literal, 0);
}


size_t IEC61131Parser::String_literalContext::getRuleIndex() const {
  return IEC61131Parser::RuleString_literal;
}

void IEC61131Parser::String_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_literal(this);
}

void IEC61131Parser::String_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IEC61131Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_literal(this);
}

IEC61131Parser::String_literalContext* IEC61131Parser::string_literal() {
  String_literalContext *_localctx = _tracker.createInstance<String_literalContext>(_ctx, getState());
  enterRule(_localctx, 24, IEC61131Parser::RuleString_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(IEC61131Parser::Static_string_literal);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> IEC61131Parser::_decisionToDFA;
atn::PredictionContextCache IEC61131Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN IEC61131Parser::_atn;
std::vector<uint16_t> IEC61131Parser::_serializedATN;

std::vector<std::string> IEC61131Parser::_ruleNames = {
  "var_block_global", "var_block", "type_rule", "array_type", "range", "pointer_type", 
  "variable_declaration", "variable_initializer", "literal", "boolean_literal", 
  "numeric_literal", "integer_literal", "string_literal"
};

std::vector<std::string> IEC61131Parser::_literalNames = {
  "", "'VAR_GLOBAL'", "'END_VAR'", "'VAR'", "'VAR_INPUT'", "'VAR_OUTPUT'", 
  "'VAR_INPUT_OUTPUT'", "'VAR_TEMP'", "'ARRAY'", "'['", "','", "']'", "'OF'", 
  "'..'", "'POINTER'", "'TO'", "':'", "':='", "';'", "'TRUE'", "'FALSE'", 
  "'-'"
};

std::vector<std::string> IEC61131Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "Binary_literal", "Octal_literal", "Decimal_literal", 
  "Pure_decimal_digits", "Hexadecimal_literal", "Floating_point_literal", 
  "Static_string_literal", "ID", "WS", "Block_comment", "Attribute", "Line_comment"
};

dfa::Vocabulary IEC61131Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> IEC61131Parser::_tokenNames;

IEC61131Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x23, 0x7b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x1f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x22, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2f, 0xa, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x32, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x35, 0xb, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3c, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x43, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x46, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x57, 
    0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x5a, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x60, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x69, 0xa, 0xa, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x5, 0xc, 0x6e, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x72, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0x75, 0xa, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x2, 0x2, 0xf, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0x4, 0x3, 
    0x2, 0x15, 0x16, 0x3, 0x2, 0x18, 0x1c, 0x2, 0x7d, 0x2, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x53, 0x3, 0x2, 0x2, 0x2, 0x10, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x68, 0x3, 0x2, 0x2, 0x2, 0x14, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x74, 0x3, 0x2, 0x2, 0x2, 0x18, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x20, 0x7, 0x3, 0x2, 0x2, 
    0x1d, 0x1f, 0x5, 0xe, 0x8, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x22, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x21, 0x23, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x4, 0x2, 0x2, 0x24, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x25, 0x2f, 0x7, 0x5, 0x2, 0x2, 0x26, 0x27, 0x8, 0x3, 0x1, 
    0x2, 0x27, 0x2f, 0x7, 0x6, 0x2, 0x2, 0x28, 0x29, 0x8, 0x3, 0x1, 0x2, 
    0x29, 0x2f, 0x7, 0x7, 0x2, 0x2, 0x2a, 0x2b, 0x8, 0x3, 0x1, 0x2, 0x2b, 
    0x2f, 0x7, 0x8, 0x2, 0x2, 0x2c, 0x2d, 0x8, 0x3, 0x1, 0x2, 0x2d, 0x2f, 
    0x7, 0x9, 0x2, 0x2, 0x2e, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x30, 0x32, 0x5, 0xe, 0x8, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x4, 0x2, 0x2, 0x37, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x3c, 0x7, 0x1f, 0x2, 0x2, 0x39, 0x3c, 0x5, 0x8, 
    0x5, 0x2, 0x3a, 0x3c, 0x5, 0xc, 0x7, 0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0xa, 0x2, 0x2, 0x3e, 
    0x3f, 0x7, 0xb, 0x2, 0x2, 0x3f, 0x44, 0x5, 0xa, 0x6, 0x2, 0x40, 0x41, 
    0x7, 0xc, 0x2, 0x2, 0x41, 0x43, 0x5, 0xa, 0x6, 0x2, 0x42, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0xd, 0x2, 0x2, 
    0x48, 0x49, 0x7, 0xe, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x6, 0x4, 0x2, 0x4a, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x18, 0xd, 0x2, 0x4c, 0x4d, 
    0x7, 0xf, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x18, 0xd, 0x2, 0x4e, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x10, 0x2, 0x2, 0x50, 0x51, 0x7, 0x11, 
    0x2, 0x2, 0x51, 0x52, 0x5, 0x6, 0x4, 0x2, 0x52, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x58, 0x7, 0x1f, 0x2, 0x2, 0x54, 0x55, 0x7, 0xc, 0x2, 0x2, 
    0x55, 0x57, 0x7, 0x1f, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x12, 0x2, 0x2, 0x5c, 0x5f, 0x5, 0x6, 
    0x4, 0x2, 0x5d, 0x5e, 0x7, 0x13, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x10, 0x9, 
    0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x14, 0x2, 0x2, 0x62, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x5, 0x12, 0xa, 0x2, 0x64, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x69, 0x5, 0x16, 0xc, 0x2, 0x66, 0x69, 0x5, 
    0x1a, 0xe, 0x2, 0x67, 0x69, 0x5, 0x14, 0xb, 0x2, 0x68, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x13, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x9, 0x2, 0x2, 0x2, 
    0x6b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6e, 0x7, 0x17, 0x2, 0x2, 0x6d, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x75, 0x5, 0x18, 0xd, 0x2, 0x70, 0x72, 0x7, 
    0x17, 0x2, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x7, 0x1d, 0x2, 
    0x2, 0x74, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x74, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x17, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x9, 0x3, 0x2, 0x2, 0x77, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0x1e, 0x2, 0x2, 0x79, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xd, 0x20, 0x2e, 0x33, 0x3b, 0x44, 0x58, 0x5f, 0x68, 
    0x6d, 0x71, 0x74, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

IEC61131Parser::Initializer IEC61131Parser::_init;
