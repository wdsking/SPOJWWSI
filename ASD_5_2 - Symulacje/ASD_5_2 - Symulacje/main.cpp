#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColumns(vector<vector<double>>& matrix, vector<int> cols) {

		sort(matrix.begin(),
			matrix.end(),
			[cols](const vector<double>& lhs, const vector<double>& rhs) {			
			short first = cols[2], second = cols[1], third = cols[0];

			if (lhs[first] == rhs[first])
				if (lhs[second] == rhs[second])
					return lhs[third] < rhs[third];
				else return lhs[second] < rhs[second];
			else return lhs[first] < rhs[first];
				
		});
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	vector<int> indexesOfColumnsToSort;
	vector<vector<double>> matrix;
	int columns;
	cin >> columns;
	int numberOfColumnsToSort;
	cin >> numberOfColumnsToSort;
	for (int i = 0; i < numberOfColumnsToSort; i++)
	{
		int num;
		cin >> num;
		indexesOfColumnsToSort.push_back(num-1);
	}
	int counter = 0;
	double number;
	vector<double> row;
	while (cin >> number)
	{
		row.push_back(number);
		counter++;
		if (counter % columns == 0) 
		{
			matrix.push_back(row);
			row.clear();
		}
	}
	for (int i = 0; i < numberOfColumnsToSort; i++)
	{
		sortColumns(matrix, indexesOfColumnsToSort);

	}
	
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}