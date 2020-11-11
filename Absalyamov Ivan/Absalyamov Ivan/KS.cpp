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
void EDITKS(KS& ks)
{
	cout << "1. ��������� ���\n2. ���������� ���\n";
	int vyb = proves(2, 1, "1 ��� 2!");
	if (vyb == 1) {
		if (ks.kolvr == ks.kol) cout << "��� ���� ��������� � ������� ���������\n";
		else ks.kolvr = ks.kolvr + 1;
	}
	else {
		if (ks.kolvr == 0)  cout << "��� ������� �����\n";
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