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
int m, n, l, h, a[10005], ans = 0, c;
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
void Getc() {
	if (h > n >> 1) {
		c = n - h + 1;
	}
	else {
		c = h;
	}
	if (l > n >> 1) {
		c = min (n - l + 1, c);
	}
	else {
		c = min (l, c);
	}
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  h = In();
	l = In();
	Getc();
	for (register int i(1); i < c; ++i) {
		ans += n - (i << 1) + 1;
	}
	ans <<= 2;
	if (h == c) {
		ans += l - c + 1;
		printf("%d\n", ans);
		return 0;
	}
	ans += n - (c << 1) + 2;
	if (l == n - c + 1) {
		ans += h - c;
		printf("%d\n", ans);
		return 0; 
	}
	ans += n - (c << 1) + 1;
	if (h == n - c + 1) {
		ans += n - c - l + 1;
		printf("%d\n", ans);
		return 0;
	}
	ans += (n << 1) - (c << 1) - c - h + 2;
	printf("%d\n", ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

