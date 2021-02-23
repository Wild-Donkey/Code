#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
bool a[105];
int main() {
	cin >> n;
	cout << n << endl;
	for (int i = 1; i <= n; i++) {//枚举不翻的
		for (int j = 1; j <= n; j++) {
			if (j != i) {
				a[j] = !a[j];
			}
			cout << a[j];
		}
		printf("\n");
	}
	return 0;
}