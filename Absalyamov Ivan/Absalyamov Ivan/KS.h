#pragma once
#include <string>
#include <vector>
#include <iostream>
class KS
{
	float effect;
	int id;
	static int MaxID;
	int kol;
	int kolvr;
public:
	float percent;
	std::string name;
	friend std::istream& operator >> (std::istream& in, KS& ks);
	friend std::ostream& operator << (std::ostream& out, const KS& ks);
	friend std::ifstream& operator >> (std::ifstream& myfile, KS& KS1);
	friend void saveinformKStxt(KS ks, std::ofstream& fout);
	friend void EDITKS(KS& ks);
	friend void EDITKSPLUS(KS& ks);
	friend void EDITKSMINUS(KS& ks);
	friend void PREP4DELKS(std::vector <KS>& KSS);
	friend void knopkaEDITKS(std::vector <KS>& g);
	friend std::pair <int, KS&> SelectKS(std::vector<KS>& g);
	friend void POTeditKS1(std::vector <KS>& KSS);
	friend void POTeditKS2(std::vector <KS>& KSS);
	KS();
};


