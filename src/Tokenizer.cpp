#include "Tokenizer.hpp"

std::vector<std::unique_ptr<Token>> tokenize(std::string str) {
	std::vector<std::unique_ptr<Token>> tokens;

	for (int i = 0; i < str.length(); i++) {
		char c = str[i];

		if (c == '\n' || c == ' ') {
			continue;
		}

		if (c == '{') {
			tokens.emplace_back(std::make_unique<BracketOpen>());
		} else if (c == '}') {
			tokens.emplace_back(std::make_unique<BracketClose>());
		} else if (c == ':') {
			tokens.emplace_back(std::make_unique<Colon>());
		} else if (c == ';') {
			tokens.emplace_back(std::make_unique<Semicolon>());
		} else if (c == '.') {
			tokens.emplace_back(std::make_unique<Dot>());
		} else if (c == '#') {
			tokens.emplace_back(std::make_unique<Hashtag>());
		} else if (c >= '0' && c <= '9') {
			int digit = c - '0';
			if (!tokens.empty() && tokens.back()->type() == NUMBER) {
				auto number = dynamic_cast<Number *>(tokens.back().get());
				number->number = number->number * 10 + digit;
			} else
				tokens.emplace_back(std::make_unique<Number>(digit));
		} else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '-' ||
				   c == '_') {
			if (!tokens.empty() && tokens.back()->type() == IDENTIFIER) {
				dynamic_cast<Identifier *>(tokens.back().get())->identifier +=
					c;
			} else
				tokens.emplace_back(
					std::make_unique<Identifier>(std::string(1, c)));
		}
	}

	return tokens;
}
