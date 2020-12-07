#include "KS.h"
#include "utils.h"
#include <fstream>
#include <iostream>
using namespace std;
int KS::MaxID = 1;
std::string KS::Getname() const
{
	return name;
}
int KS::Getkolvr() const
{
	return kolvr;
}
int KS::Getkol() const
{
	return kol;
}
KS::KS()
{
	id = MaxID++;
}
int KS::GetMaxID()
{
	return MaxID;
}
int KS::GetID() const
{
	return id;
}
istream& operator >> (istream& in, KS& ks)
{
	cout << "������� �������� " << endl;
	std::cin.ignore(256, '\n');
	getline(in, ks.name, '\n');
	cout << "������� ���������� ����� " << endl;
	ks.kol = proves(500000, 0, "���������� ����� ������ ���� ����� ��������������� ������\n");
	cout << "������� ���������� ����� � ������� ��������� " << endl;
	ks.kolvr = proves(ks.kol, 0, "����������� ���������� ����� � ������\n");
	cout << "������� ������������� " << endl;
	ks.effect = proveofeffect(100, 0, "������������ �������������(�� 0 �� 100)\n");
	return in;
}
ostream& operator << (ostream& out, const KS& ks)
{
	out << "�������������: " << ks.id << endl;
	out << "��������: " << ks.name << endl;
	out << "���������� �����: " << ks.kol << endl;
	out << "���������� ����� � ������� ���������: " << ks.kolvr << endl;
	out << "�������������: " << round(ks.effect * 100) / 100 << " %" << endl;
	return out;
}
ofstream& operator << (ofstream& fout, const KS& ks)
{
	fout << ks.name << " " << ks.kol << " " << ks.kolvr << " " << ks.effect << " ";
	return fout;
}
void EDITKS(KS& ks)
{
	cout << "1. ��������� ���\n2. ���������� ���\n";
	int vyb = proves(2, 1, "1 ��� 2!");
	if (vyb == 1) {
		if (ks.kolvr == ks.kol) cout << "��� ���� ��������� � ������� ���������\n";
		else ks.kolvr = ks.kolvr + 1;
	}
	else {
		if (ks.kolvr == 0)  cout << "��� ������� �����\n";
		else ks.kolvr = ks.kolvr - 1;
	}
}
ifstream& operator >> (std::ifstream& myfile, KS& ks)
{
	myfile >> ks.name >> ks.kol >> ks.kolvr >> ks.effect;
	return myfile;
}