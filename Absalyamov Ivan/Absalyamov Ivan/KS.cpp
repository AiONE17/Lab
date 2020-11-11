#include "KS.h"
#include "utils.h"
#include <fstream>
using namespace std;
int KS::MaxID = 1;
KS::KS()
{
	id = MaxID++;
}
istream& operator >> (istream& in, KS& ks)
{
	cout << "Введите название " << endl;
	in >> ks.name;
	cout << "Введите количество цехов " << endl;
	ks.kol = proves(500000, 0, "Количество цехов должно быть целым неотрицательным числом\n");
	cout << "Введите количество цехов в рабочем состоянии " << endl;
	ks.kolvr = proves(ks.kol, 0, "Некорретное количество цехов в работе\n");
	cout << "Введите эффективность " << endl;
	ks.effect = proveofeffect(100, 0, "Некорректная эффективность(от 0 до 100)\n");
	ks.percent = 100-100*(ks.kol - ks.kolvr) / ks.kol;
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
ifstream& operator >> (std::ifstream& myfile, KS& ks)
{
	myfile >> ks.name >> ks.kol >> ks.kolvr >> ks.effect;
	ks.percent = 100 * (ks.kol - ks.kolvr) / ks.kol;
	return myfile;
}
void PREP4DELKS(vector <KS>& KSS, int id)
{
	int i = 0;
	for (auto& t : KSS)
	{
		if (t.id == id)
		{
			swap(KSS[i].name, KSS[KSS.size() - 1].name);
			swap(KSS[i].kol, KSS[KSS.size() - 1].kol);
			swap(KSS[i].kolvr, KSS[KSS.size() - 1].kolvr);
			swap(KSS[i].effect, KSS[KSS.size() - 1].effect);
		}
		i++;
	}

}