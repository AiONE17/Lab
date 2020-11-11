#include "TRUBA.h"
#include "utils.h"
#include <fstream>
using namespace std;
istream& operator >> (istream& in, TRUBA& truba)
{
	float dll;
	float diamm;
	float vybor1;
	truba.id = {};
	cout << "������� �����" << endl;
	truba.dl = proves(5000000, 0, "����� ������ ���� ����� ������������� ������\n");
	cout << "������� �������" << endl;
	truba.diam = proves(5000000, 0,"������� ������ ���� ����� ������������� ������\n");
	cout << "� ������� ��� ��� (1-���� � �������, 2-���� � ������� ���������)" << endl;
	vybor1 = proves(2, 1, "1 ��� 2!!!\n");
	if (vybor1 == 1) { truba.pr = "��"; }
	else if (vybor1 == 2) { truba.pr = "���"; }
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "�������������: " << truba.id << "\n";
	out << "�����: " << truba.dl << "\n";
	out << "�������: " << truba.diam << "\n";
	out << "� �������: " << truba.pr << "\n";
	return out;
}
ifstream& operator >> (ifstream& myfile, TRUBA& TRUBA1)
{
	TRUBA1.id = 0;
	myfile >> TRUBA1.dl >> TRUBA1.diam >> TRUBA1.pr;
	return myfile;
}
void saveinformTRUBAtxt(TRUBA truba, ofstream& fout)
{
	fout << truba.dl << " " << truba.diam << " " << truba.pr << " ";
}
void EDITRUBA(TRUBA& truba)
{
	if (truba.pr == "��") truba.pr = "���";
	else truba.pr = "��";
	cout << "������ ����� �������";
}