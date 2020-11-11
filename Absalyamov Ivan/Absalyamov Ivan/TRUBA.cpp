#include "TRUBA.h"
#include "utils.h"
#include <fstream>
using namespace std;
int TRUBA::MaxID=1;
TRUBA::TRUBA()
{
	id = MaxID++;
}
istream& operator >> (istream& in, TRUBA& truba)
{
	float vybor1;
	cout << "������� ��������" << endl;
	in >> truba.name;
	cout << "������� �����" << endl;
	truba.dl = proves(5000000, 0, "����� ������ ���� ����� ������������� ������\n");
	cout << "������� �������" << endl;
	truba.diam = proves(5000000, 0,"������� ������ ���� ����� ������������� ������\n");
	cout << "� ������� ��� ��� (1-���� � �������, 2-���� � ������� ���������)" << endl;
	vybor1 = proves(2, 1, "1 ��� 2!!!\n");
	if (vybor1 == 1) { truba.pr = "Yes"; }
	else if (vybor1 == 2) { truba.pr = "No"; }
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "�������������: " << truba.id<<endl;
	out << "��������: " << truba.name << endl;
	out << "�����: " << truba.dl << "\n";
	out << "�������: " << truba.diam << "\n";
	out << "� �������: " << truba.pr << "\n";
	return out;
}
ifstream& operator >> (ifstream& myfile, TRUBA& TRUBA1)
{
	myfile >> TRUBA1.name >>TRUBA1.dl >> TRUBA1.diam >> TRUBA1.pr;
	return myfile;
}
void saveinformTRUBAtxt(TRUBA truba, ofstream& fout)
{
	fout << truba.name<<" "<< truba.dl << " " << truba.diam << " " << truba.pr << " ";
}
void EDITRUBA(TRUBA& truba)
{
	if (truba.pr == "��") truba.pr = "���";
	else truba.pr = "��";
	cout << "������ ����� �������";
}
void PREP4DELTR(vector <TRUBA>& TRUBAS, int id)
{
	int i = 0;
	for (auto& t : TRUBAS)
	{
		if (t.id == id)
		{
			swap(TRUBAS[i].name, TRUBAS[TRUBAS.size() - 1].name);
			swap(TRUBAS[i].dl, TRUBAS[TRUBAS.size() - 1].dl);
			swap(TRUBAS[i].diam, TRUBAS[TRUBAS.size() - 1].diam);
			swap(TRUBAS[i].pr, TRUBAS[TRUBAS.size() - 1].pr);
			
		}
		i++;
	}

}

