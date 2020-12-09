#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TRUBA.h"
#include "KS.h"
#include "utils.h"
#include <unordered_map>
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
	cout << "10. Пакетное редактирование ТРУБ\n";
	cout << "11. Пакетное редактирование КС\n";
	cout << "12. Сохранить\n";
	cout << "13. Загрузить\n";
	cout << "0. Выход\n";
}
template <typename T>
using FilterTR = bool(*)(const TRUBA& t, T param);
bool CheckbyNameTR(const TRUBA& t, string param)
{
	return t.Getname()== param;
}
bool CheckbyPr(const TRUBA& t, bool param)
{
	return t.Getpr() == param;
}
template <typename T>
vector <int> FindTRUBAbyFilter(unordered_map <int, TRUBA>& TRUBAS, FilterTR<T> f, T param)
{
	vector <int> res;
	for (int i=0; i<TRUBAS.size(); i++)
	{
		TRUBA t = TRUBAS[i];
		if (f(t, param))
			res.push_back(i);
	}
	unordered_map <int, TRUBA>::iterator it =TRUBAS.end();
	it--;
	TRUBAS.erase(it);
	return res;
}
template <typename T>
using FilterKS = bool(*)(const KS& k, T param);
bool CheckbyNameKS(const KS& k, string param)
{
	return k.Getname() == param;
}
bool CheckPercent(const KS& k, float param)
{
	return ((100 * (k.Getkol() - k.Getkolvr()) / k.Getkol())>=param);
}
template <typename T>
vector <int> FindKSbyFilter(unordered_map <int, KS>& KSS, FilterKS<T> f, T param)
{
	vector <int> res;
	for (int i = 0; i < KSS.size(); i++)
	{
		KS k = KSS[i];
		if (f(k, param))
			res.push_back(i);
	}
	unordered_map <int, KS>::iterator it = KSS.end();
	it--;
	KSS.erase(it);
	return res;
}
void Loading(unordered_map <int, TRUBA>& TRUBAS, unordered_map <int, KS>& KSS)
{
	TRUBAS.clear();
	KSS.clear();
	TRUBA TR1;
	TR1.SetMaxID(1);
	KS K1;
	K1.SetMaxID(1);
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
			TRUBAS.insert(make_pair(TR.GetID(), TR));
		}
		myfile >> countKS;
		while (countKS--) {
			KS ks;
			myfile >> ks;
			KSS.insert(make_pair(ks.GetID(), ks));
		}
	}
	else cout << "Ошибка при чтении\n";
	myfile.close();
}
void Savingtofile(unordered_map <int, TRUBA>& TRUBAS, unordered_map <int, KS>& KSS)
{
	string filename;
	cout << "Введите название файла\n";
	cin >> filename;
	ofstream fout(filename);
	if (fout.is_open())
	{
		fout << TRUBAS.size()<<' ';
		for (const auto& TR1 : TRUBAS)
			fout << TR1.second;
		fout << endl;
		fout << KSS.size()<<' ';
		for (const auto& K1 : KSS)
			fout << K1.second;
	}
	fout.close();
}
template <typename T>
void DeleteObject(unordered_map <int, T>& group)
{
	int id;
	cout << "Введите id\n";
	id = proves(group.size(), 1);
	group.erase(id);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	unordered_map <int, TRUBA> TRUBAS;
	unordered_map <int, KS> KSS;
	do {
		print_menu();
		variant = proves(13, 0);
		switch (variant) {
		case 1:
		{
			TRUBA TR1;
			cin >> TR1;
			TRUBAS.insert(make_pair(TR1.GetID(), TR1));
			break;
		}
		case 2:
		{
			KS K1;
			cin >> K1;
			KSS.insert(make_pair(K1.GetID(), K1));
			break;
		}
		case 3:
		{
			DeleteObject(TRUBAS);
			break;
		}
	    case 4:
		{ 
			DeleteObject(KSS);
			break;
		}
		case 5:
		{
			if (TRUBAS.size() == 0) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "ТРУБЫ\n";
				for (const auto& TR1 : TRUBAS)
				{
					cout << TR1.second << endl;
				}
			}
			if (KSS.size() == 0) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "КОМПРЕССОРНЫЕ СТАНЦИИ\n";
				for (const auto& K1 : KSS)
					cout << K1.second<<endl;
			}
			break;
		}
		case 6:
		{
			if (TRUBAS.size() == 0)  cout << "ТРУБЫ ОТСУТСТВУЮТ\n";
			else {
				cout << "Введите id трубы. 0 - если хотите выйти\n";
				int id;
				id = provewith0(TRUBAS.size()-1, 1);
				if (id != 0) {
					unordered_map <int, TRUBA> ::iterator it;
					it = TRUBAS.find(id);
					EDITRUBA(it->second);
				}
			}
			break;
		}
		case 7:
		{
			if (KSS.size() == 0)  cout << "ТРУБЫ ОТСУТСТВУЮТ\n";
			else {
				cout << "Введите id трубы. 0 - если хотите выйти\n";
				int id;
				id = provewith0(KSS.size()-1, 1);
				if (id != 0) {
					unordered_map <int, KS> ::iterator it;
					it = KSS.find(id);
					EDITKS(it->second);
				}
			}
			break;
		}
		case 8:
		{
			if (TRUBAS.size() == 0)  cout << "ТРУБЫ ОТСУТСТВУЮТ\n";
			else {
				cout << "1. Поиск по названию\n" << "2. Поиск по признаку в ремонте\n";
				int meanofsearch = proves(2, 1);
				if (meanofsearch == 1) {
					string name;
					cout << "Введите название трубы" << endl;
					cin >> name;
					for (int i : FindTRUBAbyFilter(TRUBAS, CheckbyNameTR, name))
						cout << TRUBAS[i] << endl;
				}
				else {
				    bool pr;
					cout << "Yes - труба в ремонте/No - не в ремонте" << endl;
					cin >> pr;
					for (int i : FindTRUBAbyFilter(TRUBAS, CheckbyPr, pr))
						cout << TRUBAS[i] << endl;
				}
			}
			break;
		}
		case 9:
		{
			if (KSS.size() == 0)  cout << "КС ОТСУТСТВУЮТ\n";
			else {
				cout << "1. Поиск по названию\n" << "2. Поиск по проценту незадействованных цехов\n";
				int meanofsearch = proves(2, 1);
				if (meanofsearch == 1) {
					string name;
					cout << "Введите название КС" << endl;
					cin >> name;
					for (int i : FindKSbyFilter(KSS, CheckbyNameKS, name))
						cout << KSS[i] << endl;
				}
				else {
					float percent;
					cout << "Введите процент" << endl;
					cin >> percent;
					for (int i : FindKSbyFilter(KSS, CheckPercent, percent))
						cout << KSS[i] << endl;
				}
			}
			break;
		}
		case 10:
		{
			if (TRUBAS.size() == 0)  cout << "ТРУБЫ ОТСУТСТВУЮТ\n";
			else {
				cout << "1. Поиск по названию\n" << "2. Поиск по признаку в ремонте\n";
				int meanofsearch = proves(2, 1);
				vector <int> result;
				if (meanofsearch == 1)
				{
					string name;
					cout << "Введите название трубы" << endl;
					cin >> name;
					result = FindTRUBAbyFilter(TRUBAS, CheckbyNameTR, name);
					for (int i : result)
						cout << TRUBAS[i] << endl;
				}
				else {
					cout << "1 - труба в ремонте/0 - не в ремонте" << endl;
					bool pr = proves(1, 0);
					result = FindTRUBAbyFilter(TRUBAS, CheckbyPr, pr);
					for (int i : result)
						cout << TRUBAS[i] << endl;
				}
				cout << "1 - Изменить состояние выбранных труб\n" << "2 - выбрать самостоятельно\n"<<"0 - выйти\n";
				int choiceofaction = provewith0(2, 1);
				if (choiceofaction == 1)
					for (int i : result)
						EDITRUBA(TRUBAS[i]);
				else if (choiceofaction==2)
				{
					int k=1;
					cout << "Введите id труб, которые хотите отредактировать. 0 - если хотите выйти\n";
					while (k != 0)
					{
						k = provewith0(TRUBAS.size(), 1);
						if (k != 0) {
							unordered_map <int, TRUBA> ::iterator it;
							it = TRUBAS.find(k);
							EDITRUBA(it->second);
						}
					}
				}
			}
			break;
		}
		case 11:
		{
			if (KSS.size() == 0)  cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n";
			else {
				vector <int> res;
				cout << "1. Поиск по названию\n" << "2. Поиск по проценту незадействованных цехов\n";
				int vybor4 = proves(2, 1);
				if (vybor4 == 1) {
					string name;
					cout << "Введите название КС" << endl;
					cin >> name;
					res = FindKSbyFilter(KSS, CheckbyNameKS, name);
					for (int i : res)
						cout << KSS[i] << endl;
				}
				else {
					float percent;
					cout << "Введите процент" << endl;
					cin >> percent;
					res = FindKSbyFilter(KSS, CheckPercent, percent);
					for (int i : res)
						cout << KSS[i] << endl;
				}
				cout << "1 - Отредактировать выбранные КС\n" << "2 - выбрать самостоятельно\n" << "0 - выйти\n";
				int choice2 = proves(2, 0);
				if (choice2 == 1)
					for (int i : res)
						EDITKS(KSS[i]);
				else if (choice2 == 2)
				{
					int k = 1;
					cout << "Введите id КС, которые хотите отредактировать. 0 - если хотите выйти\n";
					while (k != 0)
					{
						k = provewith0(TRUBAS.size(), 1);
						if (k != 0) {
							unordered_map <int, KS> ::iterator it;
							it = KSS.find(k);
							EDITKS(it->second);
						}
					}
				}

			}
			break;
		}
		case 12:
		{
			Savingtofile(TRUBAS, KSS);
			break;
		}
		case 13:
		{
			Loading(TRUBAS,KSS);
			break;
		}
		return 0;
		}
		if (variant != 0)
			system("pause");
	} while (variant != 0);
	return 0;
}