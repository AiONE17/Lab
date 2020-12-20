#pragma once
#include "TRUBA.h"
#include "KS.h"
#include <unordered_map>

class network
{
    vector<vector<int>>WeightsMatrix;
public:
    void CreateMatrix(unordered_map<int, TRUBA>& trubas, unordered_map<int, KS>& kss);
    void TopSort();
};

