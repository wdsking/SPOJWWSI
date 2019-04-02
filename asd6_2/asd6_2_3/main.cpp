#include <iostream>
#include <limits.h>
#define SIZE 101

using namespace std;
void FloydWarshallAlgorithm(int** matrix, int size)
{
	int** costs = new int*[size];
	for (int i = 0; i < size; i++)
	{
		costs[i] = new int[size] {1};
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			costs[i][j] = INT_MAX;
			
		}
		costs[i][i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 1)
			{
				costs[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if ((costs[j][i] == INT_MAX) || costs[i][k] == INT_MAX) continue;
				int w = costs[j][i] + costs[i][k];
				if (costs[j][k] > w) costs[j][k] = w;

				
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (costs[i][j] == INT_MAX)
				cout << "NaN" << " ";
			else
			cout << costs[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{

	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		int** matrix = new int*[SIZE];
		for (int j = 0; j < SIZE; j++)
		{
			matrix[j] = new int[SIZE] {0};
		}
		
		int verticiesCount = 0;
		int edgesCount;
		cin >> edgesCount;
		
		for (int j = 0; j < edgesCount; j++)
		{
			int a, b;
			cin >> a >> b;
			if (a > verticiesCount) verticiesCount = a;
			if (b > verticiesCount) verticiesCount = b;			
			matrix[a - 1][b - 1] = 1;
			matrix[b - 1][a - 1] = 1;
		}						
		FloydWarshallAlgorithm(matrix, verticiesCount);				
	}
	return 0;
}