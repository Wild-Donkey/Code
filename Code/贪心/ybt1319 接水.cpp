#include<iostream>
#include<cstring> 
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
double sum, Ans;
struct f {
	int num, d;
	double wait;
}a[1005];
bool cmp(f x, f y) {
	return (x.d < y.d);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].d;
		a[i].num = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		cout << a[i].num << " ";
		a[i].wait = sum;
		sum += a[i].d;
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		Ans += a[i].wait;
	}
	Ans /= n * 1.000000;
	printf("%.2f\n", Ans);
	return 0;
}