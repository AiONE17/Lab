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
	cout << "Введите длину" << endl;
	truba.dl = proves(5000000, 0, "Длина должна быть целым положительным числом\n");
	cout << "Введите диаметр" << endl;
	truba.diam = proves(5000000, 0,"Диаметр должен быть целым положительным числом\n");
	cout << "В ремонте или нет (1-если в ремонте, 2-если в рабочем состоянии)" << endl;
	vybor1 = proves(2, 1, "1 или 2!!!\n");
	if (vybor1 == 1) { truba.pr = "Да"; }
	else if (vybor1 == 2) { truba.pr = "Нет"; }
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "Идентификатор: " << truba.id << "\n";
	out << "Длина: " << truba.dl << "\n";
	out << "Диаметр: " << truba.diam << "\n";
	out << "В ремонте: " << truba.pr << "\n";
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
	if (truba.pr == "Да") truba.pr = "Нет";
	else truba.pr = "Да";
	cout << "Статус трубы изменен";
}