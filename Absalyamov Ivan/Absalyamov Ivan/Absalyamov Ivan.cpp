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
float proves(float vv,float k, int k1, int k2, string s) {             //float, ����� �������� �������� � ��� �������������
	while (cin.fail() || (vv - floor(vv)) || (k > k1) || (k < k2))
	{
		cout << s;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> vv;
		k = vv;
	}
	return k;
};
TRUBA CreateTRUBA()
{
	TRUBA TRUBA1;
	double dll;
	double diamm;
	TRUBA1.id = {};
	cout << "������� �����" << endl;
	cin >> dll;
	TRUBA1.dl = proves(dll,dll, 5000000, 0, "����� ������ ���� ����� ������������� ������\n");
	cout << "������� �������" << endl;
	cin >> diamm;
	TRUBA1.diam = proves(diamm,diamm, 5000000, 0, "������� ������ ���� ����� ������������� ������\n");
	cout << "� ������� ��� ��� (1-���� � �������, 2-���� � ������� ���������)" << endl;
	float n;
	cin >> n;
	n = proves(n,n, 2, 1, "1 ��� 2!!!\n");
	if (n == 1) { TRUBA1.pr = "��"; }
	else if (n == 2) { TRUBA1.pr = "���"; }
	return TRUBA1;
}
KS CreateKS()
{
	KS KS1;
	double koll;
	double kollvr;
	KS1.id = {};
	cout << "������� �������� " << endl;
	cin >> KS1.name;
	cout << "������� ���������� ����� "<< endl;
	cin >> koll;
	KS1.kol = proves(koll,koll,500000,0, "���������� ����� ������ ���� ����� ��������������� ������\n");
	cout << "������� ���������� ����� � ������� ��������� " << endl;
	cin >> kollvr;
	KS1.kolvr = proves(kollvr,kollvr,koll,0,"����������� ���������� ����� � ������\n");
	cout << "������� ������������� " << endl;
	cin >> KS1.effect;
	KS1.effect = proves(0, KS1.effect, 100, 0, "������������ ������������� (�� 0 �� 100)\n");
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
	cout << "�������������: " << round(ks.effect*100)/100 <<" %"<< "\n";
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

int main()
{
	setlocale(LC_ALL, "Russian");
	int variant;
	float vv;
	vector <KS> K1;
	vector <TRUBA> TR1;
	size_t j = 1;
	size_t i = 1;
	K1.resize(j);
	TR1.resize(i);
	do {
		print_menu();
		cin >> vv;
		variant = proves(vv,vv,7,0, "�������� ������� �����������, �������� ��������\n");
		switch (variant) {
		case 1:
		{
			TR1[i - 1] = CreateTRUBA();
			TR1[i - 1].id = i;
			printInformTRUBA(TR1[i - 1]);
			i++;
			TR1.resize(i);
			break;
		}
		case 2:
		{
			K1[j - 1] = CreateKS();
			K1[j - 1].id = j;
			printInformKS(K1[j - 1]);
			j++;
			K1.resize(j);
			break;
		}
		case 3:
		{
			if (i == 1) { cout << "����� �����������\n"; }
			else {
				cout << "�����\n";
				for (int n = 0; n < i-1; n++) {
					printInformTRUBA(TR1[n]);
					cout << "\n";
				}
			}
			if (j == 1) { cout << "������������� ������� �����������\n"; }
			else {
				cout << "������������� �������\n";
				for (int n = 0; n < j-1; n++) {
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
				float numm;
				int num;
				cout << "������� id �����\n";
				cin >> numm;
				num = proves(numm,numm, i - 1, 1, "��� ����� � ����� id\n");
				if (TR1[num-1].pr == "��") { TR1[num-1].pr = "���"; }
				else { TR1[num-1].pr = "��"; }
				cout << "������ ����� �������\n";
			}
			break;
		}
		case 5:
		{
			if (j == 1) { cout << "������������� ������� �����������\n"; }
			else {
				float numm;
				float munn;
				int num;
				int mun;
				cout << "������� id ��\n";
				cin >> numm;
				num = proves(numm, numm, j-1, 1, "��� �� � ����� id\n");
				cout << "�������� ��������\n" << "1. ��������\n" << "2. ���������� �����\n"<<"3. �������������\n";
				cin >> munn;
				mun = proves(munn, munn, 3, 1, "�� 1 �� 3!!!\n");
				if (mun == 1) {
					cout << "������� ����� ��������\n";
					cin >> K1[num-1].name;
				}
				else if (mun == 2) {
					float koll;
					float kollvr;
					cout << "������� ����� ���������� ����� " << endl;
					cin >> koll;
					K1[num-1].kol = proves(koll,koll, 500000, 0, "���������� ����� ������ ���� ����� ��������������� ������\n");
					cout << "������� ����� ���������� ����� � ������� ��������� " << endl;
					cin >> kollvr;
					K1[num-1].kolvr = proves(kollvr, kollvr, koll, 0, "����������� ���������� ����� � ������\n");
				}
				else {
					float eeffect;
					cout << "������� ����� �������������\n";
					cin >> eeffect;
					K1[num - 1].effect = proves(0, eeffect, 100, 0, "������������� ����� ����� �������� �� 0 �� 100");
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
				for (int n = 0; n < i-1; n++) {
					fout << endl;
					fout << "�������������: " << TR1[n].id << "\n";
					fout << "�����: " << TR1[n].dl << "\n";
					fout << "�������: " << TR1[n].diam << "\n";
					fout << "� �������: " << TR1[n].pr << "\n";
				}
			}
			if (j == 1) {
				fout << "\n������������� ������� �����������\n";
			}
			else {
				fout << "\n" << "������������� �������\n";
				for (int n = 0; n < j-1; n++) {
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
			string filename;
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
			if (vyb == 1) {
				while (!myfile.eof())
				{
					float dll=0;
					float diamm=0;
					float prr=0;
					TR1[i - 1].id = i;
					myfile >> dll;
					myfile >> diamm;
					myfile >> prr;
					if ((dll - floor(dll)) || cin.fail()) { cout << "�������� �������� : ����� ������ ���� ����� ������. �������� �������� ������� ������\n"; TR1[i - 1].dl = 0;}
					else { TR1[i - 1].dl =(int)dll; }
					if ((diamm - floor(diamm)) || cin.fail()) { cout << "�������� �������� : ������� ������ ���� ����� ������. �������� �������� ������� ������\n"; TR1[i - 1].diam=0; }
					else { TR1[i - 1].diam = (int)diamm; }
					if ((prr != 1) && (prr != 2)) { cout << "�������� �������� : 1 - � �������, 2 - � ������� ���������. �������� �������� ������� ������\n"; TR1[i - 1].pr = "����������";	}
      				else if (prr == 2) { TR1[i - 1].pr = "���"; }
					else { TR1[i - 1].pr = "��"; }
					printInformTRUBA(TR1[i-1]);
					cout << "\n";
					i++;
					TR1.resize(i);
				}
			}
			else {
				while (!myfile.eof())
				{
					float koll=0;
					float kollvr=0;
					float eeffect=0;
				    K1[j-1].id = j;
					myfile >> K1[j-1].name;
					myfile >> koll;
					myfile >> kollvr;
					myfile >> eeffect;
					if ((koll - floor(koll)) || cin.fail()) { cout << "�������� �������� : ���������� ����� ������ ���� ����� ������. �������� �������� ������� ������\n"; K1[j - 1].kol = 0; }
					else { K1[j - 1].kol = (int)koll; }
					if ((kollvr - floor(kollvr)) || (cin.fail())||(kollvr>koll)) { cout << "�������� �������� : ���������� ����� ������ ���� ����� ������ � <= ������ ���������� �����. �������� �������� ������� ������\n"; K1[j - 1].kolvr = 0; }
					else { K1[j - 1].kolvr = (int)kollvr; }
					if ((eeffect>100)||(eeffect<0) || cin.fail()) { cout << "�������� �������� : ������������� ����� ����� �������� �� 0 �� 100. �������� �������� ������� ������\n"; K1[j - 1].effect = 0; }
					else { K1[j - 1].effect = eeffect; }
					printInformKS(K1[j - 1]);
					cout << "\n";
					j++;
					K1.resize(j);
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
