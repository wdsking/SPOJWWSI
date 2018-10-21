#include <iostream>

using namespace std;

int main()
{
	int num;
	int smallest = 500;
	int smallestIndex = 0;
	int biggest = -500;
	int biggestIndex = 0;
	int counter = 0;
	while (cin >> num)
	{
		counter++;
		if (num >= biggest)
		{
			biggest = num;
			biggestIndex = counter;
		}
		if (num < smallest)
		{
			smallest = num;
			smallestIndex = counter;
		}
	}
	cout << smallest << endl << smallestIndex << endl << biggest << endl << biggestIndex;

	return 0;
}