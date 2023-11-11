#include <regex>
#include <vector>
#include "lemmatizer.h"

using namespace Lemmatizer;

[[nodiscard]] std::vector<Token> Lemmatizer::lemmatize(const std::vector<std::string> &input) const
{
	std::vector<Token> tokens;

	for (const std::string &statement : input)
	{
		for (auto curr = statement.cbegin(); curr != statement.cend();)
		{
			// match string
			std::smatch match;
			if (regex_search(curr, statement.cend(), match, stringRegex))
			{
				tokens.push_back({match.str(0), STRING, none});
				curr += match.str(0).length();
			}
			else if (regex_search(curr, statement.cend(), match, commentRegex))
			{
				break;
			}
			else if (regex_search(curr, statement.cend(), match, keywordRegex))
			{
				tokens.push_back({match.str(0), KEYWORD, keyword_map[match.str(0)]});
				curr += match.str(0).length();
			}
			else if (regex_search(curr, statement.cend(), match, identifierRegex))
			{
				tokens.push_back({match.str(0), IDENTIFIER, none});
				curr += match.str(0).length();
			}
			else if (regex_search(curr, statement.cend(), match, constantRegex))
			{
				tokens.push_back({match.str(0), CONSTANT, none});
				curr += match.str(0).length();
			}
			else if (regex_search(curr, statement.cend(), match, operatorRegex))
			{
				tokens.push_back({match.str(0), OPERATOR, operator_map[match.str(0)]});
				curr += match.str(0).length();
			}
			else if (regex_search(curr, statement.cend(), match, specialCharRegex))
			{
				tokens.push_back({match.str(0), SPECIAL, special_char_map[match.str(0)]});
				curr += match.str(0).length();
			} else {
				curr++;
			}
		}
	}

	return tokens;
}

