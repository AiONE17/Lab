#pragma once
#include <string>
#include <iostream>
class TRUBA
{
	int dl;
	int diam;
	std::string pr;
public:
	int id;
	friend std::istream& operator >> (std::istream& in, TRUBA& truba);
	friend std::ostream& operator << (std::ostream& out, const TRUBA& truba);
	friend std::ifstream& operator >> (std::ifstream& myfile, TRUBA& TRUBA1);
	friend void saveinformTRUBAtxt(TRUBA truba, std::ofstream& fout);
	friend void EDITRUBA(TRUBA& truba);
};

