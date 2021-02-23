#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
long long b, p, k, t, ans = 1, fst[35], n = 0, two[35];
int main() {
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k << "=";
	b %= k;
	t = p;
	while (t) {
		n++;
		t /= 2;
	}
	two[0] = 1;
	for (int i = 1; i <= n; i++) {
		two[i] = 2 * two[i - 1];
	}
	fst[0] = b % k;
	for (int i = 1; i <= n; i++) {
		fst[i] = (fst[i - 1] * fst[i - 1]) % k;
	}
	int i = n;
	while (p) {
		if (p >= two[i]) {
			p -= two[i];
			ans *= fst[i];
			ans %= k;
		}
		i--;
	}
	cout << ans << endl;
	return 0;
}