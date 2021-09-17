#include<cstdio>
#include<iostream>
using namespace std;
long long a[35], tr[35][35], sum, times;
int main() {
	tr[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			tr[i][j] = tr[i - 1][j - 1] + tr[i - 1][j];
		}
	}
	int ci = 1;
	while (cin >> a[ci]) {
		sum += a[ci];
		ci++;
	}
	ci--;
	for (int i = 1; i <= ci; i++) {
		times += tr[ci][i];
	}
	printf("%ld\n", sum * times);
	return 0;
}