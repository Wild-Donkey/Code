#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, num, two[30];
int check(int x) {
	int ans = 0;
	for (int ci = 0; ci <= 25; ci++) {
		if (x & two[ci]) {
			ans++;
		}
	}
	return ans;
}
int main() {
	two[0] = 1;
	for (int i = 1; i <= 30; i++) {
		two[i] = 2 * two[i - 1];
	}
	cin >> n;
	while (n != 0) {
		num = check(n);
		for (int i = n + 1; i <= 2 * n; i++) {
			if (check(i) == num) {
				cout << i << endl;
				break;
			}
		}
		cin >> n;
	}
	return 0;
}