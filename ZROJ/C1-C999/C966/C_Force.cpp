#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Ans, Cnt[100005], Blc, m, n, A, B, C, D, t, Tmp(0);
int a[100005], b[100005], * Newn;
struct Quest {
  unsigned L, R, Num, Belong;
  inline const char operator<(const Quest& x)const {
    return ((this->Belong) ^ (x.Belong)) ? ((this->Belong) < (x.Belong)) : ((this->R) < (x.R));
  }
}Q[100005];
signed main() {
  freopen("C.in", "r", stdin);
  freopen("C.ans", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = b[i] = RDsg();
  }
  sort(b + 1, b + n + 1);
  Newn = unique(b + 1, b + n + 1);
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = lower_bound(b + 1, Newn, a[i]) - b;
  }
  m = RD(), Blc = (n / sqrt(m)) + 1;
  for (register unsigned i(1), NowAns(1); i <= m; ++i) {
    Ans = 0, A = RD(), B = RD();
    memset(Cnt, 0, sizeof(Cnt));
    for (register unsigned j(A); j <= B; ++j) {
      ++Cnt[a[j]];
    }
    for (register unsigned j(1); j <= n; ++j) {
      if (Cnt[j] & 1) ++Ans;
    }
    printf("%u\n", Ans);
  }
  // system("pause");
  return Wild_Donkey;
}