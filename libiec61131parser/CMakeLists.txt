# -*- coding:utf-8 -*-
# -*- кодировка:utf-8 -*-

SET (SUBPROJECT iec61131parser)
PROJECT (${SUBPROJECT})




SET (HEADERS
   IEC61131Listener.h
    IEC61131BaseListener.h
    IEC61131Parser.h
    IEC61131Lexer.h
    
    runtime/Parser.h
    runtime/antlr4-runtime.h
    runtime/ANTLRFileStream.h
    runtime/misc/MurmurHash.h
    runtime/misc/Predicate.h
    runtime/misc/IntervalSet.h
    runtime/misc/Interval.h
    runtime/TokenStreamRewriter.h
    runtime/RecognitionException.h
    runtime/DefaultErrorStrategy.h
    runtime/NoViableAltException.h
    runtime/LexerInterpreter.h
    runtime/ListTokenSource.h
runtime/CommonToken.h
runtime/dfa/DFAState.h
runtime/dfa/DFA.h
runtime/dfa/DFASerializer.h
runtime/dfa/LexerDFASerializer.h
runtime/Token.h
runtime/ConsoleErrorListener.h
runtime/UnbufferedCharStream.h
runtime/atn/LexerATNConfig.h
runtime/atn/RangeTransition.h
runtime/atn/LoopEndState.h
runtime/atn/PredicateTransition.h
runtime/atn/LookaheadEventInfo.h
runtime/atn/StarLoopbackState.h
runtime/atn/PrecedencePredicateTransition.h
runtime/atn/TokensStartState.h
runtime/atn/ATN.h
runtime/atn/ATNDeserializationOptions.h
runtime/atn/BlockStartState.h
runtime/atn/LexerIndexedCustomAction.h
runtime/atn/SemanticContext.h
runtime/atn/DecisionEventInfo.h
runtime/atn/NotSetTransition.h
runtime/atn/PlusBlockStartState.h
runtime/atn/LexerModeAction.h
runtime/atn/LexerTypeAction.h
runtime/atn/AtomTransition.h
runtime/atn/ATNDeserializer.h
runtime/atn/RuleTransition.h
runtime/atn/BasicState.h
runtime/atn/DecisionInfo.h
runtime/atn/PredictionContext.h
runtime/atn/EpsilonTransition.h
runtime/atn/LexerChannelAction.h
runtime/atn/LexerAction.h
runtime/atn/RuleStartState.h
runtime/atn/ATNConfigSet.h
runtime/atn/ATNSimulator.h
runtime/atn/StarLoopEntryState.h
runtime/atn/LexerActionType.h
runtime/atn/PredicateEvalInfo.h
runtime/atn/SetTransition.h
runtime/atn/ATNType.h
runtime/atn/RuleStopState.h
runtime/atn/LexerMoreAction.h
runtime/atn/LexerPopModeAction.h
runtime/atn/BasicBlockStartState.h
runtime/atn/AbstractPredicateTransition.h
runtime/atn/EmptyPredictionContext.h
runtime/atn/PredictionMode.h
runtime/atn/OrderedATNConfigSet.h
runtime/atn/ActionTransition.h
runtime/atn/WildcardTransition.h
runtime/atn/ContextSensitivityInfo.h
runtime/atn/StarBlockStartState.h
runtime/atn/ArrayPredictionContext.h
runtime/atn/Transition.h
runtime/atn/ProfilingATNSimulator.h
runtime/atn/LexerActionExecutor.h
runtime/atn/ATNState.h
runtime/atn/LexerATNSimulator.h
runtime/atn/ParseInfo.h
runtime/atn/ATNConfig.h
runtime/atn/ErrorInfo.h
runtime/atn/LexerCustomAction.h
runtime/atn/DecisionState.h
runtime/atn/LexerPushModeAction.h
runtime/atn/ATNSerializer.h
runtime/atn/LL1Analyzer.h
runtime/atn/AmbiguityInfo.h
runtime/atn/SingletonPredictionContext.h
runtime/atn/ParserATNSimulator.h
runtime/atn/PlusLoopbackState.h
runtime/atn/LexerSkipAction.h
runtime/atn/BlockEndState.h
runtime/IntStream.h
runtime/TokenStream.h
runtime/Recognizer.h
runtime/TokenSource.h
runtime/RuleContextWithAltNum.h
runtime/BufferedTokenStream.h
runtime/ParserInterpreter.h
runtime/TokenFactory.h
runtime/antlr4-common.h
runtime/Exceptions.h
runtime/LexerNoViableAltException.h
runtime/CommonTokenStream.h
runtime/WritableToken.h
runtime/InputMismatchException.h
runtime/CharStream.h
runtime/FailedPredicateException.h
runtime/Lexer.h
runtime/UnbufferedTokenStream.h
runtime/InterpreterRuleContext.h
runtime/CommonTokenFactory.h
runtime/DiagnosticErrorListener.h
runtime/ProxyErrorListener.h
runtime/ParserRuleContext.h
runtime/tree/ErrorNodeImpl.h
runtime/tree/IterativeParseTreeWalker.h
runtime/tree/TerminalNodeImpl.h
runtime/tree/ParseTree.h
runtime/tree/ParseTreeListener.h
runtime/tree/ParseTreeVisitor.h
runtime/tree/ParseTreeProperty.h
runtime/tree/ErrorNode.h
runtime/tree/pattern/TagChunk.h
runtime/tree/pattern/ParseTreePatternMatcher.h
runtime/tree/pattern/TextChunk.h
runtime/tree/pattern/ParseTreeMatch.h
runtime/tree/pattern/ParseTreePattern.h
runtime/tree/pattern/RuleTagToken.h
runtime/tree/pattern/TokenTagToken.h
runtime/tree/pattern/Chunk.h
runtime/tree/Trees.h
runtime/tree/TerminalNode.h
runtime/tree/xpath/XPathLexer.h
runtime/tree/xpath/XPathRuleAnywhereElement.h
runtime/tree/xpath/XPathElement.h
runtime/tree/xpath/XPathTokenElement.h
runtime/tree/xpath/XPath.h
runtime/tree/xpath/XPathTokenAnywhereElement.h
runtime/tree/xpath/XPathRuleElement.h
runtime/tree/xpath/XPathLexerErrorListener.h
runtime/tree/xpath/XPathWildcardAnywhereElement.h
runtime/tree/xpath/XPathWildcardElement.h
runtime/tree/AbstractParseTreeVisitor.h
runtime/tree/ParseTreeWalker.h
runtime/RuntimeMetaData.h
runtime/Vocabulary.h
runtime/ANTLRInputStream.h
runtime/BailErrorStrategy.h
runtime/support/Declarations.h
runtime/support/Any.h
runtime/support/Arrays.h
runtime/support/StringUtils.h
runtime/support/BitSet.h
runtime/support/guid.h
runtime/support/CPPUtils.h
runtime/ANTLRErrorListener.h
runtime/BaseErrorListener.h
runtime/RuleContext.h
runtime/ANTLRErrorStrategy.h

)

SET (SOURCES
    IEC61131Parser.cpp
    IEC61131Listener.cpp
    IEC61131BaseListener.cpp
    IEC61131Lexer.cpp
    
    runtime/WritableToken.cpp
runtime/misc/IntervalSet.cpp
runtime/misc/Interval.cpp
runtime/misc/Predicate.cpp
runtime/misc/MurmurHash.cpp
runtime/TokenStream.cpp
runtime/DefaultErrorStrategy.cpp
runtime/BaseErrorListener.cpp
runtime/ParserInterpreter.cpp
runtime/RuntimeMetaData.cpp
runtime/CharStream.cpp
runtime/CommonTokenStream.cpp
runtime/TokenSource.cpp
runtime/ANTLRInputStream.cpp
runtime/UnbufferedCharStream.cpp
runtime/FailedPredicateException.cpp
runtime/dfa/DFA.cpp
runtime/dfa/LexerDFASerializer.cpp
runtime/dfa/DFAState.cpp
runtime/dfa/DFASerializer.cpp
runtime/atn/ArrayPredictionContext.cpp
runtime/atn/ATNState.cpp
runtime/atn/BlockEndState.cpp
runtime/atn/SemanticContext.cpp
runtime/atn/PrecedencePredicateTransition.cpp
runtime/atn/LexerATNConfig.cpp
runtime/atn/LexerTypeAction.cpp
runtime/atn/PlusBlockStartState.cpp
runtime/atn/EmptyPredictionContext.cpp
runtime/atn/LexerMoreAction.cpp
runtime/atn/BasicBlockStartState.cpp
runtime/atn/LexerAction.cpp
runtime/atn/AbstractPredicateTransition.cpp
runtime/atn/LexerPopModeAction.cpp
runtime/atn/SingletonPredictionContext.cpp
runtime/atn/LexerModeAction.cpp
runtime/atn/LexerCustomAction.cpp
runtime/atn/PredicateTransition.cpp
runtime/atn/DecisionInfo.cpp
runtime/atn/DecisionState.cpp
runtime/atn/LexerSkipAction.cpp
runtime/atn/StarLoopEntryState.cpp
runtime/atn/Transition.cpp
runtime/atn/StarLoopbackState.cpp
runtime/atn/RuleStartState.cpp
runtime/atn/ATNDeserializer.cpp
runtime/atn/RangeTransition.cpp
runtime/atn/PredicateEvalInfo.cpp
runtime/atn/TokensStartState.cpp
runtime/atn/NotSetTransition.cpp
runtime/atn/LexerIndexedCustomAction.cpp
runtime/atn/ParseInfo.cpp
runtime/atn/LL1Analyzer.cpp
runtime/atn/ATN.cpp
runtime/atn/ATNConfig.cpp
runtime/atn/LoopEndState.cpp
runtime/atn/ATNDeserializationOptions.cpp
runtime/atn/PlusLoopbackState.cpp
runtime/atn/LexerPushModeAction.cpp
runtime/atn/AtomTransition.cpp
runtime/atn/PredictionMode.cpp
runtime/atn/OrderedATNConfigSet.cpp
runtime/atn/ParserATNSimulator.cpp
runtime/atn/LexerChannelAction.cpp
runtime/atn/StarBlockStartState.cpp
runtime/atn/LookaheadEventInfo.cpp
runtime/atn/ProfilingATNSimulator.cpp
runtime/atn/WildcardTransition.cpp
runtime/atn/ActionTransition.cpp
runtime/atn/BlockStartState.cpp
runtime/atn/ATNSimulator.cpp
runtime/atn/PredictionContext.cpp
runtime/atn/RuleStopState.cpp
runtime/atn/BasicState.cpp
runtime/atn/LexerActionExecutor.cpp
runtime/atn/ContextSensitivityInfo.cpp
runtime/atn/DecisionEventInfo.cpp
runtime/atn/EpsilonTransition.cpp
runtime/atn/SetTransition.cpp
runtime/atn/LexerATNSimulator.cpp
runtime/atn/ErrorInfo.cpp
runtime/atn/AmbiguityInfo.cpp
runtime/atn/ATNConfigSet.cpp
runtime/atn/RuleTransition.cpp
runtime/atn/ATNSerializer.cpp
runtime/Vocabulary.cpp
runtime/ANTLRFileStream.cpp
runtime/TokenStreamRewriter.cpp
runtime/Exceptions.cpp
runtime/BailErrorStrategy.cpp
runtime/DiagnosticErrorListener.cpp
runtime/LexerInterpreter.cpp
runtime/ANTLRErrorStrategy.cpp
runtime/BufferedTokenStream.cpp
runtime/RecognitionException.cpp
runtime/Token.cpp
runtime/CommonTokenFactory.cpp
runtime/LexerNoViableAltException.cpp
runtime/ParserRuleContext.cpp
runtime/ANTLRErrorListener.cpp
runtime/ConsoleErrorListener.cpp
runtime/NoViableAltException.cpp
runtime/InterpreterRuleContext.cpp
runtime/UnbufferedTokenStream.cpp
runtime/Parser.cpp
runtime/tree/ParseTreeVisitor.cpp
runtime/tree/ErrorNodeImpl.cpp
runtime/tree/ParseTree.cpp
runtime/tree/Trees.cpp
runtime/tree/ParseTreeListener.cpp
runtime/tree/ErrorNode.cpp
runtime/tree/ParseTreeWalker.cpp
runtime/tree/IterativeParseTreeWalker.cpp
runtime/tree/pattern/ParseTreePattern.cpp
runtime/tree/pattern/ParseTreeMatch.cpp
runtime/tree/pattern/Chunk.cpp
runtime/tree/pattern/TagChunk.cpp
runtime/tree/pattern/TextChunk.cpp
runtime/tree/pattern/RuleTagToken.cpp
runtime/tree/pattern/TokenTagToken.cpp
runtime/tree/pattern/ParseTreePatternMatcher.cpp
runtime/tree/xpath/XPathTokenElement.cpp
runtime/tree/xpath/XPathLexer.cpp
runtime/tree/xpath/XPathRuleElement.cpp
runtime/tree/xpath/XPathTokenAnywhereElement.cpp
runtime/tree/xpath/XPath.cpp
runtime/tree/xpath/XPathElement.cpp
runtime/tree/xpath/XPathRuleAnywhereElement.cpp
runtime/tree/xpath/XPathLexerErrorListener.cpp
runtime/tree/xpath/XPathWildcardAnywhereElement.cpp
runtime/tree/xpath/XPathWildcardElement.cpp
runtime/tree/TerminalNode.cpp
runtime/tree/TerminalNodeImpl.cpp
runtime/Recognizer.cpp
runtime/support/Any.cpp
runtime/support/Arrays.cpp
runtime/support/CPPUtils.cpp
runtime/support/guid.cpp
runtime/support/StringUtils.cpp
runtime/ListTokenSource.cpp
runtime/CommonToken.cpp
runtime/InputMismatchException.cpp
runtime/Lexer.cpp
runtime/RuleContext.cpp
runtime/RuleContextWithAltNum.cpp
runtime/ProxyErrorListener.cpp
runtime/IntStream.cpp
)




SOURCE_GROUP ("Header Files" FILES ${HEADERS})
SOURCE_GROUP ("Source Files" FILES ${SOURCES})

FIND_PACKAGE(Boost COMPONENTS locale )  
IF (NOT Boost_FOUND)
  MESSAGE(FATAL_ERROR "Boost not found" )
ENDIF (NOT Boost_FOUND)

ADD_DEFINITIONS(-DBOOST_ALL_NO_LIB)

ADD_LIBRARY(${SUBPROJECT}  ${HEADERS} ${SOURCES}   )


TARGET_INCLUDE_DIRECTORIES(${SUBPROJECT}  PUBLIC  ${Boost_INCLUDE_DIRS} runtime)
#TARGET_LINK_LIBRARIES (${SUBPROJECT}  ${Boost_LIBRARIES} )


IF (WIN32)
	#INCLUDE(GenerateExportHeader) 
	#GENERATE_EXPORT_HEADER(${SUBPROJECT})

ENDIF(WIN32)






