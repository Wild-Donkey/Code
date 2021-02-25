#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int ans = 1, len, T, N = 0, two[15], fst[15];
string n;
int main() {
	two[0] = 1;
	for (int i = 1; i <= 13; i++) {
		two[i] = 2 * two[i - 1];
	}
	fst[0] = 2011;
	for (int i = 1; i <= 13; i++) {
		fst[i] = fst[i - 1] * fst[i - 1];
		fst[i] %= 10000;
		//cout << fst[i] << endl;
	}
	cin >> T;
	for (int j = 1; j <= T; j++) {
		cin >> n;
		len = n.length();
		ans = 1;
		if (len > 3) {
			for (int i = len - 3; i < len; i++) {
				N *= 10;
				N += int(n[i] - '0');
			}
		}
		else {
			for (int i = 0; i < len; i++) {
				N *= 10;
				N += int(n[i] - '0');
			}
		}
		int i = 13;
		while (N > 0) {
			if (N >= two[i]) {
				N -= two[i];
				ans *= fst[i];
				ans %= 10000;
			}
			i--;
			//cout << two[i]<<endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}