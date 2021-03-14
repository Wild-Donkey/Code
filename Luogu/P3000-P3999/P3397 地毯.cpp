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
int A, B, C, D, n, m, cha[1005][1005], ans = 0, a[1005][1005];
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
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
	for (register int i(1); i <= m; ++i) {
  	A = In();
  	B = In();
  	C = In();
  	D = In();
  	++cha[A][B];
  	++cha[C + 1][D + 1];
  	--cha[A][D + 1];
  	--cha[C + 1][B];
	}
	memset (a, 0, sizeof(a));
  for (register int i(1); i <= n; ++i) {
  	for (register int j(1); j <= n; ++j) {
  		a[i][j] = cha[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
  		//printf("%d ", cha[i][j]);
		}
		//printf("\n");
	}
	//printf("\n\n");
	for (register int i(1); i <= n; ++i) {
		for (register int j(1); j <= n; ++j) {
  		printf("%d ", a[i][j]);
		}
		printf("\n");
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

