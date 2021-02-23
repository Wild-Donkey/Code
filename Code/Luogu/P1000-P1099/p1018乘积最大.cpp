#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n, at, K, ans, A[50], C[1005], b[1005];
char a[50];
bool flg[1005];
void times(int x[], int y[]) {
	int xx = 0;
	for (int i = 1; i <= x[0]; i++)//枚举因数A的每一位 
	{
		xx = 0;
		for (int j = 1; j <= y[0]; j++) {//枚举因数B的每一位 
			b[i + j - 1] += xx + (x[i] * y[j]);
			xx = b[i + j - 1] / 10;
			b[i + j - 1] %= 10;
		}
		b[i + y[0]] += xx;
	}
	b[0] = x[0] + y[0];
	while (b[b[0]] == 0 && b[0] > 1)
		b[0]--;
	return;
}
int main() {
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		A[n - i + 1] = a[i] - 48;
	}
	A[0] = n;
	times(A, A);
	for (int i = b[0]; i >= 1; i--) {
		cout << b[i];
	}
	cout << endl;
	return 0;
}