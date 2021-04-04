#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int mod = 19268017;
int pow_(ll a, int i)
{
	ll sum = 1;
	for (int j = 1; j <= i; j++)
		sum *= a, sum %= mod;
	return sum;
}
int main()
{
	freopen("block.in", "r", stdin);
	freopen("block.out", "w", stdout);
	ll n, ans[25];
	cin >> n;
	ans[1] = 1;
	for (int i = 1; i <= n; i++)
		ans[i] = pow_(2, i) - i, ans[i] %= mod;
	cout << ans[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
