#include <iostream>
#include <fstream>
#include <vector>
#include "TRUBA.h"
#include "KS.h"
#include "utils.h"
using namespace std;
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
	if (truba.pr == "Да") truba.pr = "Нет";
	else truba.pr = "Да";
	cout << "Статус трубы изменен";
}
void EDITKS(KS& ks)
{
	cout << "1. Запустить цех\n2. Остановить цех\n";
		int vyb = proves(2, 1, "1 ИЛИ 2!");
		if (vyb == 1) {
			if (ks.kolvr == ks.kol) cout << "Все цехи находятся в рабочем состоянии\n"; 
			else ks.kolvr = ks.kolvr + 1;
		}
		else {
			if (ks.kolvr == 0)  cout << "Нет рабочих цехов\n"; 
			else ks.kolvr = ks.kolvr - 1;
		}
}
TRUBA& SelectTRUBA(vector<TRUBA>&g)
{
	cout << "Введите id\n";
	int index = proves(g.size(), 1, "Нет трубы с таким id\n");
	return g[index-1];
}
KS& SelectKS(vector<KS>&g)
{
	cout << "Введите id\n";
	int index = proves(g.size(), 1, "Нет компрессорной станции с таким id");
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
		variant = proves(7, 0, "Действие выбрано некорректно, выберите повторно\n");
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
			if (TRUBAS.size() == 0) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "ТРУБЫ\n";
				for (TRUBA TR1 : TRUBAS)
					cout << TR1 << endl;
			}
			if (KSS.size() == 0) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
			else {
				cout << "КОМПРЕССОРНЫЕ СТАНЦИИ\n";
				for (KS K1 : KSS)
					cout << K1 << endl;
			}
			break;
		}
		case 4:
		{
			if (TRUBAS.size() == 0) { cout << "ТРУБЫ ОТСУТСТВУЮТ\n"; }
			else {
				EDITRUBA(SelectTRUBA(TRUBAS));
			}
			break;
		}
		case 5:
		{
			if (KSS.size() == 0) { cout << "КОМПРЕССОРНЫЕ СТАНЦИИ ОТСУТСТВУЮТ\n"; }
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