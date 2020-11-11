#include "KS.h"
#include "utils.h"
#include <fstream>
using namespace std;
istream& operator >> (istream& in, KS& ks)
{
	float koll;
	float kollvr;
	float eeffect;
	ks.id = {};
	cout << "Введите название " << endl;
	in >> ks.name;
	cout << "Введите количество цехов " << endl;
	ks.kol = proves(500000, 0, "Количество цехов должно быть целым неотрицательным числом\n");
	cout << "Введите количество цехов в рабочем состоянии " << endl;
	ks.kolvr = proves(ks.kol, 0, "Некорретное количество цехов в работе\n");
	cout << "Введите эффективность " << endl;
	ks.effect = proveofeffect(100, 0, "Некорректная эффективность(от 0 до 100)\n");
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
void saveinformKStxt(KS ks, ofstream& fout)
{
	fout << ks.name << " " << ks.kol << " " << ks.kolvr << " " << ks.effect << " ";
}
void EDITKS(KS& ks)
{
	cout << "1. Запустить цех\n2. Остановить цех\n";
	int vyb = proves(2, 1, "1 ИЛИ 2!");
	if (vyb == 1) {
		if (ks.kolvr == ks.kol) cout << "Все цехи находятся в рабочем состоянии\n";
		else ks.kolvr = ks.kolvr + 1;
	}
	else {
		if (ks.kolvr == 0)  cout << "Нет рабочих цехов\n";
		else ks.kolvr = ks.kolvr - 1;
	}
}
ifstream& operator >> (std::ifstream& myfile, KS& KS1)
{
	KS1.id = 0;
	myfile >> KS1.name >> KS1.kol >> KS1.kolvr >> KS1.effect;
	return myfile;
}