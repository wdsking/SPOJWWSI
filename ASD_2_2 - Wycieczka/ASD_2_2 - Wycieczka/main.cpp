#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > GetMatrix(int rows, int columns)
{
	vector<vector<int> > matrix;
	for (int i = 0; i < rows; i++)
	{
		vector<int> row;
		for (int j = 0; j < columns; j++)
		{
			
			row.push_back(0);
		}
		matrix.push_back(row);
	}
	return matrix;
}

vector<vector<int> > Multiply(vector<vector<int> > A, vector<vector<int> > B, int rows, int columns)
{
	vector<vector<int> > C;


	for (int i = 0; i < columns; i++)
	{
		vector<int> row;

		for (int j = 0; j < columns; j++)
		{
			int sum = 0;
			for (int k = 0; k < rows; k++)
			{
				sum += A[i][k] * B[k][j];

			}
			row.push_back(sum);
		}
		C.push_back(row);
	}
	return C;
}
void Display(vector<vector<int> > matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
			if (j == columns - 1)
			{
				cout << "\n";
			}
		}
	}
}
bool isTransitive(vector<vector<int> > matrix,vector<vector<int> > matrixSquared, int highest)
{
	for (int x = 0; x < highest; x++)
	{
		for (int y = 0; y < highest; y++)
		{
			if (matrixSquared[x][y] == 1 && matrix[x][y] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int highest = 0;
	int a, b;
	vector<vector<int> > matrix = GetMatrix(101, 101);
	while (cin >> a >> b)
	{
		matrix[a][b] = 1;
		if (a > highest)
		{
			highest = a;
		}
		if (b > highest)
		{
			highest = b;
		}

		
	}
	vector<vector<int> > matrixSquared = Multiply(matrix, matrix, highest, highest);
	if (isTransitive(matrix, matrixSquared,highest))
	{
		cout << "TAK";
	}
	else cout << "NIE";
	
	return 0;
}