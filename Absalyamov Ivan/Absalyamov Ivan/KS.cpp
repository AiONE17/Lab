#include "KS.h"
#include "utils.h"
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
