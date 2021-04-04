#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n, ans[30], lst[30], cnt, c[105];
bool b[30];
char A[105];
string a[105];
void work(int l, int r, int x) {
	for (int wi = l; wi <= r; wi++) {
		if (a[wi][x] != a[wi + 1][x]) {
			if (!lst[a[wi + 1][x] - 'a']) {
				lst[a[wi + 1][x] - 'a'] = a[wi][x] - 'a';
			}
			else {
				int wt;
				wt = lst[a[wi + 1][x] - 'a'];
				while (wt) {
					wt = lst[wt];
					if (wt == a[wi][x] - 'a') {
						break;
					}
				}
				lst[wt] = a[wi][x] - 'a';
			}
		}
		else {
			int wt = wi;
			while (a[wi][x] == a[wi + 1][x]) {
				wi++;
			}
			work(wt, wi - 1, x + 1);
		}
	}
}
int main() {
	//freopen("lexicographical.in", "r", stdin);
	//freopen("lexicographical.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int j = 0;
		while (a[i][j] == a[i - 1][j]) {
			j++;
			c[i]++;
			c[i - 1]++;
		}

	}
	work(1, n, 0);
	for (int i = 0; i <= 25; i++) {
		cout << char(i + 'a') << " " << lst[i] << endl;
	}
	int ti = 1;
	while (!lst[ti]) {
		ans[++cnt] = ti;
		b[ti] = 1;
		ti++;
	}
	while (cnt <= 30) {
		int tmp = ti;
		ti = 0;
		while (b[lst[ti]] != 1) {
			if (b[ti]) {
				continue;
			}

			ti++;
		}
	}
	cout << cnt << endl;
	if (cnt >= 27) {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 1; i <= 26; i++) {
		cout << char(ans[i] + 'a');
	}
	cout << endl;
	return 0;
}