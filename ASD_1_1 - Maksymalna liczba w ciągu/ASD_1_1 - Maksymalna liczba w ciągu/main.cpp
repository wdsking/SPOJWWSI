#include <iostream>

using namespace std;

int main()
{
	int num;
	int highest=0;
	while (cin >> num)
	{
		if (num == 0) break;
		if (num > highest)
		{
			highest = num;
		}
	}
	cout << highest;
	return 0;
}