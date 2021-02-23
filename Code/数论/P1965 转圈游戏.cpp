#include<cstdio>
#include<iostream>
using namespace std;
long long  ans = 1, two[35], mi[35], M, K, N, X;
int main() {
	cin >> N >> M >> K >> X;
	two[0] = 1;
	for (int i = 1; i <= 30; i++) {
		two[i] = two[i - 1] * 2;
	}
	mi[0] = 10;
	mi[0] %= N;
	for (int i = 1; i <= 30; i++) {
		mi[i] = mi[i - 1] * mi[i - 1];
		mi[i] %= N;
	}
	for (int i = 30; i >= 0; i--) {
		if (K >= two[i]) {
			K -= two[i];
			ans *= mi[i];
			ans %= N;
		}
		if (K == 0) {
			break;
		}
	}
	ans *= M;
	ans %= N;
	ans += X;
	ans %= N;
	cout << ans << endl;
	return 0;
}