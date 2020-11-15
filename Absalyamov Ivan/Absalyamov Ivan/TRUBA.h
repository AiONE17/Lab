#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "utils.h"
class TRUBA
{
	int dl;
	int diam;
	int id;
	static int MaxID;
public:
	std::string pr;
	std::string name;
	friend std::istream& operator >> (std::istream& in, TRUBA& truba);
	friend std::ostream& operator << (std::ostream& out, const TRUBA& truba);
	friend std::ifstream& operator >> (std::ifstream& myfile, TRUBA& TRUBA1);
	friend void saveinformTRUBAtxt(TRUBA truba, std::ofstream& fout);
	friend void EDITRUBA(TRUBA& truba);
	friend void PREP4DELTR(std::vector <TRUBA>& TRUBAS);
	friend std::pair <int, TRUBA&> SelectTRUBA(std::vector<TRUBA>& g);
	friend void knopkaEDITTR(std::vector <TRUBA>& g);
	friend void POTeditTR1(std::vector <TRUBA>& TRUBAS);
	TRUBA();
};

