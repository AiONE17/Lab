#pragma once
#include <string>
#include <iostream>
class KS
{
public:
	int id;
	std::string name;
	int kol;
	int kolvr;
	float effect;
	friend std::istream& operator >> (std::istream& in, KS& ks);
	friend std::ostream& operator << (std::ostream& out, const KS& ks);
};


