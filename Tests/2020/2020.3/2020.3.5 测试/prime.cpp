#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long n, ans = 0;
bool zs[10000005];
int main() {
	freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
	cin >> n;
	long long i = n + 1;
	while (i) {
		long long y = i;
		for (int j = 2; j <= y; j++) {
			if (!(y % j)) {
				ans++;
				y /= j;
				while (!(y % j)) {
					y /= j;
				}
			}
		}
		if (ans >= 5) {
			cout << i << endl;
			return 0;
		}
		ans = 0;
		i++;
	}
	return 0;
}