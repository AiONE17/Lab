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
float proves(float vv,float k, int k1, int k2, string s) {             //float, чтобы проверка работала и для эффективности
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
	cout << "Введите длину" << endl;
	cin >> dll;
	TRUBA1.dl = proves(dll,dll, 5000000, 0, "Длина должна быть целым положительным числом\n");
	cout << "Введите диаметр" << endl;
	cin >> diamm;
	TRUBA1.diam = proves(diamm,diamm, 5000000, 0, "Диаметр должен быть целым положительным числом\n");
	cout << "В ремонте или нет (1-если в ремонте, 2-если в рабочем состоянии)" << endl;
	float n;
	cin >> n;
	n = proves(n,n, 2, 1, "1 или 2!!!\n");
	if (n == 1) { TRUBA1.pr = "Да"; }
	else if (n == 2) { TRUBA1.pr = "Нет"; }
	return TRUBA1;
}
KS CreateKS()
{
	KS KS1;
	double koll;
	double kollvr;
	KS1.id = {};
	cout << "Введите название " << endl;
	cin >> KS1.name;
	cout << "Введите количество цехов "<< endl;
	cin >> koll;
	KS1.kol = proves(koll,koll,500000,0, "Количество цехов должно быть целым неотрицательным числом\n");
	cout << "Введите количество цехов в рабочем состоянии " << endl;
	cin >> kollvr;
	KS1.kolvr = proves(kollvr,kollvr,koll,0,"Некорретное количество цехов в работе\n");
	cout << "Введите эффективность " << endl;
	cin >> KS1.effect;
	KS1.effect = proves(0, KS1.effect, 100, 0, "Некорректная эффективность (от 0 до 100)\n");
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
	cout << "Эффективность: " << round(ks.effect*100)/100 <<" %"<< "\n";
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
		variant = proves(vv,vv,7,0, "Действие выбрано некорректно, выберите повторно\n");
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
			if (i == 1) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "ТРУБЫ\n";
				for (int n = 0; n < i-1; n++) {
					printInformTRUBA(TR1[n]);
					cout << "\n";
				}
			}
			if (j == 1) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "КОМПРЕССОРНЫЕ СТАНЦИИ\n";
				for (int n = 0; n < j-1; n++) {
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
				float numm;
				int num;
				cout << "Укажите id трубы\n";
				cin >> numm;
				num = proves(numm,numm, i - 1, 1, "Нет ТРУБЫ с таким id\n");
				if (TR1[num-1].pr == "Да") { TR1[num-1].pr = "Нет"; }
				else { TR1[num-1].pr = "Да"; }
				cout << "Статус трубы изменен\n";
			}
			break;
		}
		case 5:
		{
			if (j == 1) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				float numm;
				float munn;
				int num;
				int mun;
				cout << "Укажите id КС\n";
				cin >> numm;
				num = proves(numm, numm, j-1, 1, "Нет КС с таким id\n");
				cout << "Выберите параметр\n" << "1. Название\n" << "2. Количество цехов\n"<<"3. Эффективность\n";
				cin >> munn;
				mun = proves(munn, munn, 3, 1, "ОТ 1 ДО 3!!!\n");
				if (mun == 1) {
					cout << "Введите новое название\n";
					cin >> K1[num-1].name;
				}
				else if (mun == 2) {
					float koll;
					float kollvr;
					cout << "Введите новое количество цехов " << endl;
					cin >> koll;
					K1[num-1].kol = proves(koll,koll, 500000, 0, "Количество цехов должно быть целым неотрицательным числом\n");
					cout << "Введите новое количество цехов в рабочем состоянии " << endl;
					cin >> kollvr;
					K1[num-1].kolvr = proves(kollvr, kollvr, koll, 0, "Некорретное количество цехов в работе\n");
				}
				else {
					float eeffect;
					cout << "Введите новую эффективность\n";
					cin >> eeffect;
					K1[num - 1].effect = proves(0, eeffect, 100, 0, "Эффективность может иметь значение от 0 до 100");
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
				for (int n = 0; n < i-1; n++) {
					fout << endl;
					fout << "Идентификатор: " << TR1[n].id << "\n";
					fout << "Длина: " << TR1[n].dl << "\n";
					fout << "Диаметр: " << TR1[n].diam << "\n";
					fout << "В ремонте: " << TR1[n].pr << "\n";
				}
			}
			if (j == 1) {
				fout << "\nКОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n";
			}
			else {
				fout << "\n" << "КОМПРЕССОРНЫЕ СТАНЦИИ\n";
				for (int n = 0; n < j-1; n++) {
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
			string filename;
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
					if ((dll - floor(dll)) || cin.fail()) { cout << "ОБРАТИТЕ ВНИМАНИЕ : Длина должна быть целым числом. ИЗМЕНИТЕ ФАЙЛОВЫЕ ВХОДНЫЕ ДАННЫЕ\n"; TR1[i - 1].dl = 0;}
					else { TR1[i - 1].dl =(int)dll; }
					if ((diamm - floor(diamm)) || cin.fail()) { cout << "ОБРАТИТЕ ВНИМАНИЕ : Диаметр должен быть целым числом. ИЗМЕНИТЕ ФАЙЛОВЫЕ ВХОДНЫЕ ДАННЫЕ\n"; TR1[i - 1].diam=0; }
					else { TR1[i - 1].diam = (int)diamm; }
					if ((prr != 1) && (prr != 2)) { cout << "ОБРАТИТЕ ВНИМАНИЕ : 1 - в ремонте, 2 - в рабочем состоянии. ИЗМЕНИТЕ ФАЙЛОВЫЕ ВХОДНЫЕ ДАННЫЕ\n"; TR1[i - 1].pr = "Неизвестно";	}
      				else if (prr == 2) { TR1[i - 1].pr = "Нет"; }
					else { TR1[i - 1].pr = "Да"; }
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
					if ((koll - floor(koll)) || cin.fail()) { cout << "ОБРАТИТЕ ВНИМАНИЕ : Количество цехов должно быть целым числом. ИЗМЕНИТЕ ФАЙЛОВЫЕ ВХОДНЫЕ ДАННЫЕ\n"; K1[j - 1].kol = 0; }
					else { K1[j - 1].kol = (int)koll; }
					if ((kollvr - floor(kollvr)) || (cin.fail())||(kollvr>koll)) { cout << "ОБРАТИТЕ ВНИМАНИЕ : Количество цехов должно быть целым числом и <= общего количества цехов. ИЗМЕНИТЕ ФАЙЛОВЫЕ ВХОДНЫЕ ДАННЫЕ\n"; K1[j - 1].kolvr = 0; }
					else { K1[j - 1].kolvr = (int)kollvr; }
					if ((eeffect>100)||(eeffect<0) || cin.fail()) { cout << "ОБРАТИТЕ ВНИМАНИЕ : Эффективность может иметь значения от 0 до 100. ИЗМЕНИТЕ ФАЙЛОВЫЕ ВХОДНЫЕ ДАННЫЕ\n"; K1[j - 1].effect = 0; }
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
