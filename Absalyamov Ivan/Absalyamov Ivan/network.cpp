#include "NETWORK.h"
#include <iostream>
#include <unordered_map>
using namespace std;
void network::CreateMatrix(unordered_map<int, TRUBA>& trubas, unordered_map<int, KS>& kss) 
{
	int n = kss.size();
	WeightsMatrix.clear();
	WeightsMatrix.resize(n);
	adj = new list<int>[n];
	for (int i = 0; i < n; i++)
			WeightsMatrix[i].resize(n);
	for (auto it = trubas.begin(); it != trubas.end(); it++) {
		int k = it->second.GetVyhod();
		int l = it->second.GetVhod();
		if (l < kss.size() + 1 && l > 0 && k > 0 && k < kss.size() + 1)
		{
			WeightsMatrix[k - 1][l - 1] = it->second.GetDL();
			adj[k-1].push_back(l-1);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << WeightsMatrix[i][j] << " ";
		}
		cout << endl;
	}
}
void network::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);
	Stack.push(v);
}
bool network::isCyclicUtil(int v,bool visited[], int parent)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i !=
		adj[v].end(); ++i)
	{
		if (!visited[*i])
		{
			if (isCyclicUtil(*i, visited, v))
				return true;
		}
		else if (*i != parent)
			return true;
	}
	return false;
}
bool network::isCyclic()
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int u = 0; u < V; u++)
	{
		if (!visited[u])
			if (isCyclicUtil(u, visited, -1))
				return true;
	}
	return false;
}
void network::TopSort()
{
	int V = WeightsMatrix.size();
	stack<int> Stack;
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}
bool network::bfs(vector<vector<int>>rGraph, int s, int t, int parent[]) {
	bool* visited=new bool[V];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}
	return (visited[t] == true);
}
int network::fordFulkerson(int s, int t) {
	int u, v;
	vector<vector<int>>rGraph(V);
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = WeightsMatrix[u][v];
	int* parent=new int[V];
	int max_flow = 0;
	while (bfs(rGraph, s, t, parent)) {
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}
int network::minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void network::printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}
void network::dijkstra(vector<vector<int>>graph, int src)
{
	int* dist=new int[V]; // The output array.  dist[i] ill hold the shortest 
	bool* sptSet=new bool[V]; // sptSet[i] will be true if vertex i is included in shortest 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false; 
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) { 
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}

