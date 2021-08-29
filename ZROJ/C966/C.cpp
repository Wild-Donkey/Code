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
unsigned Ans[100005], Cnt[100005], Blc, m, n, A, B, C, D, t, Tmp(0);
int a[100005], b[100005], * Newn;
struct Quest {
  unsigned L, R, Num, Belong;
  inline const char operator<(const Quest& x)const {
    return ((this->Belong) ^ (x.Belong)) ? ((this->Belong) < (x.Belong)) : ((this->R) < (x.R));
  }
}Q[100005];
signed main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
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
  for (register unsigned i(1); i <= m; ++i) {
    Q[i].L = RD(), Q[i].R = RD(), Q[i].Num = i, Q[i].Belong = Q[i].L / Blc;
  }
  sort(Q + 1, Q + m + 1);
  Cnt[a[1]] = 1;
  // for (register unsigned i(1); i <= n; ++i) {
  //   printf("%u\n", a[i]);
  // }
  for (register unsigned i(1), NowL(1), NowR(1), NowAns(1); i <= m; ++i) {
    // printf("Ask %u Now [%u, %u] %u\n", i, NowL, NowR, NowAns);
    while (NowL > Q[i].L) {
      // printf("Fuck?3");
      if ((Cnt[a[--NowL]]++) & 1) {
        --NowAns;
      }
      else {
        ++NowAns;
      }
    }
    while (NowR < Q[i].R) {
      // printf("NowR %u a[NowR] %u Cnt[a[NowR]] %u\n", NowR + 1, a[NowR + 1], Cnt[a[NowR + 1]]);
      if ((Cnt[a[++NowR]]++) & 1) {
        --NowAns;
      }
      else {
        ++NowAns;
      }
      // printf("After Cnt[a[NowR]] %u Ans %u\n", Cnt[a[NowR - 1]], NowAns);
    }
    while (NowL < Q[i].L) {
      // printf("Fuck?");
      if ((Cnt[a[NowL++]]--) & 1) {
        --NowAns;
      }
      else {
        ++NowAns;
      }
    }
    while (NowR > Q[i].R) {
      // printf("Fuck2?");
      if ((Cnt[a[NowR--]]--) & 1) {
        --NowAns;
      }
      else {
        ++NowAns;
      }
    }
    Ans[Q[i].Num] = NowAns;
  }
  for (register unsigned i(1); i <= m; ++i) {
    printf("%u\n", Ans[i]);
  }
  // system("pause");
  return Wild_Donkey;
}