#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct KS
{
	int id;
	string name;
	int kol;
	int kolvr;
	float effect;
};
struct TRUBA
{
	int id;
	int dl;
	int diam;
	string pr;
};
int proves(int verhgran, int nizhgran, string textoffail) {
	float vvedchis;
	while ((cin>>vvedchis).fail() || (vvedchis - floor(vvedchis)) || (vvedchis > verhgran) || (vvedchis < nizhgran))
	{
		cout << textoffail;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return vvedchis;
};
float proveofeffect(int verhgran, int nizhgran, string textoffail) {
	float vvedeffect;
	while ((cin >> vvedeffect).fail()|| (vvedeffect > verhgran) || (vvedeffect < nizhgran))
	{
		cout << textoffail;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return vvedeffect;
};
void print_menu() {
	system("cls");  // ������� �����
	cout << "����\n";
	cout << "1. �������� �����\n";
	cout << "2. �������� ��\n";
	cout << "3. �������� ���� ��������\n";
	cout << "4. ������������� �����\n";
	cout << "5. ������������� ��\n";
	cout << "6. ���������\n";
	cout << "7. ���������\n";
	cout << "0. �����\n";
}
TRUBA loadingTR(ifstream& myfile, int i)
{
	TRUBA TRUBA1;
	TRUBA1.id = i;
	myfile >> TRUBA1.dl >> TRUBA1.diam >> TRUBA1.pr;
	return TRUBA1;
}
KS loadingKS(ifstream& myfile, int i)
{
	KS KS1;
	KS1.id = i;
	myfile >> KS1.name >> KS1.kol >> KS1.kolvr >> KS1.effect;
	return KS1;
}
void saveinformTRUBAtxt(TRUBA truba, ofstream& fout)
{
	fout << truba.dl << " " << truba.diam << " " << truba.pr << " ";
}
void saveinformKStxt(KS ks, ofstream& fout)
{
	fout << ks.name << " " << ks.kol << " " << ks.kolvr << " " << ks.effect << " ";
}
void EDITRUBA(TRUBA&truba)
{
	if (truba.pr == "��") truba.pr = "���";
	else truba.pr = "��";
	cout << "������ ����� �������";
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
istream& operator >> (istream& in, TRUBA& truba)
{
	float dll;
	float diamm;
	float vybor1;
	truba.id = {};
	cout << "������� �����" << endl;
	truba.dl = proves(5000000, 0, "����� ������ ���� ����� ������������� ������\n");
	cout << "������� �������" << endl;
	truba.diam = proves(5000000, 0, "������� ������ ���� ����� ������������� ������\n");
	cout << "� ������� ��� ��� (1-���� � �������, 2-���� � ������� ���������)" << endl;
	vybor1 = proves(2, 1, "1 ��� 2!!!\n");
	if (vybor1 == 1) { truba.pr = "��"; }
	else if (vybor1 == 2) { truba.pr = "���"; }
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "�������������: " << truba.id << "\n";
	out << "�����: " << truba.dl << "\n";
	out << "�������: " << truba.diam << "\n";
	out << "� �������: " << truba.pr << "\n";
	return out;
}
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
TRUBA& SelectTRUBA(vector<TRUBA>&g)
{
	cout << "������� id\n";
	int index = proves(g.size(), 1, "��� ����� � ����� id\n");
	return g[index-1];
}
KS& SelectKS(vector<KS>&g)
{
	cout << "������� id\n";
	int index = proves(g.size(), 1, "��� ������������� ������� � ����� id");
	return g[index - 1];
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	vector <TRUBA> TRUBAS;
	vector <KS> KSS;
	do {
		print_menu();
		variant = proves(7, 0, "�������� ������� �����������, �������� ��������\n");
		switch (variant) {
		case 1:
		{
			TRUBA TR1;
			cin >> TR1;
			TR1.id = TRUBAS.size() + 1;
			TRUBAS.push_back(TR1);
			break;
		}
		case 2:
		{
			KS K1;
			cin >> K1;
			K1.id =KSS.size() + 1;
			KSS.push_back(K1);
			break;
		}
		case 3:
		{
			if (TRUBAS.size() == 0) { cout << "����� �����������\n"; }
			else {
				cout << "�����\n";
				for (TRUBA TR1 : TRUBAS)
					cout << TR1 << endl;
			}
			if (KSS.size() == 0) { cout << "������������� ������� �����������\n"; }
			else {
				cout << "������������� �������\n";
				for (KS K1 : KSS)
					cout << K1 << endl;
			}
			break;
		}
		case 4:
		{
			if (TRUBAS.size() == 0) { cout << "����� �����������\n"; }
			else {
				EDITRUBA(SelectTRUBA(TRUBAS));
			}
			break;
		}
		case 5:
		{
			if (KSS.size() == 0) { cout << "������������� ������� �����������\n"; }
			else {
				EDITKS(SelectKS(KSS));
			}
			break;
		}
		case 6:
		{
			ofstream fout;
			fout.open("file.txt",ios::out);
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
		case 7:
		{
			ifstream myfile;
			myfile.open("file.txt", ios::in);
			if (myfile.is_open())
			{ 
				int countTR, countKS;
				myfile >> countTR;
				while (countTR--) {
					TRUBAS.push_back(loadingTR(myfile,TRUBAS.size()+1));
				}
				myfile >> countKS;
				while (countKS--) {
					KSS.push_back(loadingKS(myfile, KSS.size()+1));
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