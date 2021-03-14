#include<iostream>
#include<cstring> 
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, a[1005], f[1005], ans = 0, u = 1;
int main() {
	int i = 1;
	while (cin >> a[i]) {
		i++;
	}
	f[1] = a[1];
	for (int j = 1; j <= i; j++) {
		bool flag = 0;
		for (int k = 1; k <= u; k++) {
			if (f[k] >= a[j]) {
				f[k] = a[j];
				flag = 1;
				break;
			}
		}
		if (!(flag)) {
			f[++u] = a[j];
		}
	}
	cout << u << endl;
	return 0;
}