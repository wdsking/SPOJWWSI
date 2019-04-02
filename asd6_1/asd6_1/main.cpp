#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Pair
{
public:
	Pair();
	~Pair();
	int A;
	int B;
};
Pair::Pair()
{
}
Pair::~Pair()
{
}
class Graph
{
	int VerticiesCount;
	vector<int> *AdjacencyVec;

	void DFS(int v, bool visited[],vector<int> &connectedComponents);
public:
	Graph(int verticiesCount);
	void AddEdge(int v, int w);
	void FindConnectedComponents();
};
void Graph::DFS(int vertex, bool visitedVerticies[], vector<int> &connectedComponents)
{
	visitedVerticies[vertex] = true;
	connectedComponents.push_back(vertex);

	vector<int>::iterator i;
	for (i = AdjacencyVec[vertex].begin(); i != AdjacencyVec[vertex].end(); ++i)
		if (!visitedVerticies[*i])
			DFS(*i, visitedVerticies,connectedComponents);
}



void Graph::AddEdge(int v, int w)
{
	AdjacencyVec[v].push_back(w);
	AdjacencyVec[w].push_back(v);
}
Graph::Graph(int verticiesCount)
{
	this->VerticiesCount = verticiesCount;
	AdjacencyVec = new vector<int>[verticiesCount];
}
void Graph::FindConnectedComponents()
{
	bool *visitedVerticies = new bool[VerticiesCount];
	for (int v = 0; v < VerticiesCount; v++)
		visitedVerticies[v] = false;
	vector<int> connectedComponents;
	int counter = 1;
	for (int v = 1; v < VerticiesCount; v++)
	{
		
		if (visitedVerticies[v] == false)
		{
			cout << counter << ": ";
			counter++;
		
			DFS(v, visitedVerticies,connectedComponents);
			sort(connectedComponents.begin(), connectedComponents.end());
			for (int j = 0; j < connectedComponents.size(); j++)
			{
				cout << connectedComponents[j] << " ";
			}
			cout << "\n";
			connectedComponents.clear();
			
		}
	}
	
}



int main()
{
	
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		vector<Pair> pairs;
		int highestVertexIndex = 0;
		int edgesCount;
		cin >> edgesCount;
		for (int j = 0; j < edgesCount; j++)
		{
			Pair pair;
			int a, b;
			cin >> a >> b;
			pair.A = a;
			pair.B = b;
			pairs.push_back(pair);
			if (a > highestVertexIndex)highestVertexIndex = a;
			if (b > highestVertexIndex)highestVertexIndex = b;
		}
		Graph graph(highestVertexIndex+1);
		for (int j = 0; j < pairs.size(); j++)
		{
			graph.AddEdge(pairs[j].A, pairs[j].B);
		}
		graph.FindConnectedComponents();
	
	

	}
	return 0;
}