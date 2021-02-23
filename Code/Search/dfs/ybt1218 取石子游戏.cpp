#include<iostream>
#include<cstring> 
#include<stack>
using namespace std;
int a, b;
void f(int x, int y) {
	if (y > x) {
		int t = x;
		x = y;
		y = t;
	}
	if (y == 0) {

	}
	if (x >= 2 * y) {
		cout << "win" << endl;
		return;
	}
	if (x == y) {
		cout << "win" << endl;
		return;
	}
	else {
		int t = x;
		x = y;
		y = t - y;
		if (x >= 2 * y) {
			cout << "lose" << endl;
			return;
		}
		return f(y, x - y);
	}
}
int main() {
	cin >> a >> b;
	while ((a > 0) && (b > 0)) {
		f(a, b);
		cin >> a >> b;
	}
	return 0;
}