#include "Lexer.hpp"
#include "cssparser.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <print>

std::string readFile(std::string path) {
	std::ifstream file(path, std::ios::binary);

	if (!file.is_open()) {
		std::println("Could not open file");
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
