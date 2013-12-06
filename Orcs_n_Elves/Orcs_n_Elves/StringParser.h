#ifndef _STRING_PARSER_H
#define _STRING_PARSER_H
#include <string>
#include <iostream>
#include <sstream>
#include "SceneManager.h"
using namespace std;
class StringParser
{
private:
	static StringParser* _me;
	StringParser(void);
	
public:
	static StringParser* GetInstance();
	~StringParser(void);
	void ParseString(string _string);
};

#endif