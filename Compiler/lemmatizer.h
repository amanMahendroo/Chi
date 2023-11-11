#pragma once
#include <regex>
#include <vector>

namespace Lemmatizer {

	enum TokenType
	{
		IDENTIFIER,
		OPERATOR,
		CONSTANT,
		KEYWORD,
		SPECIAL,
		STRING
	};

	enum TokenValue
	{
		add,
		subtract,
		multiply,
		divide,
		exponent,
		modulo,
		range, // OPERATOR - ARITHMETIC
		equal,
		greater,
		greater_equal,
		lesser,
		lesser_equal,
		not_equal,	 // OPERATOR - COMPARATOR
		logical_not, // OPERATOR - LOGICAL
		walrus,		 // ASSIGNMENT
		kw_else,
		kw_for,
		kw_while,
		kw_print,
		kw_break,
		kw_const,
		kw_continue,
		kw_struct,
		kw_nil, // KEYWORDS
		square_open,
		square_close,
		implies,
		curly_open,
		curly_close,
		paren_open,
		paren_close, // SPECIAL
		dot,
		comma, // SPECIAL
		none,
	};

	const std::map<std::string, TokenValue> keyword_map({
		{"else", kw_else},
		{"for", kw_for},
		{"while", kw_while},
		{"print", kw_print},
		{"break", kw_break},
		{"const", kw_const},
		{"continue", kw_continue},
		{"struct", kw_struct},
		{"nil", kw_nil},
	});

	const std::map<std::string, TokenValue> operator_map({
		{"+", add},
		{"-", subtract},
		{"*", multiply},
		{"/", divide},
		{"^", exponent},
		{"\%", modulo},
		{"~=", not_equal},
		{"=>", implies},
		{"-", equal},
		{">=", greater_equal},
		{"<=", lesser_equal},
		{">", greater},
		{"<", lesser},
		{"~", logical_not},
		{":=", walrus},
		{":", range},
	});

	const std::map<std::string, TokenValue> special_char_map({
		{"(", paren_open},
		{")", paren_close},
		{"{", curly_open},
		{"}", curly_close},
		{"[", square_open},
		{"]", square_close},
		{".", dot},
		{",", comma},
	});

	const std::regex commentRegex("^#");
	const std::regex identifierRegex("^([a-zA-Z])([\\w$@]){0,39}");
	const std::regex stringRegex("^(\"[^\"]*\"|'[^']*')");
	const std::regex constantRegex("^(true|false|(\\d+(\\.\\d+)?([eE][+-]?\\d+)?))");
	const std::regex keywordRegex("^(else|for|while|print|break|const|continue|struct|nil)");
	const std::regex operatorRegex("^(\\+|-|\\*|/|~=|=>|=|>=|<=|>|<|~|\%|\\^|:=|:)");
	const std::regex specialCharRegex("^(\\{|\\(|\\[|\\]|\\)|\\}|\\]|\\.|,)");

	struct Token
	{
		std::string value;
		TokenType tokenType;
		TokenValue tokenValue;
	};

	/*
	 * Converts a list of strings into a list of token objects
	 */
	class Lemmatizer
	{
		public:
			[[nodiscard]] std::vector<Token> lemmatize(const std::vector<std::string> &input);
	};
}

