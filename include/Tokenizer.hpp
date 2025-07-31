#pragma once
#include <string>
#include <vector>
#include <memory>

enum TokenType {
	IDENTIFIER,
	NUMBER,
	HASHTAG,
	DOT,
	BRACKET_OPEN,
	BRACKET_CLOSE,
	COLON,
	SEMICOLON,
};

class Token {
  public:
	virtual ~Token() = default;
	virtual TokenType type() const = 0;

	std::string toString() const {
		switch (type()) {
		case IDENTIFIER:
			return "IDENTIFIER";
		case NUMBER:
			return "NUMBER";
		case HASHTAG:
			return "HASHTAG";
		case DOT:
			return "DOT";
		case BRACKET_OPEN:
			return "BRACKET_OPEN";
		case BRACKET_CLOSE:
			return "BRACKET_CLOSE";
		case COLON:
			return "COLON";
		case SEMICOLON:
			return "SEMICOLON";
		default:
			return "UNKNOWN";
		}
	}
};

std::vector<std::unique_ptr<Token>> tokenize(std::string str);

class Identifier : public Token {
  public:
	~Identifier() override = default;
	Identifier(std::string identifier) : identifier(identifier) {}
	TokenType type() const override { return IDENTIFIER; }

	std::string identifier;
};

class Number : public Token {
  public:
	~Number() override = default;
	Number(int number) : number(number) {}
	TokenType type() const override { return NUMBER; }

	int number;
};

class Hashtag : public Token {
  public:
	~Hashtag() override = default;
	Hashtag() {}
	TokenType type() const override { return HASHTAG; }
};

class Dot : public Token {
  public:
	~Dot() override = default;
	Dot() {}
	TokenType type() const override { return DOT; }
};

class BracketOpen : public Token {
  public:
	~BracketOpen() override = default;
	BracketOpen() {}
	TokenType type() const override { return BRACKET_OPEN; }
};

class BracketClose : public Token {
  public:
	~BracketClose() override = default;
	BracketClose() {}
	TokenType type() const override { return BRACKET_CLOSE; }
};

class Colon : public Token {
  public:
	~Colon() override = default;
	Colon() {}
	TokenType type() const override { return COLON; }
};

class Semicolon : public Token {
  public:
	~Semicolon() override = default;
	Semicolon() {}
	TokenType type() const override { return SEMICOLON; }
};
