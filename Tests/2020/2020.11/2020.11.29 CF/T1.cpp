#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '1' || rdch > '9') {
    if (rdch == '-') {
      insign = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
int n, m, r, c, t, ans;
void Clr() {
  n = RD();
  m = RD();
  r = RD();
  c = RD();
  return;
}
int main() {
  t = RD();
  for (register int T(1); T <= t; ++T) {
    Clr();
    ans = max(n - r, r - 1) + max(m - c, c - 1);
    printf("%d\n", ans);
  }
  system("pause");
  return 0;
}