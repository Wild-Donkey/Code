#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n, a1, a2, b1, b2, a, b, c;
char ch;
int main() {
	cin >> n;
	int i = 1;
	while (n > i) {
		n -= i;
		i++;
	}
	a = i;
	b = 1;
	for (int j = i; j > n; j--) {
		a--;
		b++;
	}
	cout << b << "/" << a << endl;
	return 0;
}