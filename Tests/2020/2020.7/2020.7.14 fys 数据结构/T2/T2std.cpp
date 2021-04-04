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
int m, n, st[15][10005][2], ans = 0, two[10005], A, B;
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
inline int G (const int x, const int y) {
	if (y) {
		return G (y, x%y);
	}
	else{
		return x;
	}
}
inline void ask () {
	A = IN();
	B = IN();
	int tmp(two[B - A + 1]), tmp2(1 << tmp);
	//printf("%d %d\n", max(st[tmp][A][1], st[tmp][B - tmp2 + 1][1]), G(st[tmp][A][0], st[tmp][B - tmp2 + 1][0]));
	printf("%d\n", max(st[tmp][A][1], st[tmp][B - tmp2 + 1][1]) / G(st[tmp][A][0], st[tmp][B - tmp2 + 1][0]));
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
    n = IN();
    for (register int i(1); i <= n; ++i) {
    	st[0][i][2] = st[0][i][1] = st[0][i][0] = IN();
    }
    int cnt(0);
    for (register int i(1); i <= n; ++i) {
    	if(1 << (cnt + 1) <= i) {
    		two[i] = ++cnt;
		}
		else {
			two[i] = cnt;
		}
		//printf("%d %d\n", i, two[i]); 
	}
    for (register int i(1), ii(0); i <= n; i <<= 1, ++ii) {
    	int j(0);
		while((++j) + (i << 1) <= n + 1) {
			st[ii + 1][j][0] = G(st[ii][j][0], st[ii][j + i][0]);
			st[ii + 1][j][1] = max(st[ii][j][1], st[ii][j + i][1]);
			//printf("%d %d %d %d %d\n", i, ii, j, st[ii + 1][j][0], st[ii + 1][j][1]);
		}
	}
	m = IN();
	for(register int i(1); i <= m; ++i) {
		ask();
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

