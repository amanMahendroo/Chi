

/*
 * Converts a list of strings into a list of token objects
 */

enum TokenType = {IDENTIFIER, OPERATOR, CONSTANT, KEYWORD, SPECIAL, STRING};
enum TokenValue = {
	add, subtract, multiply, divide, exponent, modulo, range, // OPERATOR - ARITHMETIC
	equal, greater, greater_equal, lesser, lesser_equal, not_equal, // OPERATOR - COMPARATOR
	logical_not, // OPERATOR - LOGICAL
	walrus, // ASSIGNMENT
	kw_if, kw_else, kw_true, kw_false, kw_for, kw_while, kw_print, kw_break,
	kw_const, kw_continue, kw_struct, kw_nil // KEYWORDS
	square_open, square_close, curly_open, curly_close, paren_open, paren_close, // SPECIAL
	dot, comma, // SPECIAL
};

struct Token {
	std::string value;
	enum TokenType;
	enum Token;
};

class Lemmatizer {
	// Token: {string, type(enum)}
	
	public:

	[[nodiscard]] std::vector<Token> lemmatize(const std::vector<std::string>> &input) const {
		
		for (std::string &statement : input) {
			
		}
	}
}

// IDENTIFIER: [a-zA-Z_]{?:a-zA-Z0-9_$@}[,39]
// OPERATOR: [+|-|*|/|~|=|>|<|>=|<=|~=|%|^|:|:=]
// num: \d*(\.\d+)?([eE][+-]?\d+)?
// CONSTANT: [true|false|num]
// STRING: [".*"|'.*']
