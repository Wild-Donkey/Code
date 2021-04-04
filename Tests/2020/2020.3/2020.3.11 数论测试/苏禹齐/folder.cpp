#include <iostream>
#include <cstdio> 
using namespace std;
typedef long long ll;
int gcd(ll a, ll b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a; 
}
int main()
{
	freopen("folder.in", "r", stdin);
	freopen("folder.out", "w", stdout);
	ll a, b, c;
	cin >> a >> b >> c;
	if (c % gcd(a, b) || a == b == c == 1)
	{
		cout << "NO" << '\n' << "0";
		return 0;
	}
	int t = b + b % a;
	for (ll i = t; ; i += a)
		if ((i % b) == c)
		{
			cout << "YE5" << '\n' << i / a;
			return 0;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
