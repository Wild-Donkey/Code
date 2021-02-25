#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int n, m, a[10005], ans = 0;
bool flg;
char ch;
string s;
inline int In() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
bool cmp (int x, int y) {
	int X[15], Y[15], tmp[15];
	//printf("%d %d\n", x, y);
	int cnt(0);
	while (x) {
		tmp[++cnt] = x % 10;
		x /= 10; 
	}
	X[0] = cnt;
	for (register int i(cnt); i >= 1; --i) {
		X[cnt - i + 1] = tmp[i]; 
	}
	cnt = 0;
	while (y) {
		tmp[++cnt] = y % 10;
		y /= 10; 
	}
	Y[0] = cnt;
	for (register int i(cnt); i >= 1; --i) {
		Y[cnt - i + 1] = tmp[i]; 
	}
	for (register int i(1); i <= max(X[0], Y[0]); ++i) {
		if (X[(i - 1) % X[0] + 1] > Y[(i - 1) % Y[0] + 1]) {
			return 1;
		}
		if (Y[(i - 1) % Y[0] + 1] > X[(i - 1) % X[0] + 1]) {
			return 0;
		}
	}
	return 0;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  for (register int i(1); i <= n; ++i) {
    a[i] = In();
  }
  for (register int i(n); i >= 1; --i) {
  	for (register int j(1); j < i; ++j) {
  		if(cmp(a[j], a[j + 1])) {
  			swap(a[j], a[j + 1]);
			}
		}
	}
	for (register int i(n); i >= 1; --i) {
		printf("%d", a[i]);
	}
	printf("\n");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
