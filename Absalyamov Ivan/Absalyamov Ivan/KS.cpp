#include "KS.h"
#include "utils.h"
using namespace std;
istream& operator >> (istream& in, KS& ks)
{
	float koll;
	float kollvr;
	float eeffect;
	ks.id = {};
	cout << "������� �������� " << endl;
	in >> ks.name;
	cout << "������� ���������� ����� " << endl;
	ks.kol = proves(500000, 0, "���������� ����� ������ ���� ����� ��������������� ������\n");
	cout << "������� ���������� ����� � ������� ��������� " << endl;
	ks.kolvr = proves(ks.kol, 0, "����������� ���������� ����� � ������\n");
	cout << "������� ������������� " << endl;
	ks.effect = proveofeffect(100, 0, "������������ �������������(�� 0 �� 100)\n");
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
