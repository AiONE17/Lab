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
	cout << "Введите длину" << endl;
	cin >> TRUBA1.dl;
	cout << "Введите диаметр" << endl;
	cin >> TRUBA1.diam;
	cout << "В ремонте или нет (1-если в ремонте, 2-если в рабочем состоянии)" << endl;
	int n;
	cin >> n;
	if (n == 1) { TRUBA1.pr = "Да"; }
	else if (n == 2) { TRUBA1.pr = "Нет"; }
	else { TRUBA1.pr = "Неизвестно"; };
	return TRUBA1;
}
KS CreateKS()
{
	KS KS1;
	KS1.id = {};
	cout << "Введите название ";
	cin >> KS1.name;
	cout << "Введите количество цехов ";
	cin >> KS1.kol;
	cout << "Введите количество цехов в рабочем состоянии ";
	cin >> KS1.kolvr;
	cout << "Введите эффективность ";
	KS1.effect = 100 * KS1.kolvr / KS1.kol;
	return KS1;
}
void printInformTRUBA(TRUBA truba)
{
	cout << "Идентификатор: " << truba.id << "\n";
	cout << "Длина: " << truba.dl << "\n";
	cout << "Диаметр: " << truba.diam << "\n";
	cout << "В ремонте: " << truba.pr << "\n";
}
void printInformKS(KS ks)
{
	cout << "Идентификатор: " << ks.id << "\n";
	cout << "Название: " << ks.name << "\n";
	cout << "Количество цехов: " << ks.kol << "\n";
	cout << "Количество цехов в рабочем состоянии: " << ks.kolvr << "\n";
	cout << "Эффективность: " << ks.effect << "\n";
}
void print_menu() {
	system("cls");  // очищаем экран
	cout << "Меню\n";
	cout << "1. Добавить трубу\n";
	cout << "2. Добавить КС\n";
	cout << "3. Просмотр всех объектов\n";
	cout << "4. Редактировать трубу\n";
	cout << "5. Редактировать КС\n";
	cout << "6. Сохранить\n";
	cout << "7. Загрузить\n";
	cout << "0. Выход\n";
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
			if (i == 1) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "ТРУБЫ\n";
				for (int n = 1; n < i; n++) {
					printInformTRUBA(TR1[n]);
					cout << "\n";
				}
			}
			if (k == 1) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "КОМПРЕССОРНЫЕ СТАНЦИИ\n";
				for (int n = 1; n < k; n++) {
					printInformKS(K1[n]);
					cout << "\n";
				}
			}
			break;
		}
		case 4:
		{
			if (i == 1) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				int num;
				cout << "Укажите id трубы\n";
				cin >> num;
				if (TR1[num].pr == "Да") { TR1[num].pr = "Нет"; }
				else { TR1[num].pr = "Да"; }
			}
			break;
		}
		case 5:
		{
			if (k == 1) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				int num;
				int mun;
				cout << "Укажите id КС\n";
				cin >> num;
				cout << "Выберите параметр\n" << "1. Название\n" << "2. Количество цехов\n" << "3. Количество цехов в рабочем состоянии\n";
				cin >> mun;
				if (mun == 1) {
					cout << "Введите новое название\n";
					cin >> K1[num].name;
				}
				else if (mun == 2) {
					cout << "Введите новое количество цехов\n";
					cin >> K1[num].kol;
					K1[num].effect = K1[num].kolvr * 100 / K1[num].kol;
				}
				else if (mun == 3)
				{
					cout << "Введите новое количество цехов в рабочем состоянии\n";
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
			if (i == 1) { fout << "ТРУБЫ ОТСУТСТВУЮТ\n";}
			else {
			fout << "ТРУБЫ\n";
				for (int n = 1; n < i; n++) {
					fout << endl;
					fout << "Идентификатор: " << TR1[n].id << "\n";
					fout << "Длина: " << TR1[n].dl << "\n";
					fout << "Диаметр: " << TR1[n].diam << "\n";
					fout << "В ремонте: " << TR1[n].pr << "\n";
				}
			}
			if (k == 1) {
				fout << "\nКОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n";
			}
			else {
				fout << "\n" << "КОМПРЕССОРНЫЕ СТАНЦИИ\n";
				for (int n = 1; n < k; n++) {
					fout<<endl;
					fout << "Идентификатор: " << K1[n].id << "\n";
					fout << "Название: " << K1[n].name << "\n";
					fout << "Количество цехов: " << K1[n].kol << "\n";
					fout << "Количество цехов в рабочем состоянии: " << K1[n].kolvr << "\n";
					fout << "Эффективность: " << K1[n].effect << "\n";
				}
			}
			fout.close();
			break;
		}
		case 7:
		{

			char filename[20];
			int vyb;
			cout << "Выберите\n" << "1. Загрузить трубы\n" << "2. Загрузить компрессорные станции\n";
			cin >> vyb;
			cout << "Введите имя файла: ";
			cin >> filename;
			ifstream myfile(filename, ios::beg);
			if (!myfile)
			{
				cout << "Ошибка при открытии файла.\n";
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
