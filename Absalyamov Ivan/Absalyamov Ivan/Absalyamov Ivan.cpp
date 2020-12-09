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
	system("cls");  // ������� �����
	cout << "����\n";
	cout << "1. �������� �����\n";
	cout << "2. �������� ��\n";
	cout << "3. ������� �����\n";
	cout << "4. ������� ��\n";
	cout << "5. �������� ���� ��������\n";
	cout << "6. ������������� �����\n";
	cout << "7. ������������� ��\n";
	cout << "8. ����� ����� �� �������\n";
	cout << "9. ����� �� �� �������\n";
	cout << "10. �������� �������������� ����\n";
	cout << "11. �������� �������������� ��\n";
	cout << "12. ���������\n";
	cout << "13. ���������\n";
	cout << "0. �����\n";
}
using FilterTR = bool(*)(const TRUBA& t, string param);
bool CheckbyNameTR(const TRUBA& t, string param)
{
	return t.Getname()== param;
}
bool CheckbyPr(const TRUBA& t, string param)
{
	return t.Getpr() == param;
}
vector <int> FindTRUBAbyFilter(unordered_map <int, TRUBA>& TRUBAS, FilterTR f, string param)
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
	string filename;
	cout << "������� �������� �����\n";
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
	else cout << "������ ��� ������\n";
	myfile.close();
}
void Savingtofile(unordered_map <int, TRUBA>& TRUBAS, unordered_map <int, KS>& KSS)
{
	string filename;
	cout << "������� �������� �����\n";
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
int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	unordered_map <int, TRUBA> TRUBAS;
	unordered_map <int, KS> KSS;
	do {
		print_menu();
		variant = proves(13, 0, "�������� ������� �����������, �������� ��������\n");
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
			unordered_map <int, TRUBA> ::iterator it;
			int id;
			cout << "������� id\n";
			id = proves(TRUBAS.size(),1,"��� ����� � ����� id\n");
			unordered_map <int, TRUBA> ::iterator item1 = TRUBAS.find(id);
			unordered_map <int, TRUBA> ::iterator item2 = TRUBAS.find(TRUBAS.size());
			if ((item1 != TRUBAS.end()) && (item2 != TRUBAS.end()))
				swap(item1->second, item2->second);
			TRUBAS[id].SetID(id);
			TRUBAS.erase(item2);
			break;
		}
	    case 4:
		{
			int id;
			cout << "������� id\n";
			id = proves(KSS.size(), 1, "��� ����� � ����� id\n");
			unordered_map <int, KS> ::iterator item1 = KSS.find(id);
			unordered_map <int, KS> ::iterator item2 = KSS.find(KSS.size());
			if ((item1 != KSS.end()) && (item2 != KSS.end()))
				swap(item1->second, item2->second);
			KSS[id].SetID(id);
		    KSS.erase(item2);  
			break;
		}
		case 5:
		{
			if (TRUBAS.size() == 0) { cout << "����� �����������\n"; }
			else {
				cout << "�����\n";
				for (const auto& TR1 : TRUBAS)
					cout << TR1.second<<endl;
			}
			if (KSS.size() == 0) { cout << "������������� ������� �����������\n"; }
			else {
				cout << "������������� �������\n";
				for (const auto& K1 : KSS)
					cout << K1.second<<endl;
			}
			break;
		}
		case 6:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else {
				cout << "������� id �����. 0 - ���� ������ �����\n";
				int id;
				id = proves3(TRUBAS.size()-1, 1, "��� ����� � ����� id\n");
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
			if (KSS.size() == 0)  cout << "����� �����������\n";
			else {
				cout << "������� id �����. 0 - ���� ������ �����\n";
				int id;
				id = proves3(KSS.size()-1, 1, "��� �� � ����� id\n");
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
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else {
				cout << "1. ����� �� ��������\n" << "2. ����� �� �������� � �������\n";
				int vybor3 = proves(2, 1, "1 ��� 2!");
				if (vybor3 == 1) {
					string name;
					cout << "������� �������� �����" << endl;
					cin >> name;
					for (int i : FindTRUBAbyFilter(TRUBAS, CheckbyNameTR, name))
						cout << TRUBAS[i] << endl;
				}
				else {
					string pr;
					cout << "Yes - ����� � �������/No - �� � �������" << endl;
					cin >> pr;
					for (int i : FindTRUBAbyFilter(TRUBAS, CheckbyPr, pr))
						cout << TRUBAS[i] << endl;
				}
			}
			break;
		}
		case 9:
		{
			if (KSS.size() == 0)  cout << "�� �����������\n";
			else {
				cout << "1. ����� �� ��������\n" << "2. ����� �� �������� ����������������� �����\n";
				int vybor4 = proves(2, 1, "1 ��� 2!");
				if (vybor4 == 1) {
					string name;
					cout << "������� �������� ��" << endl;
					cin >> name;
					for (int i : FindKSbyFilter(KSS, CheckbyNameKS, name))
						cout << KSS[i] << endl;
				}
				else {
					float percent;
					cout << "������� �������" << endl;
					cin >> percent;
					for (int i : FindKSbyFilter(KSS, CheckPercent, percent))
						cout << KSS[i] << endl;
				}
			}
			break;
		}
		case 10:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else {
				cout << "1. ����� �� ��������\n" << "2. ����� �� �������� � �������\n";
				int choice = proves(2, 1, "1 ��� 2");
				vector <int> result;
				if (choice == 1)
				{
					string name;
					cout << "������� �������� �����" << endl;
					cin >> name;
					result = FindTRUBAbyFilter(TRUBAS, CheckbyNameTR, name);
					for (int i : result)
						cout << TRUBAS[i] << endl;
				}
				else {
					string pr;
					cout << "Yes - ����� � �������/No - �� � �������" << endl;
					cin >> pr;
					result = FindTRUBAbyFilter(TRUBAS, CheckbyPr, pr);
					for (int i : result)
						cout << TRUBAS[i] << endl;
				}
				cout << "1 - �������� ��������� ��������� ����\n" << "2 - ������� ��������������\n"<<"0 - �����\n";
				int choice2 = proves3(2, 1, "1 ��� 2");
				if (choice2 == 1)
					for (int i : result)
						EDITRUBA(TRUBAS[i]);
				else if (choice2==2)
				{
					int k=1;
					cout << "������� id ����, ������� ������ ���������������. 0 - ���� ������ �����\n";
					while (k != 0)
					{
						k = proves3(TRUBAS.size(), 1, "��� ����� � ����� id. 0 - ���� ������ �����\n");
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
			if (KSS.size() == 0)  cout << "������������� ������� �����������\n";
			else {
				vector <int> res;
				cout << "1. ����� �� ��������\n" << "2. ����� �� �������� ����������������� �����\n";
				int vybor4 = proves(2, 1, "1 ��� 2!");
				if (vybor4 == 1) {
					string name;
					cout << "������� �������� ��" << endl;
					cin >> name;
					res = FindKSbyFilter(KSS, CheckbyNameKS, name);
					for (int i : res)
						cout << KSS[i] << endl;
				}
				else {
					float percent;
					cout << "������� �������" << endl;
					cin >> percent;
					res = FindKSbyFilter(KSS, CheckPercent, percent);
					for (int i : res)
						cout << KSS[i] << endl;
				}
				cout << "1 - ��������������� ��������� ��\n" << "2 - ������� ��������������\n" << "0 - �����\n";
				int choice2 = proves3(2, 1, "1 ��� 2");
				if (choice2 == 1)
					for (int i : res)
						EDITKS(KSS[i]);
				else if (choice2 == 2)
				{
					int k = 1;
					cout << "������� id ��, ������� ������ ���������������. 0 - ���� ������ �����\n";
					while (k != 0)
					{
						k = proves3(TRUBAS.size(), 1, "��� �� � ����� id. 0 - ���� ������ �����\n");
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