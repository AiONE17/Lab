#include "TRUBA.h"
#include "utils.h"
#include <fstream>
using namespace std;
int TRUBA::MaxID=1;
std::string TRUBA::Getname() const
{
	return name;
}
bool TRUBA::Getpr() const
{
	return pr;
}
int TRUBA::GetID() const
{
	return id;
}
int TRUBA::GetMaxID() const
{
	return MaxID;
}
void TRUBA::SetID(int newID)
{
	id = newID;
}
void TRUBA::SetMaxID(int newID)
{
	MaxID = newID;
}
TRUBA::TRUBA()
{
	id = MaxID;
	MaxID++;
}
istream& operator >> (istream& in, TRUBA& truba)
{
	float vybor1;
	cout << "������� ��������" << endl;
	cin.ignore(256, '\n');
	getline(in, truba.name, '\n');
	cout << "������� �����" << endl;
	truba.dl = proves(5000000, 1);
	cout << "������� �������" << endl;
	truba.diam = proves(5000000, 1);
	cout << "� ������� ��� ��� (1-���� � �������, 0-���� � ������� ���������)" << endl;
	truba.pr = proves(1, 0);
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "�������������: " << truba.id<<endl;
	out << "��������: " << truba.name << endl;
	out << "�����: " << truba.dl << "\n";
	out << "�������: " << truba.diam << "\n";
	if (truba.pr==true)
		out << "� �������: " << "��" << "\n";
	else 
		out << "� �������: " << "H��" << "\n";
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
	truba.pr = !truba.pr;
}


