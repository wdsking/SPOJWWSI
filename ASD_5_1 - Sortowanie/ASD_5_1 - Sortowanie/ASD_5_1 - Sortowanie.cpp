#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	vector<int> numbers;
	int number;
	while (cin >> number)
	{
		numbers.push_back(number);
	}
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); ++i)
	{
		cout << numbers[i] << "\n";
	}
	return 0;
}
