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
#define Lbt(x) ((x) & ((~(x))+1))
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
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
vector<unsigned> Con[200005];
unsigned long long D, C, Ans(0);
unsigned Tr[200005];
unsigned a[200005], b[200005], TmpSr[200005], m, n;
unsigned A, B, t;
unsigned Cnt(0), Tmp(0);
inline void Chg() {
  while (B < Cnt) ++Tr[B], B += Lbt(B);
}
inline void Find() {
  while (B) C += Tr[B], B -= Lbt(B);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) TmpSr[i] = a[i] = RD();
  sort(TmpSr + 1, TmpSr + n + 1);
  A = (Cnt = unique(TmpSr + 1, TmpSr + n + 1) - TmpSr) - 1;
  for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(TmpSr + 1, TmpSr + Cnt, a[i]) - TmpSr;
  for (unsigned i(1); i <= n; ++i) TmpSr[i] = b[i] = RD();
  sort(TmpSr + 1, TmpSr + n + 1);
  Cnt = unique(TmpSr + 1, TmpSr + n + 1) - TmpSr;
  for (unsigned i(1); i <= n; ++i) b[i] = lower_bound(TmpSr + 1, TmpSr + Cnt, b[i]) - TmpSr;
  for (unsigned i(1); i <= n; ++i) Con[a[i]].push_back(b[i]);
  for (unsigned i(1); i <= A; ++i) {
    // printf("%u %u %llu\n", i, Con[i].size(), D);
    for (auto j : Con[i]) B = j, Chg();
    D += Con[i].size();
    for (auto j : Con[i]) { B = j - 1, C = 0; if (B) Find(); Ans += D - C; }
    // printf("Ans %llu\n", Ans);
  }
  printf("%llu\n", Ans);
  //  } 
  // system("pause");
  return Wild_Donkey;
}