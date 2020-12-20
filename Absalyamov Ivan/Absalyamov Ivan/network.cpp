#include "NETWORK.h"
#include <iostream>
#include <unordered_map>
using namespace std;
void network::CreateMatrix(unordered_map<int, TRUBA>& trubas, unordered_map<int, KS>& kss) 
{
	int n = kss.size();
	WeightsMatrix.clear();
	WeightsMatrix.resize(n);
	for (int i = 0; i < n; i++)
			WeightsMatrix[i].resize(n);
	for (auto it = trubas.begin(); it != trubas.end(); it++) {
		int k = it->second.GetVyhod();
		int l = it->second.GetVhod();
		if (l < kss.size() + 1 && l > 0 && k > 0 && k < kss.size() + 1)
		{
			WeightsMatrix[k - 1][l - 1] = it->second.GetDL();
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << WeightsMatrix[i][j] << " ";
		}
		cout << endl;
	}
}
void network::TopSort()
{
	int i, j, k, count = 0;
	int n = WeightsMatrix.size();
	vector<int >indeg(n);
	vector<int >flag(n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (WeightsMatrix[i][j] != 0)
				WeightsMatrix[i][j] = 1;
	
}