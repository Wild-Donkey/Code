#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int len, spc, cnt = 0, n;//连续空格的第一个空格位置
char a[100005];
void move(int x) {//将第x和x+1移动到spc和spc+1
	cnt++;
	int t;
	t = a[x];
	a[spc] = t;
	t = a[x + 1];
	a[spc + 1] = t;
	/*if (spc < x) {
		for(int mi=spc+2)
	}*/
	spc = x;
	a[x + 1] = '-';
	a[x] = '-';
	printf("step%2d:", cnt);
	for (int mi = 1; mi <= 2 * n + 2; mi++) {
		printf("%c", a[mi]);
	}
	printf("\n");
	return;
}
void f(int x) {
	if (x == 4) {
		move(4);
		move(8);
		move(2);
		move(7);
		move(1);
		return;
	}
	move(x);
	move(2 * x - 1);
	f(x - 1);
	return;
};
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = 'o';
		a[n + i] = '*';
	}
	a[2 * n + 1] = '-';
	a[2 * n + 2] = '-';
	spc = 2 * n + 1;
	printf("step 0:");
	for (int i = 1; i <= n * 2 + 2; i++) {
		printf("%c", a[i]);
	}
	printf("\n");
	f(n);
	return 0;
}