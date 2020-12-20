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
void KS::SetID(int newID)
{
	id = newID;
}
int KS::GetMaxID()
{
	return MaxID;
}
int KS::GetID() const
{
	return id;
}
void KS::SetMaxID(int newID)
{
	MaxID = newID;
}
KS::KS()
{
	id = MaxID;
	MaxID++;
}

istream& operator >> (istream& in, KS& ks)
{
	cout << "Введите название " << endl;
	std::cin.ignore(256, '\n');
	getline(in, ks.name, '\n');
	cout << "Введите количество цехов " << endl;
	ks.kol = proves(500000, 0);
	cout << "Введите количество цехов в рабочем состоянии " << endl;
	ks.kolvr = proves(ks.kol, 0);
	cout << "Введите эффективность " << endl;
	ks.effect = proveofeffect(100, 0);
	return in;
}
ostream& operator << (ostream& out, const KS& ks)
{
	out << "Идентификатор: " << ks.id << endl;
	out << "Название: " << ks.name << endl;
	out << "Количество цехов: " << ks.kol << endl;
	out << "Количество цехов в рабочем состоянии: " << ks.kolvr << endl;
	out << "Эффективность: " << round(ks.effect * 100) / 100 << " %" << endl;
	return out;
}
ofstream& operator << (ofstream& fout, const KS& ks)
{
	fout << ks.name << " " << ks.kol << " " << ks.kolvr << " " << ks.effect << " ";
	return fout;
}
void EDITKS(KS& ks)
{
	cout << "1. Запустить цех\n2. Остановить цех\n";
	int vyb = proves(2, 1);
	if (vyb == 1) {
		if (ks.kolvr == ks.kol) cout << "Все цехи находятся в рабочем состоянии\n";
		else ks.kolvr = ks.kolvr + 1;
	}
	else {
		if (ks.kolvr == 0)  cout << "Нет рабочих цехов\n";
		else ks.kolvr = ks.kolvr - 1;
	}
}
ifstream& operator >> (std::ifstream& myfile, KS& ks)
{
	myfile >> ks.name >> ks.kol >> ks.kolvr >> ks.effect;
	return myfile;
}