#pragma once
#include <string>
#include <iostream>
class TRUBA
{
public:
	int id;
	int dl;
	int diam;
	std::string pr;
	friend std::istream& operator >> (std::istream& in, TRUBA& truba);
	friend std::ostream& operator << (std::ostream& out, const TRUBA& truba);
};

