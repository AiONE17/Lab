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
int proves(float vvedchis, int nizhgran, int verhgran, string s) {
	while (cin.fail() || (vvedchis - floor(vvedchis)) || (vvedchis > nizhgran) || (vvedchis < verhgran))
	{
		cout << s;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> vvedchis;
	}
	return vvedchis;
};
float proveofeffect(float vvedeffect, int nizhgran, int verhgran, string textoffail) {
	while ((vvedeffect > nizhgran) || (vvedeffect < verhgran))
	{
		cout << textoffail;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> vvedeffect;
	}
	return vvedeffect;
};
TRUBA CreateTRUBA()
{
	TRUBA TRUBA1;
	float dll;
	float diamm;
	TRUBA1.id = {};
	cout << "������� �����" << endl;
	cin >> dll;
	TRUBA1.dl = proves(dll, 5000000, 0, "����� ������ ���� ����� ������������� ������\n");
	cout << "������� �������" << endl;
	cin >> diamm;
	TRUBA1.diam = proves(diamm, 5000000, 0, "������� ������ ���� ����� ������������� ������\n");
	cout << "� ������� ��� ��� (1-���� � �������, 2-���� � ������� ���������)" << endl;
	float vybor1;
	cin >> vybor1;
	vybor1 = proves(vybor1, 2, 1, "1 ��� 2!!!\n");
	if (vybor1 == 1) { TRUBA1.pr = "��"; }
	else if (vybor1 == 2) { TRUBA1.pr = "���"; }
	return TRUBA1;
}
KS CreateKS()
{
	KS KS1;
	float koll;
	float kollvr;
	float eeffect;
	KS1.id = {};
	cout << "������� �������� " << endl;
	cin >> KS1.name;
	cout << "������� ���������� ����� " << endl;
	cin >> koll;
	KS1.kol = proves(koll, 500000, 0, "���������� ����� ������ ���� ����� ��������������� ������\n");
	cout << "������� ���������� ����� � ������� ��������� " << endl;
	cin >> kollvr;
	KS1.kolvr = proves(kollvr, koll, 0, "����������� ���������� ����� � ������\n");
	cout << "������� ������������� " << endl;
	cin >> eeffect;
	KS1.effect = proveofeffect(eeffect, 100, 0, "������������ �������������(�� 0 �� 100)\n");
	return KS1;
}
void printInformTRUBA(TRUBA truba)
{
	cout << "�������������: " << truba.id << "\n";
	cout << "�����: " << truba.dl << "\n";
	cout << "�������: " << truba.diam << "\n";
	cout << "� �������: " << truba.pr << "\n";
}
void printInformKS(KS ks)
{
	cout << "�������������: " << ks.id << "\n";
	cout << "��������: " << ks.name << "\n";
	cout << "���������� �����: " << ks.kol << "\n";
	cout << "���������� ����� � ������� ���������: " << ks.kolvr << "\n";
	cout << "�������������: " << round(ks.effect * 100) / 100 << " %" << "\n";
}
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
TRUBA loadingTR(ifstream& myfile)
{
	TRUBA TRUBA1;
	TRUBA1.id = {};
	myfile >> TRUBA1.dl >> TRUBA1.diam >> TRUBA1.pr;
	return TRUBA1;
}
KS loadingKS(ifstream& myfile)
{
	KS KS1;
	KS1.id = {};
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
int RedactKS(int vyb, KS ks)
{
	if (vyb == 1) {
		if (ks.kolvr == ks.kol) { cout << "��� ���� ��������� � ������� ���������\n"; }
		else {
			return 1;
		}
	}
	else {
		if (ks.kolvr == 0) { cout << "��� ������� �����\n"; }
		else {
			return -1;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	float vvariant;
	KS K1;
	int idTR = 0, idKS = 0;
	TRUBA TR1;
	do {
		print_menu();
		cin >> vvariant;
		variant = proves(vvariant, 7, 0, "�������� ������� �����������, �������� ��������\n");
		switch (variant) {
		case 1:
		{
			TR1 = CreateTRUBA();
			TR1.id = idTR + 1;
			printInformTRUBA(TR1);
			idTR++;
			break;
		}
		case 2:
		{
			K1 = CreateKS();
			K1.id = idKS + 1;
			printInformKS(K1);
			idKS++;
			break;
		}
		case 3:
		{
			if (idTR == 0) { cout << "����� �����������\n"; }
			else {
				cout << "�����\n";
				printInformTRUBA(TR1);
				cout << "\n";
			}
			if (idKS == 0) { cout << "������������� ������� �����������\n"; }
			else {
				cout << "������������� �������\n";
				printInformKS(K1);
				cout << "\n";
			}
			break;
		}
		case 4:
		{
			if (idTR == 0) { cout << "����� �����������\n"; }
			else {
				if (TR1.pr == "��") { TR1.pr = "���"; }
				else { TR1.pr = "��"; }
				cout << "������ ����� �������\n";
			}
			break;
		}
		case 5:
		{
			int vybor2;
			if (idKS == 0) { cout << "������������� ������� �����������\n"; }
			else {
				cout << "1. ��������� ���\n2. ���������� ���\n";
				cin >> vybor2;
				vybor2 = proves(vybor2, 2, 1, "1 ��� 2!");
				K1.kolvr = K1.kolvr + RedactKS(vybor2, K1);
			}
		}
		case 6:
		{
			ofstream fout;
			fout.open("file.txt");
			if (idTR == 0) { fout << "����� �����������\n"; }
			else {
				saveinformTRUBAtxt(TR1, fout);
			}
			if (idKS == 0) {
				fout << "\n������������� ������� �����������\n";
			}
			else {
				fout << "\n";
				saveinformKStxt(K1, fout);
			}
			fout.close();
			break;
		}
		case 7:
		{
			idTR = 0; idKS = 0;
			string filename;
			cout << "������� ��� �����: ";
			cin >> filename;
			ifstream myfile(filename);
			if (myfile.is_open())
			{
				TR1 = loadingTR(myfile);
				TR1.id = idTR + 1;
				printInformTRUBA(TR1);
				cout << "\n";
				idTR++;
				myfile.ignore(256, '\n');
				K1 = loadingKS(myfile);
				K1.id = idKS + 1;
				printInformKS(K1);
				cout << "\n";
				idKS++;
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