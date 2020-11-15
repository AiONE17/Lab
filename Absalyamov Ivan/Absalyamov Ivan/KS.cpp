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
	cout << "������� �������� " << endl;
	in >> ks.name;
	cout << "������� ���������� ����� " << endl;
	ks.kol = proves(500000, 0, "���������� ����� ������ ���� ����� ��������������� ������\n");
	cout << "������� ���������� ����� � ������� ��������� " << endl;
	ks.kolvr = proves(ks.kol, 0, "����������� ���������� ����� � ������\n");
	cout << "������� ������������� " << endl;
	ks.effect = proveofeffect(100, 0, "������������ �������������(�� 0 �� 100)\n");
	if (ks.kol >0)
	ks.percent = 100-100*(ks.kol - ks.kolvr) / ks.kol;
	return in;
}
ostream& operator << (ostream& out, const KS& ks)
{
	out << "�������������: " << ks.id << endl;
	out << "��������: " << ks.name << endl;
	out << "���������� �����: " << ks.kol << endl;
	out << "���������� ����� � ������� ���������: " << ks.kolvr << endl;
	out << "�������������: " << round(ks.effect * 100) / 100 << " %" << endl;
	return out;
}
void saveinformKStxt(KS ks, ofstream& fout)
{
	fout << ks.name << " " << ks.kol << " " << ks.kolvr << " " << ks.effect << " ";
}
void EDITKSPLUS(KS& ks)
{
	if (ks.kolvr == ks.kol) cout << "��� ���� ��������� � ������� ���������\n";
	else ks.kolvr = ks.kolvr + 1;
}
void EDITKSMINUS(KS& ks)
{
	if (ks.kolvr == 0)  cout << "��� ������� �����\n";
	else ks.kolvr = ks.kolvr - 1;
}
void EDITKS(KS& ks)
{
	cout << "1. ��������� ���\n2. ���������� ���\n";
	int vyb = proves(2, 1, "1 ��� 2!");
	if (vyb == 1) {
		EDITKSPLUS(ks);
	}
	else {
		EDITKSMINUS(ks);
	}
}
ifstream& operator >> (std::ifstream& myfile, KS& ks)
{
	myfile >> ks.name >> ks.kol >> ks.kolvr >> ks.effect;
	ks.percent = 100 * (ks.kol - ks.kolvr) / ks.kol;
	return myfile;
}
void PREP4DELKS(vector <KS>& KSS)
{
	cout << "������� id �� (������� 0, ���� ������ ����� � ����)\n";
	int id = proves(KSS.size(), 1, "��� �� � ����� id (������� 0, ���� ������ ����� � ����)\n");
	int i = 0;
	if (id != 0) {
		for (auto& t : KSS)
		{
			if (id != 0) {
				swap(KSS[i].name, KSS[KSS.size() - 1].name);
				swap(KSS[i].kol, KSS[KSS.size() - 1].kol);
				swap(KSS[i].kolvr, KSS[KSS.size() - 1].kolvr);
				swap(KSS[i].effect, KSS[KSS.size() - 1].effect);
			}
			i++;
		}
		KSS.pop_back();
	}
}
void knopkaEDITKS(vector <KS>& g)
{
	pair <int, KS&> ATR = SelectKS(g);
	if (ATR.first != 0) {
		EDITKS(ATR.second);
		g[ATR.first - 1] = ATR.second;
	}
}
pair <int, KS&> SelectKS(vector<KS>& g)
{
	cout << "������� id (������� 0, ���� ������ ����� � ����)\n";
	int index = proves(g.size(), 1, "��� ����� � ����� id (������� 0, ���� ������ ����� � ����)\n");
	if (index == 0) return{ index, g[0] };
	else
		return { index,g[index - 1] };
}
void POTeditKS1(vector <KS>& KSS)
{
	int flag = 1;
	do {
		pair <int, KS&> ATR = SelectKS(KSS);
		if (ATR.first != 0) {
			EDITKSPLUS(ATR.second);
			KSS[ATR.first - 1] = ATR.second;
		}
		flag = ATR.first;
	} while (flag != 0);
}
void POTeditKS2(vector <KS>& KSS)
{
	int flag = 1;
	do {
		pair <int, KS&> ATR = SelectKS(KSS);
		if (ATR.first != 0) {
			EDITKSMINUS(ATR.second);
			KSS[ATR.first - 1] = ATR.second;
		}
		flag = ATR.first;
	} while (flag != 0);
}
