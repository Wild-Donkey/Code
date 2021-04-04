#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int m, n;
	long long total = 2;
	cin >> m >> n;
	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			if (j==2||i==2||gcd(i-1,j-1)==1)
			{
				total++;
				total %= 19268017;
			}
		}
	}
	cout << total;
	fclose(stdout);
	fclose(stdin);
}