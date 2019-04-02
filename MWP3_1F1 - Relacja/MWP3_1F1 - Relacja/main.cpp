#include <iostream>
#include <vector>
using namespace std;
class Pair
{
public:
	int a, b;
};
bool zwrotna(int **R, int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (R[i][i] == 0) return 0;
	return 1;
}

bool przeciwzwrotna(int **R, int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (R[i][i]) return 0;
	return 1;
}

bool przechodnia(int **R, int n)
{
	int i, j, k;
	int B;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++)
	{
		B = 0;
		for (k = 0; (!B) && (k < n); k++) B = R[i][k] && R[k][j];
		if (R[i][j] < B) return 0;
	}
	return 1;
}
bool spojna(int **R, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{

		for (j = i + 1; j < n; j++)
		{
			if (!(R[i][j] || R[j][i])) return 0;
		}
	}
	return 1;
}
bool symetryczna(int **R, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (R[i][j] != R[j][i]) return 0;
	return 1;
}
bool antysymetryczna(int **R, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (R[i][j] && R[j][i]) return 0;
	return 1;
}
int main()
{
	int a, b;
	int highest = 0;
	vector<Pair> pairs;
	while (cin >> a >> b)
	{
		if (a > highest)highest = a;
		if (b > highest)highest = b;
		Pair p;
		p.a = a;
		p.b = b;
		pairs.push_back(p);

	}

	int **matrix = new int *[highest+1];
	for (int i = 0; i < highest + 1; i++)
		matrix[i] = new int[highest + 1];

	for (int i = 0; i < pairs.size(); i++)
	{
		Pair p = pairs[i];
		matrix[p.a - 1][p.b - 1] = 1;
	}

	bool zw = zwrotna(matrix, highest);
	bool pz = przeciwzwrotna(matrix, highest);
	bool s = spojna(matrix, highest);
	bool sym = symetryczna(matrix, highest);
	bool asym = antysymetryczna(matrix, highest);
	bool p = przechodnia(matrix, highest);
	bool rr = zw + sym + p;
	bool rpl = zw + asym + p + s;
	bool rpcz = zw + asym + p;
	if (zw) cout << "Z ";
	if (pz) cout << "PZ ";
	if (sym) cout << "S ";
	if (asym) cout << "AS ";
	if (p) cout << "P ";
	if (s) cout << "SP ";
	if (zw + pz + sym + asym + p + s == 0)
	{
		cout << "X";
		return 0;
	}else cout << "\n";

	if (rr) cout << "RR ";
	if (rpl)
	{
		cout << "RPL ";
	}
	else
	{
		if (rpcz) cout << "RPCz";
	}
	if (rr + rpl + rpcz == 0)
	{
		cout << "X";
	}

	return 0;
}