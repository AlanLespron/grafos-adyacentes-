#include <bits/stdc++.h>
using namespace std;

class Graph {

	int vertex;
	int edges;
	int** adjecent;

public:
	Graph(int vertex, int edges);
	void addEdge(int start, int edges);
	void DFS(int start, vector<bool>& visited);
};

Graph::Graph(int vertex, int edges)
{
	this->vertex = vertex;
	this->edges = edges;
	adjecent = new int*[vertex];
	for (int row = 0; row < vertex; row++) {
		adjecent[row] = new int[vertex];
		for (int column = 0; column < vertex; column++) {
			adjecent[row][column] = 0;
		}
	}
}


void Graph::addEdge(int start, int edges)
{
	adjecent[start][edges] = 1;
	adjecent[edges][start] = 1;
}


void Graph::DFS(int start, vector<bool>& visited)
{
	cout << start << " ";
	visited[start] = true;

	for (int i = 0; i < vertex; i++) {
		if (adjecent[start][i] == 1 && (!visited[i])) {
			DFS(i, visited);
		}
	}
}

int main()
{
	int vertex = 5, edges = 4;

	Graph G(vertex, edges);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(0, 3);
	G.addEdge(0, 4);

	vector<bool> visited(vertex, false);

	G.DFS(0, visited);
}