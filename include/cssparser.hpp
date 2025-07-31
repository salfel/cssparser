#pragma once

#include "Lexer.hpp"
#include <string>

std::string readFile(std::string path);

std::vector<Selector> parseCSS(std::string filePath);
