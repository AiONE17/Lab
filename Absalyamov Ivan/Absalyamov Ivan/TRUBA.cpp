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
	cout << "Введите название" << endl;
	in >> truba.name;
	cout << "Введите длину" << endl;
	truba.dl = proves(5000000, 0, "Длина должна быть целым положительным числом\n");
	cout << "Введите диаметр" << endl;
	truba.diam = proves(5000000, 0,"Диаметр должен быть целым положительным числом\n");
	cout << "В ремонте или нет (1-если в ремонте, 2-если в рабочем состоянии)" << endl;
	vybor1 = proves(2, 1, "1 или 2!!!\n");
	if (vybor1 == 1) { truba.pr = "Yes"; }
	else if (vybor1 == 2) { truba.pr = "No"; }
	return in;
}
ostream& operator << (ostream& out, const TRUBA& truba)
{
	out << "Идентификатор: " << truba.id<<endl;
	out << "Название: " << truba.name << endl;
	out << "Длина: " << truba.dl << "\n";
	out << "Диаметр: " << truba.diam << "\n";
	out << "В ремонте: " << truba.pr << "\n";
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
	if (truba.pr == "Да") truba.pr = "Нет";
	else truba.pr = "Да";
	cout << "Статус трубы изменен";
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

