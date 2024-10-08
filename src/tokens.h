#ifndef TOKENS_H
#define TOKENS_H

#include <optional>
#include <string>
#include <vector>
#include <map>


#include "position.h"
//#pragma once

//! we should also store their names ngl
enum TokenType { 
	RETURN,
	INTEGER_DEF,
	STRING_DEF,
	BOOL,
	FLOAT,
	DECIMAL,
	LIST,
	ARRAY,
	DICT,
	CLASS,
	OPEN_PAREN, 
	CLOSE_PAREN, 
	INT_LITERAL, 
	SEMICOLON, 
	COLON,
	IDENT, 
	EQUALS, 
	ADDITION, 
	EXIT, 
	SUBTRACTION, 
	MULTIPLICATION, 
	DIVISION, 
	INCREMENT, 
	DECREMENT
};

std::map<TokenType, const char*> TokenMap = {
	{TokenType::RETURN, "return"},
	{TokenType::INTEGER_DEF, "int"},
	{TokenType::STRING_DEF, "str"},
	{TokenType::BOOL, "bool"},
	{TokenType::FLOAT, "float"},
	{TokenType::DECIMAL, "decimal"},
	{TokenType::LIST, "list"}
};


struct Tokens
{
	TokenType type;

	// (line number, column number)
	Position position;
	std::optional<std::string> value {};
};

namespace OperatorGroups
{
	extern std::vector<TokenType> OperatorTokens;
	extern std::vector<TokenType> UnaryOperators;
	extern std::vector<std::string> UnaryOperatorStrings;
	extern std::vector<std::string> OperatorStrings;
}

//struct TokenGroups
//{
//};

///*, TokenType::SUBTRACTION, TokenType::MULTIPLICATION, TokenType::DIVISION*/
//extern std::vector<TokenType> OperatorTokens;

#endif