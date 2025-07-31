#include "Lexer.hpp"
#include <format>

std::vector<Selector> parseTokens(std::vector<std::unique_ptr<Token>> &tokens) {
	if (tokens.empty())
		return {};

	std::vector<Selector> selectors;

	for (int i = 0; i < tokens.size(); i++) {
		std::unique_ptr<Token> &token = tokens[i];

		Selector selector;
		switch (token->type()) {
		case IDENTIFIER: {
			selector.type = ELEMENT;
			selector.name =
				dynamic_cast<Identifier *>(tokens[i].get())->identifier;
			break;
		}
		case HASHTAG: {
			selector.type = ID;
			if (tokens[++i]->type() == IDENTIFIER) {
				selector.name =
					dynamic_cast<Identifier *>(tokens[i].get())->identifier;
			} else {
				throw std::runtime_error("Expected identifier after hashtag");
			}
			break;
		}
		case DOT: {
			selector.type = CLASS;
			if (tokens[++i]->type() == IDENTIFIER) {
				selector.name =
					dynamic_cast<Identifier *>(tokens[i].get())->identifier;
			} else {
				throw std::runtime_error("Expected identifier after dot");
			}
			break;
		}

		default: {
			throw std::runtime_error(
				std::format("unexpected token, got: {}", token->toString()));
		}
		}

		if (tokens[++i]->type() != BRACKET_OPEN) {
			throw std::runtime_error("Expected colon");
		}

		while (tokens[++i]->type() != BRACKET_CLOSE) {
			std::string property;
			int value;
			if (tokens[i]->type() == IDENTIFIER) {
				property =
					dynamic_cast<Identifier *>(tokens[i].get())->identifier;
			} else {
				throw std::runtime_error(std::format(
					"Expected identifier, got: {}", tokens[i]->toString()));
			}

			if (tokens[++i]->type() != COLON) {
				throw std::runtime_error("Expected colon");
			}

			if (tokens[++i]->type() == NUMBER) {
				value = dynamic_cast<Number *>(tokens[i].get())->number;
			} else {
				throw std::runtime_error("Expected number");
			}

			if (tokens[++i]->type() != SEMICOLON) {
				throw std::runtime_error(std::format(
					"Expected semicolon, got: {}", tokens[i]->toString()));
			}

			selector.properties[property] = value;
		}

		selectors.emplace_back(selector);
	}

	return selectors;
}
