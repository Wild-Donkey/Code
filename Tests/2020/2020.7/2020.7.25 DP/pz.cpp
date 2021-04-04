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
int t, n, m, a[10005], ans = 0, f[15][15];
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
int main () {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  memset(f, 0, sizeof(f));
  for (register int i(1); i <= 13; ++i) {
  	if(i % 2) {
  		f[1][i] = f[i][1] = 0;
	  }
	  else {
	  	f[1][i] = f[i][1] = 1;
	  }
  }
  f[2][2] = 2;
  for (register int i(3); i <= 13; ++i) {
	f[2][i] = f[i][2] = f[i - 1][2] + f[i - 2][2];
	//printf("%d %d\n", i, f[i][2]);
  }
  for (register int i(4); i <= 13; i += 2) {
	f[3][i] = f[i][3] = /*(f[i][2] - 1) * 2 */2 * (i - 3) + (f[i - 2][3]) * 3;
	//printf("%d %d\n", i, f[i][3]);
  }
  for (register int i(4); i <= 13; ++i) {
  	for (register int j(i); j <= 13; ++j) {
		f[i][j] = f[2][j] * f[i - 2][j];
		f[i][j] += f[1][j] * f[i - 1][j];
		f[j][i] = f[i][j];
	}
  }
  m = IN();
  n = IN();
  while ((m != 0) && (n != 0)) {
  	printf("%d\n", f[m][n]);
  	m = IN();
  	n = IN();
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

