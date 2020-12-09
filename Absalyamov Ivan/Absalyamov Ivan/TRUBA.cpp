#include "TRUBA.h"
#include "utils.h"
#include <fstream>
using namespace std;
int TRUBA::MaxID=1;
std::string TRUBA::Getname() const
{
	return name;
}
std::string TRUBA::Getpr() const
{
	return pr;
}
int TRUBA::GetID() const
{
	return id;
}
void TRUBA::SetID(int newID)
{
	id = newID;
}
TRUBA::TRUBA()
{
	id = MaxID++;
}
istream& operator >> (istream& in, TRUBA& truba)
{
	float vybor1;
	cout << "������� ��������" << endl;
	std::cin.ignore(256, '\n');
	getline(in, truba.name, '\n');
	cout << "������� �����" << endl;
	truba.dl = proves(5000000, 0, "����� ������ ���� ����� ������������� ������\n");
	cout << "������� �������" << endl;
	truba.diam = proves(5000000, 0,"������� ������ ���� ����� ������������� ������\n");
	cout << "� ������� ��� ��� (1-���� � �������, 2-���� � ������� ���������)" << endl;
	vybor1 = proves(2, 1, "1 ��� 2!!!\n");
	if (vybor1 == 1) { truba.pr = "Yes"; }
	else if (vybor1 == 2) { truba.pr = "No"; }
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "�������������: " << truba.id<<endl;
	out << "��������: " << truba.name << endl;
	out << "�����: " << truba.dl << "\n";
	out << "�������: " << truba.diam << "\n";
	out << "� �������: " << truba.pr << "\n";
	return out;
}
ifstream& operator >> (ifstream& myfile, TRUBA& TRUBA1)
{
	myfile >> TRUBA1.name >>TRUBA1.dl >> TRUBA1.diam >> TRUBA1.pr;
	return myfile;
}
ofstream& operator << (ofstream& fout, const TRUBA& truba)
{
	fout << truba.name << " " << truba.dl << " " << truba.diam << " " << truba.pr << " ";
	return fout;
}
void EDITRUBA(TRUBA& truba)
{
	if (truba.pr == "Yes") truba.pr = "No";
	else truba.pr = "Yes";
	cout << "������ ����� �������\n";
}


