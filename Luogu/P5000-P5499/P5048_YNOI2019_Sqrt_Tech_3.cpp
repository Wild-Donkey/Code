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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
vector<unsigned> List[500005];
unsigned a[500005], Pos[500005], Cond[1005000], m, n;
unsigned A, B, C, L, R, BL, BR;
unsigned Cnt(0), Ans(0);
inline unsigned* Pnt(unsigned x, unsigned y) { return Cond + x * (A + 1) + y; }
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), B = max((n / 1000) + 1, (unsigned)(n / (sqrt(m) + 1)) + 1), A = n / B;
  // printf("%u\n", A / 1000);
  // return 0;
  for (unsigned i(1); i <= n; ++i) Pos[i] = a[i] = RD();
  sort(Pos + 1, Pos + n + 1), C = unique(Pos + 1, Pos + n + 1) - Pos - 1;
  for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(Pos + 1, Pos + C + 1, a[i]) - Pos;
  for (unsigned i(0); i < A; ++i) {
    memset(Pos, 0, (C + 1) << 2);
    unsigned* To(Pnt(i, i)), * Cur(a + i * B + 1), Tmp(0);
    for (unsigned j(i); j < A; ++j, ++To) {
      for (unsigned k(1); k <= B; ++k, ++Cur) Tmp = max(++Pos[*Cur], Tmp);
      (*To) = Tmp;
    }
  }
  for (unsigned i(1); i <= n; ++i) List[a[i]].push_back(i), Pos[i] = List[a[i]].size() - 1;
  for (unsigned i(1); i <= m; ++i) {
    L = (RD() ^ Ans), R = (RD() ^ Ans);
    if (L > R) swap(L, R);
    if (R > n) return 0;
    BL = (L + B - 2) / B, BR = (R / B);
    if (BL >= BR) {
      Ans = 0;
      for (unsigned k(L); k <= R; ++k) {
        unsigned Cur(Pos[k] + Ans), Now(a[k]);
        while ((Cur < List[Now].size()) && (List[Now][Cur] <= R)) ++Cur, ++Ans;
      }
      printf("%u\n", Ans);
      continue;
    }
    Ans = *Pnt(BL, BR - 1), BL = (B - ((L - 1) % B)) % B, BR = R % B;
    for (unsigned j(0), k(L); j < BL; ++j, ++k) {
      unsigned Cur(Pos[k] + Ans), Now(a[k]);
      while ((Cur < List[Now].size()) && (List[Now][Cur] <= R)) ++Cur, ++Ans;
    }
    for (unsigned j(0), k(R); j < BR; ++j, --k) {
      unsigned Cur(Pos[k] - Ans), Now(a[k]);
      while ((Cur < 0x3f3f3f3f) && (List[Now][Cur] >= L)) --Cur, ++Ans;
    }
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}