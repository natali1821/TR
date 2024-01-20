
// Generated from gram.g4 by ANTLR 4.7.2


#include "gramListener.h"
#include "gramVisitor.h"

#include "gramParser.h"


using namespace antlrcpp;
using namespace antlr4;

gramParser::gramParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

gramParser::~gramParser() {
  delete _interpreter;
}

std::string gramParser::getGrammarFileName() const {
  return "gram.g4";
}

const std::vector<std::string>& gramParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& gramParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- DeclContext ------------------------------------------------------------------

gramParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

gramParser::TypeContext* gramParser::DeclContext::type() {
  return getRuleContext<gramParser::TypeContext>(0);
}

gramParser::InitContext* gramParser::DeclContext::init() {
  return getRuleContext<gramParser::InitContext>(0);
}

tree::TerminalNode* gramParser::DeclContext::SEMICOLON() {
  return getToken(gramParser::SEMICOLON, 0);
}

gramParser::DeclContext* gramParser::DeclContext::decl() {
  return getRuleContext<gramParser::DeclContext>(0);
}

tree::TerminalNode* gramParser::DeclContext::EOF() {
  return getToken(gramParser::EOF, 0);
}


size_t gramParser::DeclContext::getRuleIndex() const {
  return gramParser::RuleDecl;
}

void gramParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void gramParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


antlrcpp::Any gramParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<gramVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

gramParser::DeclContext* gramParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 0, gramParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(22);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(12);
      type();
      setState(13);
      init();
      setState(14);
      match(gramParser::SEMICOLON);
      setState(15);
      decl();
      setState(16);
      match(gramParser::EOF);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(18);
      type();
      setState(19);
      init();
      setState(20);
      match(gramParser::SEMICOLON);
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

//----------------- InitContext ------------------------------------------------------------------

gramParser::InitContext::InitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

gramParser::AssignContext* gramParser::InitContext::assign() {
  return getRuleContext<gramParser::AssignContext>(0);
}

tree::TerminalNode* gramParser::InitContext::COMMA() {
  return getToken(gramParser::COMMA, 0);
}

gramParser::InitContext* gramParser::InitContext::init() {
  return getRuleContext<gramParser::InitContext>(0);
}


size_t gramParser::InitContext::getRuleIndex() const {
  return gramParser::RuleInit;
}

void gramParser::InitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInit(this);
}

void gramParser::InitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInit(this);
}


antlrcpp::Any gramParser::InitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<gramVisitor*>(visitor))
    return parserVisitor->visitInit(this);
  else
    return visitor->visitChildren(this);
}

gramParser::InitContext* gramParser::init() {
  InitContext *_localctx = _tracker.createInstance<InitContext>(_ctx, getState());
  enterRule(_localctx, 2, gramParser::RuleInit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(29);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(24);
      assign();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(25);
      assign();
      setState(26);
      match(gramParser::COMMA);
      setState(27);
      init();
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

//----------------- AssignContext ------------------------------------------------------------------

gramParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* gramParser::AssignContext::VAR() {
  return getToken(gramParser::VAR, 0);
}

tree::TerminalNode* gramParser::AssignContext::EQUAL() {
  return getToken(gramParser::EQUAL, 0);
}

gramParser::ValueContext* gramParser::AssignContext::value() {
  return getRuleContext<gramParser::ValueContext>(0);
}


size_t gramParser::AssignContext::getRuleIndex() const {
  return gramParser::RuleAssign;
}

void gramParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void gramParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


antlrcpp::Any gramParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<gramVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

gramParser::AssignContext* gramParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 4, gramParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(35);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(31);
      match(gramParser::VAR);
      setState(32);
      match(gramParser::EQUAL);
      setState(33);
      value();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(34);
      match(gramParser::VAR);
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

//----------------- ValueContext ------------------------------------------------------------------

gramParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

gramParser::CalcContext* gramParser::ValueContext::calc() {
  return getRuleContext<gramParser::CalcContext>(0);
}

tree::TerminalNode* gramParser::ValueContext::TRUE() {
  return getToken(gramParser::TRUE, 0);
}

tree::TerminalNode* gramParser::ValueContext::FALSE() {
  return getToken(gramParser::FALSE, 0);
}


size_t gramParser::ValueContext::getRuleIndex() const {
  return gramParser::RuleValue;
}

void gramParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void gramParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


antlrcpp::Any gramParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<gramVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

gramParser::ValueContext* gramParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 6, gramParser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case gramParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(37);
        calc();
        break;
      }

      case gramParser::TRUE: {
        enterOuterAlt(_localctx, 2);
        setState(38);
        match(gramParser::TRUE);
        break;
      }

      case gramParser::FALSE: {
        enterOuterAlt(_localctx, 3);
        setState(39);
        match(gramParser::FALSE);
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

//----------------- CalcContext ------------------------------------------------------------------

gramParser::CalcContext::CalcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* gramParser::CalcContext::NUMBER() {
  return getToken(gramParser::NUMBER, 0);
}

gramParser::CalcContext* gramParser::CalcContext::calc() {
  return getRuleContext<gramParser::CalcContext>(0);
}

tree::TerminalNode* gramParser::CalcContext::PLUS() {
  return getToken(gramParser::PLUS, 0);
}


size_t gramParser::CalcContext::getRuleIndex() const {
  return gramParser::RuleCalc;
}

void gramParser::CalcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCalc(this);
}

void gramParser::CalcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCalc(this);
}


antlrcpp::Any gramParser::CalcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<gramVisitor*>(visitor))
    return parserVisitor->visitCalc(this);
  else
    return visitor->visitChildren(this);
}

gramParser::CalcContext* gramParser::calc() {
  CalcContext *_localctx = _tracker.createInstance<CalcContext>(_ctx, getState());
  enterRule(_localctx, 8, gramParser::RuleCalc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(42);
      match(gramParser::NUMBER);
      setState(43);
      dynamic_cast<CalcContext *>(_localctx)->op = match(gramParser::PLUS);
      setState(44);
      calc();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(45);
      match(gramParser::NUMBER);
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

//----------------- TypeContext ------------------------------------------------------------------

gramParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* gramParser::TypeContext::INT() {
  return getToken(gramParser::INT, 0);
}

tree::TerminalNode* gramParser::TypeContext::BOOL() {
  return getToken(gramParser::BOOL, 0);
}


size_t gramParser::TypeContext::getRuleIndex() const {
  return gramParser::RuleType;
}

void gramParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void gramParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<gramListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any gramParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<gramVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

gramParser::TypeContext* gramParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, gramParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    _la = _input->LA(1);
    if (!(_la == gramParser::INT

    || _la == gramParser::BOOL)) {
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

// Static vars and initialization.
std::vector<dfa::DFA> gramParser::_decisionToDFA;
atn::PredictionContextCache gramParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN gramParser::_atn;
std::vector<uint16_t> gramParser::_serializedATN;

std::vector<std::string> gramParser::_ruleNames = {
  "decl", "init", "assign", "value", "calc", "type"
};

std::vector<std::string> gramParser::_literalNames = {
  "", "'int'", "'bool'", "'True'", "'False'", "'+'", "'='", "','", "';'"
};

std::vector<std::string> gramParser::_symbolicNames = {
  "", "INT", "BOOL", "TRUE", "FALSE", "PLUS", "EQUAL", "COMMA", "SEMICOLON", 
  "VAR", "NUMBER", "WS"
};

dfa::Vocabulary gramParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> gramParser::_tokenNames;

gramParser::Initializer::Initializer() {
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
    0x3, 0xd, 0x35, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x19, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x20, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x26, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x2b, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x31, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x2, 0x2, 
    0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 0x3, 0x3, 0x2, 0x3, 0x4, 0x2, 
    0x34, 0x2, 0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x25, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x32, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x5, 0xc, 
    0x7, 0x2, 0xf, 0x10, 0x5, 0x4, 0x3, 0x2, 0x10, 0x11, 0x7, 0xa, 0x2, 
    0x2, 0x11, 0x12, 0x5, 0x2, 0x2, 0x2, 0x12, 0x13, 0x7, 0x2, 0x2, 0x3, 
    0x13, 0x19, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x5, 0xc, 0x7, 0x2, 0x15, 
    0x16, 0x5, 0x4, 0x3, 0x2, 0x16, 0x17, 0x7, 0xa, 0x2, 0x2, 0x17, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xe, 0x3, 0x2, 0x2, 0x2, 0x18, 0x14, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x20, 0x5, 0x6, 
    0x4, 0x2, 0x1b, 0x1c, 0x5, 0x6, 0x4, 0x2, 0x1c, 0x1d, 0x7, 0x9, 0x2, 
    0x2, 0x1d, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1e, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x7, 0xb, 0x2, 0x2, 0x22, 0x23, 
    0x7, 0x8, 0x2, 0x2, 0x23, 0x26, 0x5, 0x8, 0x5, 0x2, 0x24, 0x26, 0x7, 
    0xb, 0x2, 0x2, 0x25, 0x21, 0x3, 0x2, 0x2, 0x2, 0x25, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x7, 0x3, 0x2, 0x2, 0x2, 0x27, 0x2b, 0x5, 0xa, 0x6, 
    0x2, 0x28, 0x2b, 0x7, 0x5, 0x2, 0x2, 0x29, 0x2b, 0x7, 0x6, 0x2, 0x2, 
    0x2a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 
    0x7, 0xc, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x7, 0x2, 0x2, 0x2e, 0x31, 0x5, 
    0xa, 0x6, 0x2, 0x2f, 0x31, 0x7, 0xc, 0x2, 0x2, 0x30, 0x2c, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x32, 0x33, 0x9, 0x2, 0x2, 0x2, 0x33, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x7, 0x18, 0x1f, 0x25, 0x2a, 0x30, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

gramParser::Initializer gramParser::_init;
