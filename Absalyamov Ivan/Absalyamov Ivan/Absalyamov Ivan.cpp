#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TRUBA.h"
#include "KS.h"
#include "network.h"
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
	cout << "11. ���������\n";
	cout << "12. ���������\n";
	cout << "13. ��������� ������������� �������\n";
	cout << "14. ����������� ������������� �������\n";
	cout << "15. ������� �����\n";
	cout << "16. �������������� ����������\n";
	cout << "17. ����� ������������ �����\n";
	cout << "18. ����� ���������� ����\n";
	cout << "0. �����\n";
}
template<class Tcl, typename Tpar>
using Filter = bool(*)(const Tcl& object, Tpar param);
template<class Tcl, typename Tpar>
vector <int> FindObjectsByFilter(unordered_map <int, Tcl>& Group, Filter<Tcl,Tpar> f, Tpar param)
{
	vector <int> res;
	for (int i = 1; i <= Group.size(); i++)
	{
		Tcl t = Group[i];
		if (f(t, param))
			res.push_back(i);
	}
	return res;
}
template<class Tcl>
bool CheckbyNameObject(const Tcl& k, string param)
{
	return k.Getname() == param;
}
bool CheckbyPercent(const KS& k, float param)
{
	return ((100 * (k.Getkol() - k.Getkolvr()) / k.Getkol()) >= param);
}
bool CheckbyPr(const TRUBA& t, bool param)
{
	return t.Getpr() == param;
}

void Loading(unordered_map <int, TRUBA>& TRUBAS, unordered_map <int, KS>& KSS)
{
	TRUBAS.clear();
	KSS.clear();
	TRUBA::SetMaxID(1);
	KS::SetMaxID(1);
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
template <typename T>
void DeleteObject(unordered_map <int, T>& group)
{
	int id;
	cout << "������� id\n";
	id = proves(T::GetMaxID(), 1);
	if (group.count(id) == 0)
		cout << "��� �������� � ����� id"<<endl;
	else
	{
		group.erase(id);
		cout << "����� ������� �������"<<endl;
	}
}
void Connect(unordered_map<int, TRUBA>& trubas, unordered_map<int, KS>& kss)
{
	int MxidKS = KS::GetMaxID() - 1;
	cout << "������� id �� �� ������� ������� ����� ";
	int idKSvyhod = proves(MxidKS, 1);
	cout << "������� id �� � ������� ������ ����� ";
	int idKSvhod = proves(MxidKS, 1);
	cout << "������� id ����� ";
	int MxidTR = TRUBA::GetMaxID() - 1;
	int idTR = proves(MxidTR, 1);
	if (trubas.find(idTR)->second.GetStatusOfuse() == false)
	{
		trubas.find(idTR)->second.SetVyhod(idKSvyhod);
		trubas.find(idTR)->second.SetVhod(idKSvhod);
		trubas.find(idTR)->second.SetStatusOfuse(true);
	}
	else
		cout << "������ ����� ��� ������������";
}
void DisConnect(unordered_map<int, TRUBA>& trubas, unordered_map<int, KS>& kss)
{
	int Mxid = KS::GetMaxID() - 1;
	cout << "������� id �� �� ������� ������� ����� ";
	int idKSvyhod = proves(Mxid, 1);
	cout << "������� id �� � ������� ������ ����� ";
	int idKSvhod = proves(Mxid, 1);
	for (auto it = trubas.begin(); it != trubas.end(); it++)
		if ((it->second.GetVhod() == idKSvhod) && (it->second.GetVyhod() == idKSvyhod))
		{
			it->second.SetVhod(0);
			it->second.SetVyhod(0);
			it->second.SetStatusOfuse(false);
		}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	unordered_map <int, TRUBA> TRUBAS;
	unordered_map <int, KS> KSS;
	network net;
	do {
		print_menu();
		variant = proves(18, 0);
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
			if (TRUBAS.size() == 0) { cout << "����� �����������\n"; }
			else {
				cout << "�����\n";
				for (const auto& TR1 : TRUBAS)
					cout << TR1.second << endl;
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
				id = provewith0(TRUBA::GetMaxID(), 1);
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
				id = provewith0(KS::GetMaxID(), 1);
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
				int meanofsearch = proves(2, 1);
				if (meanofsearch == 1) {
					string name;
					cout << "������� �������� �����" << endl;
					cin >> name;
					for (int i : FindObjectsByFilter(TRUBAS, CheckbyNameObject, name))
						cout << TRUBAS[i] << endl;
				}
				else {
				    bool pr;
					cout << "Yes - ����� � �������/No - �� � �������" << endl;
					cin >> pr;
					for (int i : FindObjectsByFilter(TRUBAS, CheckbyPr, pr))
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
				int meanofsearch = proves(2, 1);
				if (meanofsearch == 1) {
					string name;
					cout << "������� �������� ��" << endl;
					cin >> name;
					for (int i : FindObjectsByFilter(KSS, CheckbyNameObject, name))
						cout << KSS[i] << endl;
				}
				else {
					float percent;
					cout << "������� �������" << endl;
					cin >> percent;
					for (int i : FindObjectsByFilter(KSS, CheckbyPercent, percent))
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
				int meanofsearch = proves(2, 1);
				vector <int> result;
				if (meanofsearch == 1)
				{
					string name;
					cout << "������� �������� �����" << endl;
					cin >> name;
					result = FindObjectsByFilter(TRUBAS, CheckbyNameObject, name);
					for (int i : result)
						cout << TRUBAS[i] << endl;
				}
				else {
					cout << "1 - ����� � �������/0 - �� � �������" << endl;
					bool pr = proves(1, 0);
					result = FindObjectsByFilter(TRUBAS, CheckbyPr, pr);
					for (int i : result)
						cout << TRUBAS[i] << endl;
				}
				cout << "1 - �������� ��������� ��������� ����\n" << "2 - ������� ��������������\n"<<"0 - �����\n";
				int choiceofaction = provewith0(2, 1);
				if (choiceofaction == 1)
					for (int i : result)
						EDITRUBA(TRUBAS[i]);
				else if (choiceofaction==2)
				{
					int k=1;
					cout << "������� id ����, ������� ������ ���������������. 0 - ���� ������ �����\n";
					while (k != 0)
					{
						k = provewith0(TRUBA::GetMaxID(), 1);
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
			Savingtofile(TRUBAS, KSS);
			break;
		}
		case 12:
		{
			Loading(TRUBAS,KSS);
			break;
		}
		case 13:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else 
				Connect(TRUBAS,KSS);
			break;
		}
		case 14:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else
				DisConnect(TRUBAS, KSS);
			break;
		}
		case 15:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else
				net.CreateMatrix(TRUBAS,KSS);
			break;
		}
		case 16:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else
				if (net.isCyclic() == true) cout << "���� ��������\n";
				else
					net.TopSort();
			break;
		}
		case 17:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else
				cout<<net.fordFulkerson(0, 5);
			break;
		}
		case 18:
		{
			if (TRUBAS.size() == 0)  cout << "����� �����������\n";
			else
				net.dijkstra(1);
			break;
		}
		return 0;
		}
		if (variant != 0)
			system("pause");
	} while (variant != 0);
	return 0;
}