#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
struct Query {
  unsigned long long Val;
  unsigned L, R, Num;
  inline const char operator < (const Query& x) const { return R < x.R; }
}Q[200005];
unsigned long long a[400005], B[60];
unsigned Pos[60], C, D, m, n;
unsigned Cnt(0), Tmp(0);
bitset<200005> Ans;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RDll();
  for (unsigned i(1); i <= m; ++i) Q[i].L = RD(), Q[i].R = RD(), Q[i].Val = RDll(), Q[i].Num = i;
  sort(Q + 1, Q + m + 1);
  for (unsigned i(1), j(1); j <= m; ++j) {
    while (i <= Q[j].R) {
      // printf("Add %u\n", i);
      unsigned long long A(a[i]);
      unsigned P(i++);
      for (unsigned k(59); (~k) && A; --k) if (A >> k) {
        if (!B[k]) { Pos[k] = P, B[k] = A;break; }
        if (P > Pos[k]) swap(P, Pos[k]), swap(A, B[k]);
        A ^= B[k];
      }
    }
    // printf("Ans %u\n", j);
    unsigned long long A(Q[j].Val);
    unsigned P(Q[j].L);
    for (unsigned k(59); ~k; --k) if (A >> k) {
      if (P > Pos[k]) break;
      A ^= B[k]; if (!A) { Ans[Q[j].Num] = 1; break; }
    }
  }
  for (unsigned i(1); i <= m; ++i) printf(Ans[i] ? "Yes\n" : "No\n");
  //  }
    //  system("pause");
  return Wild_Donkey;
}