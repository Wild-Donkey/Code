#include<cstdio>
//#include<minmax.h>
#include<iostream>
using namespace std;
int T[105], W[105], M, f[105][1005];
int main() {
	cin >> T[0] >> M;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &T[i], &W[i]);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = T[0]; j >= 0; j--) {
			if (T[i] <= j) {
				f[i][j] = max(f[i - 1][j], f[i - 1][j - T[i]] + W[i]);
			}
			else {
				f[i][j] = f[i - 1][j];
			}
		}
	}
	cout << f[M][T[0]] << endl;//Êä³ö´ð°¸
	return 0;
}
