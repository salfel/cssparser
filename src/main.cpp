#include "Lexer.hpp"
#include "cssparser.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <print>

std::string readFile(std::string path) {
	std::ifstream file(path, std::ios::binary);

	if (!file.is_open()) {
		return "";
	}

	std::string str((std::istreambuf_iterator<char>(file)),
					std::istreambuf_iterator<char>());

	return str;
}

std::vector<Selector> parseCSS(std::string filePath) {
	std::string str = readFile(filePath);
	auto tokens = tokenize(str);
	return parseTokens(tokens);
}

int main() {
	auto selectors = parseCSS("test.css");

	for (auto &selector : selectors) {
		std::println("name: {}", selector.name);
		switch (selector.type) {
		case CLASS:
			std::println("type: class");
			break;
		case ID:
			std::println("type: id");
			break;
		case ELEMENT:
			std::println("type: element");
			break;
		}

		for (auto &[key, value] : selector.properties) {
			std::println("key: {}, value: {}", key, value);
		}
	}

	return 0;
}
