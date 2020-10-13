#include <iostream>
#include <fstream>
#include <string>
//#include <string.h>
using namespace std;
struct KS
{
	int id;
	char name[20];
	int kol;
	int kolvr;
	double effect;
};
struct TRUBA
{
	int id;
	double dl;
	double diam;
	string pr;
};
TRUBA CreateTRUBA()
{
	TRUBA TRUBA1;
	TRUBA1.id = {};
	cout << "������� �����" << endl;
	cin >> TRUBA1.dl;
	cout << "������� �������" << endl;
	cin >> TRUBA1.diam;
	cout << "� ������� ��� ��� (1-���� � �������, 2-���� � ������� ���������)" << endl;
	int n;
	cin >> n;
	if (n == 1) { TRUBA1.pr = "��"; }
	else if (n == 2) { TRUBA1.pr = "���"; }
	else { TRUBA1.pr = "����������"; };
	return TRUBA1;
}
KS CreateKS()
{
	KS KS1;
	KS1.id = {};
	cout << "������� �������� ";
	cin >> KS1.name;
	cout << "������� ���������� ����� ";
	cin >> KS1.kol;
	cout << "������� ���������� ����� � ������� ��������� ";
	cin >> KS1.kolvr;
	cout << "������� ������������� ";
	KS1.effect = 100 * KS1.kolvr / KS1.kol;
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
	cout << "�������������: " << ks.effect << "\n";
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
int get_variant(int count) {
	int variant;
	cin >> variant;
	return variant;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	int i = 1;
	int k = 1;
	const int amount = 1024;
	TRUBA TR1[amount] = {};
	KS K1[amount] = {};
	do {
		print_menu();
		variant = get_variant(7);
		switch (variant) {
		case 1:
		{
			TR1[i] = CreateTRUBA();
			TR1[i].id = i;
			printInformTRUBA(TR1[i]);
			i++;
			break;
		}
		case 2:
		{
			K1[k] = CreateKS();
			K1[k].id = k;
			printInformKS(K1[k]);
			k++;
			break;
		}
		case 3:
		{
			if (i == 1) { cout << "����� �����������\n"; }
			else {
				cout << "�����\n";
				for (int n = 1; n < i; n++) {
					printInformTRUBA(TR1[n]);
					cout << "\n";
				}
			}
			if (k == 1) { cout << "������������� ������� �����������\n"; }
			else {
				cout << "������������� �������\n";
				for (int n = 1; n < k; n++) {
					printInformKS(K1[n]);
					cout << "\n";
				}
			}
			break;
		}
		case 4:
		{
			if (i == 1) { cout << "����� �����������\n"; }
			else {
				int num;
				cout << "������� id �����\n";
				cin >> num;
				if (TR1[num].pr == "��") { TR1[num].pr = "���"; }
				else { TR1[num].pr = "��"; }
			}
			break;
		}
		case 5:
		{
			if (k == 1) { cout << "������������� ������� �����������\n"; }
			else {
				int num;
				int mun;
				cout << "������� id ��\n";
				cin >> num;
				cout << "�������� ��������\n" << "1. ��������\n" << "2. ���������� �����\n" << "3. ���������� ����� � ������� ���������\n";
				cin >> mun;
				if (mun == 1) {
					cout << "������� ����� ��������\n";
					cin >> K1[num].name;
				}
				else if (mun == 2) {
					cout << "������� ����� ���������� �����\n";
					cin >> K1[num].kol;
					K1[num].effect = K1[num].kolvr * 100 / K1[num].kol;
				}
				else if (mun == 3)
				{
					cout << "������� ����� ���������� ����� � ������� ���������\n";
					cin >> K1[num].kolvr;
					K1[num].effect = K1[num].kolvr * 100 / K1[num].kol;
				}
			}
			break;
		}
		case 6:
		{
			ofstream fout;
			fout.open("file.txt");
			if (i == 1) { fout << "����� �����������\n";}
			else {
			fout << "�����\n";
				for (int n = 1; n < i; n++) {
					fout << endl;
					fout << "�������������: " << TR1[n].id << "\n";
					fout << "�����: " << TR1[n].dl << "\n";
					fout << "�������: " << TR1[n].diam << "\n";
					fout << "� �������: " << TR1[n].pr << "\n";
				}
			}
			if (k == 1) {
				fout << "\n������������� ������� �����������\n";
			}
			else {
				fout << "\n" << "������������� �������\n";
				for (int n = 1; n < k; n++) {
					fout<<endl;
					fout << "�������������: " << K1[n].id << "\n";
					fout << "��������: " << K1[n].name << "\n";
					fout << "���������� �����: " << K1[n].kol << "\n";
					fout << "���������� ����� � ������� ���������: " << K1[n].kolvr << "\n";
					fout << "�������������: " << K1[n].effect << "\n";
				}
			}
			fout.close();
			break;
		}
		case 7:
		{

			char filename[20];
			int vyb;
			cout << "��������\n" << "1. ��������� �����\n" << "2. ��������� ������������� �������\n";
			cin >> vyb;
			cout << "������� ��� �����: ";
			cin >> filename;
			ifstream myfile(filename, ios::beg);
			if (!myfile)
			{
				cout << "������ ��� �������� �����.\n";
				return 1;
			}
			int p;
			if (vyb == 1) {
				for (p = i; myfile; p++)
				{
					myfile >> TR1[p].id;
					myfile >> TR1[p].dl;
					myfile >> TR1[p].diam;
					myfile >> TR1[p].pr;
				}
			}
			else {
				for (p = k; myfile; p++)
				{
					myfile >> K1[p].id;
					myfile >> K1[p].name;
					myfile >> K1[p].kol;
					myfile >> K1[p].kolvr;
					myfile >> K1[p].effect;
				}
			}
			myfile.close();
			if (vyb == 1) {
				for (int n = i; n < p - 1; n++) {
					printInformTRUBA(TR1[n]);
					cout << "\n";
					i++;
				}

			}
			else {
				for (int n = k; n < p - 1; n++) {
					printInformKS(K1[n]);
					k++;
				}

			}
			break;
		}
		return 0;
		}
		if (variant != 0)
			system("pause");
	} while (variant != 0);
	return 0;
}
