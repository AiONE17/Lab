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
	cout << "Введите название" << endl;
	std::cin.ignore(256, '\n');
	getline(in, truba.name, '\n');
	cout << "Введите длину" << endl;
	truba.dl = proves(5000000, 0, "Длина должна быть целым положительным числом\n");
	cout << "Введите диаметр" << endl;
	truba.diam = proves(5000000, 0,"Диаметр должен быть целым положительным числом\n");
	cout << "В ремонте или нет (1-если в ремонте, 2-если в рабочем состоянии)" << endl;
	vybor1 = proves(2, 1, "1 или 2!!!\n");
	if (vybor1 == 1) { truba.pr = "Yes"; }
	else if (vybor1 == 2) { truba.pr = "No"; }
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "Идентификатор: " << truba.id<<endl;
	out << "Название: " << truba.name << endl;
	out << "Длина: " << truba.dl << "\n";
	out << "Диаметр: " << truba.diam << "\n";
	out << "В ремонте: " << truba.pr << "\n";
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
	cout << "Статус трубы изменен\n";
}


