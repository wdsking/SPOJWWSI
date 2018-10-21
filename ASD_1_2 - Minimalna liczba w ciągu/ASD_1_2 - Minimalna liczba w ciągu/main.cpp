#include <iostream>

using namespace std;

int main()
{
	int num;
	int lowest = 100;
	int lowestNumberIndex = 0;
	int counter = 0;
	while (cin >> num)
	{
		counter++;
		if (num == 0) break;
		if (num <= lowest)
		{
			lowest = num;
			lowestNumberIndex = counter;
		}
		
	}
	cout << lowest << endl;
	cout << lowestNumberIndex << endl;
	
	return 0;
}