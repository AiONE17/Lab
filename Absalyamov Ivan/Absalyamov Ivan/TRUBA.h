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
	std::string pr;
	std::string name;
	static int MaxID;
public:
	std::string Getname() const;
	std::string Getpr() const;
	int GetID() const;
	void SetID(int newMaxID);
	friend std::istream& operator >> (std::istream& in, TRUBA& truba);
	friend std::ostream& operator << (std::ostream& out, const TRUBA& truba);
	friend std::ifstream& operator >> (std::ifstream& myfile, TRUBA& TRUBA1);
	friend std::ofstream& operator << (std::ofstream& fout, const TRUBA& truba);
	friend void EDITRUBA(TRUBA& truba);
	TRUBA();
};

