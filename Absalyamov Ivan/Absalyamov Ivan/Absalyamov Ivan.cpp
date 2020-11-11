#include <iostream>
#include <fstream>
#include <vector>
#include "TRUBA.h"
#include "KS.h"
#include "utils.h"
using namespace std;
void print_menu() {
	system("cls");  // очищаем экран
	cout << "Меню\n";
	cout << "1. Добавить трубу\n";
	cout << "2. Добавить КС\n";
	cout << "3. Удалить трубу\n";
	cout << "4. Удалить КС\n";
	cout << "5. Просмотр всех объектов\n";
	cout << "6. Редактировать трубу\n";
	cout << "7. Редактировать КС\n";
	cout << "8. Поиск трубы по фильтру\n";
	cout << "9. Поиск КС по фильтру\n";
	cout << "10. Сохранить\n";
	cout << "11. Загрузить\n";
	cout << "0. Выход\n";
}
TRUBA& SelectTRUBA(vector<TRUBA>&g)
{
	cout << "Введите id\n";
	int index = proves(g.size(), 1, "Нет трубы с таким id\n");
	return g[index-1];
}
KS& SelectKS(vector<KS>&g)
{
	cout << "Введите id\n";
	int index = proves(g.size(), 1, "Нет компрессорной станции с таким id");
	return g[index - 1];
}
using FilterTR = bool(*)(const TRUBA& t, string param);
bool CheckbyNameTR(const TRUBA& t, string param)
{
	return t.name == param;
}
bool CheckbyPr(const TRUBA& t, string param)
{
	return t.pr == param;
}
vector <int> FindTRUBAbyFilter(const vector <TRUBA>& TRUBAS, FilterTR f, string param)
{
	vector <int> res;
	int i = 0;
	for (auto& t : TRUBAS)
	{
		if (f(t, param))
			res.push_back(i);
		i++;
	}
	return res;
}

template <typename T>
using FilterKS = bool(*)(const KS& k, T param);
bool CheckbyNameKS(const KS& k, string param)
{
	return k.name == param;
}
bool CheckPercent(const KS& k, float param)
{
	return k.percent == param;
}
template <typename T>
vector <int> FindKSbyFilter(const vector <KS>& KSS, FilterKS<T> f, T param)
{
	vector <int> res;
	int i = 0;
	for (auto& k : KSS)
	{
		if (f(k, param))
			res.push_back(i);
		i++;
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	vector <TRUBA> TRUBAS;
	vector <KS> KSS;
	do {
		print_menu();
		variant = proves(11, 0, "Действие выбрано некорректно, выберите повторно\n");
		switch (variant) {
		case 1:
		{
			TRUBA TR1;
			cin >> TR1;
			TRUBAS.push_back(TR1);
			break;
		}
		case 2:
		{
			KS K1;
			cin >> K1;
			KSS.push_back(K1);
			break;
		}
		case 3:
		{
			int id;
			cout << "Введите id трубы" << endl;
			cin >> id;
		    PREP4DELTR(TRUBAS,id);
			TRUBAS.pop_back();
			break;
		}
		case 4:
		{
			int id;
			cout << "Введите id КС" << endl;
			cin >> id;
			PREP4DELKS(KSS, id);
			KSS.pop_back();
			break;
		}
		case 5:
		{
			if (TRUBAS.size() == 0) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "ТРУБЫ\n";
				for (TRUBA TR1 : TRUBAS)
					cout << TR1 << endl;
			}
			if (KSS.size() == 0) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "КОМПРЕССОРНЫЕ СТАНЦИИ\n";
				for (KS K1 : KSS)
					cout << K1 << endl;
			}
			break;
		}
		case 6:
		{
			if (TRUBAS.size() == 0) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				EDITRUBA(SelectTRUBA(TRUBAS));
			}
			break;
		}
		case 7:
		{
			if (KSS.size() == 0) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				EDITKS(SelectKS(KSS));
			}
			break;
		}
		case 8:
		{
			cout << "1. Поиск по названию\n" << "2. Поиск по признаку в ремонте\n";
			int vybor3 = proves(2, 1, "1 или 2!");
			if (vybor3 == 1) {
				string name;
				cout << "Введите название трубы" << endl;
				cin >> name;
				for (int i : FindTRUBAbyFilter(TRUBAS, CheckbyNameTR, name))
					cout << TRUBAS[i] << endl;
			}
			else {
				string pr;
				cout << "Yes - труба в ремонте/No - не в ремонте" << endl;
				cin >> pr;
				for (int i : FindTRUBAbyFilter(TRUBAS, CheckbyPr, pr))
					cout << TRUBAS[i] << endl;
			}
			break;

		}
		case 9:
		{
			cout << "1. Поиск по названию\n" << "2. Поиск по проценту незадействованных цехов\n";
			int vybor4 = proves(2, 1, "1 или 2!");
			if (vybor4 == 1) {
				string name;
				cout << "Введите название КС" << endl;
				cin >> name;
				for (int i : FindKSbyFilter(KSS, CheckbyNameKS, name))
					cout << KSS[i]<<endl;
			}
			else {
				float percent;
				cout << "Введите процент" << endl;
				cin >> percent;
				for (int i : FindKSbyFilter(KSS, CheckPercent, percent))
					cout << KSS[i]<<endl;
			}
			break;
		}
		case 10:
		{
			string filename;
			cout << "Введите название файла\n";
			cin >> filename;
			ofstream fout(filename);
		    if (fout.is_open())
				{
				fout << TRUBAS.size()<<" ";
					for (TRUBA TR1 : TRUBAS)
						saveinformTRUBAtxt(TR1, fout);
					fout << endl;
					fout << KSS.size()<<" ";
					for (KS K1 : KSS)
						saveinformKStxt(K1, fout);
				}
			fout.close();
			break;
		}
		case 11:
		{
			TRUBAS.clear();
			KSS.clear();
			string filename;
			cout << "Введите название файла\n";
			cin >> filename;
			ifstream myfile(filename);
			if (myfile.is_open())
			{ 
				int countTR, countKS;
				myfile >> countTR;
				while (countTR--) {
					TRUBA TR;
					myfile >> TR;
					TRUBAS.push_back(TR);
				}
				myfile >> countKS;
				while (countKS--) {
					KS ks;
					myfile >> ks;
					KSS.push_back(ks);
				}
			}
			myfile.close();
			break;
		}
		return 0;
		}
		if (variant != 0)
			system("pause");
	} while (variant != 0);
	return 0;
}