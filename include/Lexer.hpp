#pragma once

#include "Tokenizer.hpp"
#include <unordered_map>
#include <vector>
#include <memory>

enum SelectorType { CLASS, ID, ELEMENT };

struct Selector {
	SelectorType type;
	std::string name;

	std::unordered_map<std::string, int> properties;
};

std::vector<Selector> parseTokens(std::vector<std::unique_ptr<Token>> &tokens);
