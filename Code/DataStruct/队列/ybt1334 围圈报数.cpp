#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int cnt, n, m, at, stp;
bool a[105];
int main() {
	at = 0;
	cin >> n >> m;
	memset(a, 1, sizeof(a));
	at = 0;
	cnt = n;
	while (cnt) {
		stp = 0;
		while (stp < m) {
			at %= n;
			at++;
			if (a[at] != 0) {
				stp++;
			}
		}
		while (a[at] == 0) {
			at %= n;
			at++;
		}
		cout << at << " ";
		a[at] = 0;
		cnt--;
	}
	cout << endl;
	return 0;
}