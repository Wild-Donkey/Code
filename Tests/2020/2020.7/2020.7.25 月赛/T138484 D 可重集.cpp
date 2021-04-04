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
int Do, A, B, C, D, t, n, q, a[1000005], ans = 0;
bool flg;
char ch;
string s;
inline int IN() {
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
void Jud (int l1, int r1, int l2, int r2) {
	int len = r1 - l1 + 1, x[len + 2], y[len + 2], at = 0, bt = 0;
	for (register int i(l1); i <= r1; i++) {
		x[++at] = a[i];
	}
	for (register int i(l2); i <= r2; i++) {
		y[++bt] = a[i];
	}
	sort(x + 1, x + len + 1);
	sort(y + 1, y + len + 1);
	int del = x[1] - y[1];
	for (register int i(1); i <= len; i++) {
		if (x[i] - y[i] != del) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = IN();
  q = IN();
  for (register int i(1); i <= n; i++) {
     a[i] = IN();
  }
  for (register int i(1); i <= q; ++i) {
  	Do = IN();
  	if(Do) {
  		A = IN();
  		B = IN();
  		C = IN();
  		D = IN();
  		Jud(A, B, C, D);
		}
		else {
			A = IN();
			B = IN(); 
			a[A] = B;
		}
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

