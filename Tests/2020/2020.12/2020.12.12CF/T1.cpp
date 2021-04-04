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
inline int RD() {
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
int n, c0, c1, h, cnts(0), t, cnt0(0), cnt1(0);
bool b[100005];
char ch, s[100005];
void Clr() {
  n = RD();
  c0 = RD();
  c1 = RD();
  h = RD();
  cnt0 = 0;
  cnt1 = 0;
  return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    for (register int i(1); i <= n; ++i) {
      while (ch != '0' && ch != '1') {
        ch = getchar();
      }
      if (ch == '0') {
        ++cnt0;
      } else {
        ++cnt1;
      }
      ch = getchar();
    }
    // printf("%d%d\n", cnt0, cnt1);
    if (c0 < c1) {
      swap(c1, c0);
      swap(cnt0, cnt1);
    }
    if (c1 + h < c0) {
      c0 = c1 + h;
    }
    printf("%d\n", c1 * cnt1 + c0 * cnt0);
  }
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
