#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "utils.h"
class TRUBA
{
	int diam;
	int id;
	bool pr;
	int dl;
	std::string name;
	static int MaxID;
	int vhod;
	int vyhod;
	bool StatusOfuse;
public:
	void SetVyhod(int id);
	void SetVhod(int id);
	int GetVyhod() const;
	int GetVhod() const;
	std::string Getname() const;
	bool Getpr() const;
	int GetID() const;
	int GetDL() const;
	bool GetStatusOfuse() const;
	static int GetMaxID();
	void SetID(int newMaxID);
	void SetStatusOfuse(bool newStatus);
	static void SetMaxID(int newID);
	friend std::istream& operator >> (std::istream& in, TRUBA& truba);
	friend std::ostream& operator << (std::ostream& out, const TRUBA& truba);
	friend std::ifstream& operator >> (std::ifstream& myfile, TRUBA& TRUBA1);
	friend std::ofstream& operator << (std::ofstream& fout, const TRUBA& truba);
	friend void EDITRUBA(TRUBA& truba);
	TRUBA();
};

