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
unsigned long long t, n, a, b, ans = 0, f[70][1005];
bool flg;
char ch;
string s;
inline long long IN() {
  char ich = getchar();
  unsigned long long intmp = 0, insign = 1;
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
  a = IN();
  b = IN();
  //f[0] = {1, 2, 3, 4, 5, 6};
  //f[1] = {2, 4, 6, 8, 10, 12};
  //f[2] = {4, 8, 12, 16, 20, 24};
  //f[3] = {8, 16, 24, 32, 40, 48};
  //f[4] = {16};
  for (register int i(0); i <= b; ++i) {
  	f[0][i] = i + 1;
  }
  for (register int i(1); i <= a; ++i) {
  	for (register int j(0); j <= b; ++j) {
  		f[i][j] = f[i - 1][j] << 1;
  		//printf("%d\n", f[i][j]);
	}
  }
  ans = IN();
  ans += f[a][b];
  cout << ans;
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

