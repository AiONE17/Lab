#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "utils.h"
class KS
{
	float effect;
	int id;
	static int MaxID;
	int kol;
	int kolvr;
	std::string name;
public:
	std::string Getname() const;
	int Getkol() const;
	int Getkolvr() const;
	int GetMaxID() const;
	void SetMaxID(int newID);
	int GetID() const;
	void SetID(int newID);
	friend std::istream& operator >> (std::istream& in, KS& ks);
	friend std::ostream& operator << (std::ostream& out, const KS& ks);
	friend std::ifstream& operator >> (std::ifstream& myfile, KS& KS1);
	friend std::ofstream& operator << (std::ofstream& fout, const KS& ks);
	friend void EDITKS(KS& ks);
	KS();
};


