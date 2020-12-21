#include "TRUBA.h"
#include "utils.h"
#include <fstream>
using namespace std;
int TRUBA::MaxID=1;
string TRUBA::Getname() const
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
int TRUBA::GetVyhod() const
{
	return vyhod;
}
int TRUBA::GetVhod() const
{
	return vhod;
}
int TRUBA::GetDL() const
{
	return dl;
}
int TRUBA::GetMaxID()
{
	return MaxID;
}
bool TRUBA::GetStatusOfuse() const
{
	return StatusOfuse;
}
void TRUBA::SetID(int newID)
{
	id = newID;
}
void TRUBA::SetVhod(int id)
{
	vhod = id;
}
void TRUBA::SetVyhod(int id)
{
	vyhod = id;
}
void TRUBA::SetMaxID(int newID)
{
	MaxID = newID;
}
void TRUBA::SetStatusOfuse(bool newStatus)
{
	StatusOfuse = newStatus;
}
TRUBA::TRUBA()
{
	id = MaxID;
	MaxID++;
	StatusOfuse = false;
	vyhod = 0;
	vhod = 0;
}
istream& operator >> (istream& in, TRUBA& truba)
{
	float vybor1;
	cout << "Введите название" << endl;
	cin.ignore(256, '\n');
	getline(in, truba.name, '\n');
	cout << "Введите длину" << endl;
	truba.dl = proves(5000000, 1);
	cout << "Введите диаметр" << endl;
	truba.diam = proves(5000000, 1);
	cout << "В ремонте или нет (1-если в ремонте, 0-если в рабочем состоянии)" << endl;
	truba.pr = proves(1, 0);
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "Идентификатор: " << truba.id<<endl;
	out << "Название: " << truba.name << endl;
	out << "Длина: " << truba.dl << "\n";
	out << "Диаметр: " << truba.diam << "\n";
	if (truba.pr==true)
		out << "В ремонте: " << "Да" << "\n";
	else 
		out << "В ремонте: " << "Hет" << "\n";
	out << "выход " << truba.vyhod;
	out << "вход " << truba.vhod<<endl;
	out << "status" << truba.StatusOfuse << endl;
	return out;
}
ifstream& operator >> (ifstream& myfile, TRUBA& TRUBA1)
{
	myfile >> TRUBA1.name >> TRUBA1.dl >> TRUBA1.diam >> TRUBA1.pr;
	return myfile;
}
ofstream& operator << (ofstream& fout, const TRUBA& truba)
{
	fout << truba.name << " " << truba.dl << " " << truba.diam << " " << truba.pr;
	return fout;
}
void EDITRUBA(TRUBA& truba)
{
	truba.pr = !truba.pr;
}


