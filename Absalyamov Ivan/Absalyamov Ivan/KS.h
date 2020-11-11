#pragma once
#include <string>
#include <vector>
#include <iostream>
class KS
{
	int kolvr;
	float effect;
	int kol;
	int id;
	static int MaxID;
public:
	float percent;
	std::string name;
	friend std::istream& operator >> (std::istream& in, KS& ks);
	friend std::ostream& operator << (std::ostream& out, const KS& ks);
	friend std::ifstream& operator >> (std::ifstream& myfile, KS& KS1);
	friend void saveinformKStxt(KS ks, std::ofstream& fout);
	friend void EDITKS(KS& ks);
	friend void PREP4DELKS(std::vector <KS>& KSS, int id);
	KS();
};


