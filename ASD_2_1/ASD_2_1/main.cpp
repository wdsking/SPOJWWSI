#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> GetMoveVectors(int rows, int columns)
{
	vector<vector<int>> matrix;
	for (int i = 0; i < rows; i++)
	{
		vector<int> row;
		for (int j = 0; j < columns; j++)
		{
			int num;
			cin >> num;
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	return matrix;
}
vector<int> GetStartVector(int elements)
{
	vector<int> startV;
	for (int i = 0; i < elements; i++)
	{
	
		startV.push_back(0);
	}
	return startV;
}
void AddToVector(vector<int> &a, vector<int> b)
{

	for (int i = 0; i < a.size(); i++)
	{
		a[i] += b[i];
	}
}
void Display(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
bool isPerpendicular(vector<int> a, vector<int> b)
{
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		sum += a[i] * b[i];
	}
	if (sum == 0) return true; else return false;
}
bool isZero(vector<int> a)
{
	int counter = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 0) counter++;
	}
	if(counter == a.size())return true; else return false;
	
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n;
		cin >> m;
		cin >> n;
		
		vector<vector<int>> moveVectors = GetMoveVectors(n, m);
		vector<int> actualPosition = moveVectors[0];
		vector<int> goodVector = moveVectors[0];
		for (int a = 1; a < moveVectors.size(); a++)
		{
			if (isZero(moveVectors[a]))continue;
			if (isPerpendicular(goodVector, moveVectors[a]))
			{
				AddToVector(actualPosition, moveVectors[a]);
				goodVector = moveVectors[a];
			}
		}
		Display(actualPosition);
		
		
	}
	return 0;
}