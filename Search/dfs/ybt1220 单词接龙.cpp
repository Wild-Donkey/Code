#include<iostream>
#include<cstring> 
#include<stack>
#include<minmax.h>
using namespace std;
int n, Ans, l[25], vsd[25];
string a[25];
char ch;
int f(string x) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i][0] != x) {
			continue;
		}
		if (vsd[i] >= 2) {
			continue;
		}
		vsd[i] += 1;
		int l = a[i].length();
		ans = max(f(a[i][l - 1]) + l - 1, ans);
		vsd[i] -= 1;
	}
	ans;
	return ans;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l[i] = a[i].length();
	}
	cin >> ch;
	for (int i = 1; i <= n; i++) {
		if (a[i][0] == ch) {
			vsd[i] = 1;
			Ans = max(f(a[i][l[i] - 1]) + l[i], Ans);
			vsd[i] = 0;
		}
	}
	cout << Ans << endl;
	return 0;
}