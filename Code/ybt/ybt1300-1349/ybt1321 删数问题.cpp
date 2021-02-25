#include<iostream>
#include<cstring> 
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;
string ch;
int n, a[305], l = 0, len, ans = 0, ed;
void del(int add) {
	for (int i = add; i < len; i++) {
		a[i] = a[i + 1];
	}
	len--;
	return;
}
int main() {
	cin >> ch;
	cin >> n;
	len = ch.length();
	ed = len - n;
	for (int i = 0; i < len; i++) {
		a[i] = ch[i] - '0';
	}
	while (len > ed) {
		for (int l = 0; l < len; l++) {
			if (a[l] > a[l + 1]) {
				del(l);
				break;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		if (a[i] == -1) {
			continue;
		}
		ans *= 10;
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}