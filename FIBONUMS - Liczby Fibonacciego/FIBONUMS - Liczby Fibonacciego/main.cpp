#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<unsigned long long, unsigned long long> Fib;
unsigned long long fib(unsigned long long n)
{
	if (n < 2) return 1;
	if (Fib.find(n) != Fib.end()) return Fib[n];
	Fib[n] = (fib((n + 1) / 2)*fib(n / 2) + fib((n - 1) / 2)*fib((n - 2) / 2)) % 1000000007;
	return Fib[n];
}
int main()
{
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; ++i)
	{
		unsigned long long Ni;
		cin >> Ni;
		cout << fib(Ni-1)<< "\n";
	}
	return 0;
}