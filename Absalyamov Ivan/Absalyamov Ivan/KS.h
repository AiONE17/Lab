#pragma once
#include <string>
#include <iostream>
class KS
{
	int kol;
	int kolvr;
	float effect;
public:
	int id;
	std::string name;
	friend std::istream& operator >> (std::istream& in, KS& ks);
	friend std::ostream& operator << (std::ostream& out, const KS& ks);
	friend std::ifstream& operator >> (std::ifstream& myfile, KS& KS1);
	friend void saveinformKStxt(KS ks, std::ofstream& fout);
	friend void EDITKS(KS& ks);
};


