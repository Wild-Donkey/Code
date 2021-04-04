#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 19268017;
int main()
{
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	ans += (n + m) % mod;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
