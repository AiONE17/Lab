#pragma once
#include "TRUBA.h"
#include "KS.h"
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
#include <limits.h>
#include <string.h>
#include <iostream>

class network
{
    int V;
    list<int>* adj;
    vector<vector<int>>WeightsMatrix;
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);
    bool isCyclicUtil(int v, bool visited[], bool* recStack);
    bool bfs(vector<vector<int>>graph, int s, int t,int parent[]);
    void printSolution(int dist[]);
    int minDistance(int dist[], bool sptSet[]);
public:
    void CreateMatrix(unordered_map<int, TRUBA>& trubas, unordered_map<int, KS>& kss);
    void TopSort();
    bool isCyclic();
    int fordFulkerson(int s, int t);
    void dijkstra(int src);
};

