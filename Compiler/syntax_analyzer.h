#pragma once

#include <map>
#include <set>
#include "lemmatizer.h"

namespace SyntaxAnalyzer {

	enum NonTerminals {
		START,
		STMT,
		DELTA,
		EXPR,
		EXPR_ID,
		EXPR_CT,
		FOR,
		WHILE,
		IF,
		ELIF,
		ELSE,
		ARGS,
		ARGS_DELTA,
	};

	// enum Terminals = TokenValue
	
	std::map<Lemmatizer::Token, vector<vector<Lemmatizer::Token>>> ProductionRules = {
		{START, {{STMT}}},
		{STMT,  {{EXPR, DELTA, STMT}, {none}}},
		{DELTA, {{FOR}, {WHILE}, {IF}, {none}}},
		{EXPR,  {{paren_open, EXPR, paren_close}, {curly_open, STMT, curly_close}, {UN_OPER, EXPR}, {id, EXPR_ID}, {lit, EXPR_LIT}, {kw_break}, {kw_continue}, {kw_nil}}},
		{EXPR_ID, {{BIN_OPER, EXPR}, {walrus, EXPR}, {paren_open, ARGS, paren_close, EXPR_ID}, {none}}},
		{EXPR_LIT, {{BIN_OPER, EXPR}, {none}}},
		{FOR, {{kw_for, id, kw_in, EXPR}}},
		{WHILE, {{kw_while, EXPR}}},
		{IF, {{implies, STMT, ELIF, ELSE}}},
		{ELIF, {{kw_elif, EXPR, implies, STMT, ELIF}, {none}}},
		{ELSE, {{kw_else, STMT}, {none}}},
		{ARGS, {{EXPR, ARGS_DELTA}, {none}}},
		{ARGS_DELTA, {{comma, EXPR, ARGS_DELTA}, {none}}},
	};

	std::map<Lemmatizer::Token, std::set<Lemmatizer::Token>> First, Follow;
	vector<vector<optional<pair<Lemmatizer::Token, int>>>> ParseTable;

	class SyntaxAnalyzer {

		void populateFirst();
		void populateFollow();
		void populateParseTable();

	};
}

