#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
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
int Ans[15005][4], a[40005], b[15005], n, m, mx(0), Hans;
int main() {
  freopen("P2119_11.in", "r", stdin);
  freopen("my.out", "w", stdout);
  n = RD();
  m = RD();
  memset(b, 0, sizeof(b));
  for (register int i(1); i <= m; ++i) {
    a[i] = RD();
    b[a[i]]++;
    mx = max(mx, a[i]);
  }
  for (register int i(1); (i * 9) + 1 < mx; ++i) {
    Hans = 0;
    for (register int j(mx - i), a_(j - (i << 3) - 1), b_(a_ + (i << 1)); a_;
         --j, --a_, --b_) {
      Hans += b[j] * b[j + i];
      if (!(b[b_] && b[a_])) {
        continue;
      }
      Ans[a_][0] += b[b_] * Hans;
      Ans[b_][1] += b[a_] * Hans;
    }
  }
  for (register int i(1); (i * 9) + 1 < mx; ++i) {
    Hans = 0;
    for (register int j(1), c_(j + (i << 3) + 1), d_(c_ + i); d_ <= mx;
         ++j, ++c_, ++d_) {
      Hans += b[j] * b[j + (i << 1)];
      if (!(b[d_] && b[c_])) {
        continue;
      }
      Ans[c_][2] += b[d_] * Hans;
      Ans[d_][3] += b[c_] * Hans;
    }
  }
  for (register int i(1); i <= m; ++i) {
    printf("%d %d %d %d\n", Ans[a[i]][0], Ans[a[i]][1], Ans[a[i]][2],
           Ans[a[i]][3]);
  }
  return 0;
}