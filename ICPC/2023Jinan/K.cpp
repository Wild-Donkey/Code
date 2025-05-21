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
#define foreplay for
#define wild while
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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long m;
unsigned n, a[500005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct MySe {
  unsigned long long SumL, SumR;
  multiset<unsigned> ValL, ValR;
  void Balance() {
    unsigned TmpB;
    if (ValL.size() > (ValR.size() + 1)) {
      SumL -= (TmpB = *(ValL.rbegin()));
      ValL.erase(--(ValL.end()));
      ValR.insert(TmpB), SumR += TmpB;
    }
    if (ValR.size() > ValL.size()) {
      SumR -= (TmpB = *(ValR.begin()));
      ValR.erase(ValR.begin());
      ValL.insert(TmpB), SumL += TmpB;
    }
  }
  void Insert(unsigned x) {
    if (ValL.size() == 0 || x <= *(ValL.rbegin()))
      ValL.insert(x), SumL += x;
    else
      ValR.insert(x), SumR += x;
    Balance();
  }
  void Erase(unsigned x) {
    if (x <= *(ValL.rbegin()))
      ValL.erase(ValL.find(x)), SumL -= x;
    else
      ValR.erase(ValR.find(x)), SumR -= x;
    Balance();
  }
  unsigned long long Calc() {
    if (!(ValL.size())) return 0;
    unsigned long long Mid(*(ValL.rbegin()));
    // printf("Mid %llu Ans %llu\n", Mid,
    //        (ValL.size() * Mid - SumL) + (SumR - ValR.size() * Mid));
    return (ValL.size() * Mid - SumL) + (SumR - ValR.size() * Mid);
  }
} St;
inline void Clr() {
  n = RD(), m = RDll();
  St.SumL = St.SumR = 0;
  St.ValL.clear();
  St.ValR.clear();
  Ans = 1;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD() + n - i;
    unsigned L(1), R(1);
    St.Insert(a[1]);
    while (L <= n) {
      while (St.Calc() <= m) {
        // printf("[%u, %u]\n", L, R);
        Ans = max(Ans, R - L + 1);
        if (R >= n) break;
        St.Insert(a[++R]);
      }
      if (L == n) break;
      St.Erase(a[L++]);
    }
    printf("%u\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}