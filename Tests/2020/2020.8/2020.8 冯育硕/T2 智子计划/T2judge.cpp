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
#include <windows.h>
using namespace std;
int t, Ti, m, n, a[10005], ans = 0;
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
  t = In();
  for (register int i(1); i <= t; ++i) {
  	system ("T2rand.exe > t2_10.in");
		Ti = clock();
  	system ("T2std.exe < t2_10.in > t2_10.out");
  	Ti = clock() - Ti;
  	printf ("std in %d ms\n", Ti);
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

