
#include <regex>
#include <vector>
/*
 * Converts a list of strings into a list of token objects
 */

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
	kw_if,
	kw_else,
	kw_true,
	kw_false,
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
	curly_open,
	curly_close,
	paren_open,
	paren_close, // SPECIAL
	dot,
	comma, // SPECIAL
	none,
};

const std::regex commentRegex("^#");
const std::regex identifierRegex("^([a-zA-Z])([\\w$@]){0,39}");
const std::regex stringRegex("^(\"[^\"]*\"|'[^']*')");
const std::regex constantRegex("^(true|false|(\\d+(\\.\\d+)?([eE][+-]?\\d+)?))");
const std::regex keywordRegex("^(if|else|for|while|print|break|const|continue|struct|nil)");
const std::regex operatorRegex("^(\\+|-|\\*|/|~=|=>|=|>=|<=|>|<|~|\%|\\^|:=|:)");
const std::regex specialCharRegex("^(\\{|\\(|\\[|\\]|\\)|\\}|\\]|\\.|,)");

struct Token
{
	std::string value;
	TokenType tokenType;
	TokenValue tokenValue;
};

class Lemmatizer
{
	// Token: {string, type(enum)}

public:
	[[nodiscard]] std::vector<Token> lemmatize(const std::vector<std::string> &input) const
	{
		std::vector<Token> tokens;

		for (const std::string &statement : input)
		{
			for (auto curr = statement.cbegin(); curr != statement.cend();)
			{
				// match string
				std::smatch match;
				bool flag = false;
				bool result = regex_search(curr, statement.cend(), match, stringRegex);
				if (result)
				{
					tokens.push_back({match.str(0), STRING, none});
					curr += match.str(0).length();
					flag = true;
				}
				result = regex_search(curr, statement.cend(), match, commentRegex);
				if (result)
				{
					break;
				}
				result = regex_search(curr, statement.cend(), match, keywordRegex);
				if (result)
				{
					tokens.push_back({match.str(0), KEYWORD, none});
					curr += match.str(0).length();
					flag = true;
				}
				result = regex_search(curr, statement.cend(), match, identifierRegex);
				if (result)
				{
					tokens.push_back({match.str(0), IDENTIFIER, none});
					curr += match.str(0).length();
					flag = true;
				}
				result = regex_search(curr, statement.cend(), match, constantRegex);
				if (result)
				{
					tokens.push_back({match.str(0), CONSTANT, none});
					curr += match.str(0).length();
					flag = true;
				}
				result = regex_search(curr, statement.cend(), match, operatorRegex);
				if (result)
				{
					tokens.push_back({match.str(0), OPERATOR, none});
					curr += match.str(0).length();
					flag = true;
				}
				result = regex_search(curr, statement.cend(), match, specialCharRegex);
				if (result)
				{
					tokens.push_back({match.str(0), SPECIAL, none});
					curr += match.str(0).length();
					flag = true;
				}
				if (!flag)
					curr++;
			}
		}
		return tokens;
	}
};

// IDENTIFIER: [a-zA-Z_]{?:a-zA-Z0-9_$@}[,39]
// OPERATOR: [+|-|*|/|~|=|>|<|>=|<=|~=|%|^|:|:=]
// num: \d*(\.\d+)?([eE][+-]?\d+)?
// CONSTANT: [true|false|num]
// STRING: [".*"|'.*']
