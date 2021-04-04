#include<bits/stdc++.h>

using namespace std;

long long shu[21] = {0,1,2};
int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		fclose(stdout);
		fclose(stdin);
		return 0;
	}
	if (n == 2)
	{
		cout << 2;
		fclose(stdout);
		fclose(stdin);
		return 0;
	}
	for (int yousa = 3; yousa <= 20; yousa++)
	{
		shu[yousa] = shu[yousa - 1] * 2 % 19260817;
		for (int hanser= 1; hanser <=yousa-2 ; hanser++)
		{
			shu[yousa] += shu[hanser] * shu[yousa - 1 - hanser];
			shu[yousa] %= 19260817;
		}
	}
	cout << shu[n] % 19260817;
	fclose(stdout);
	fclose(stdin);
	return 0;
}