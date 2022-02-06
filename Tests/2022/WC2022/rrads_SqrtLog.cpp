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
unsigned long long Ans[500005], Cur;
unsigned a[500005], m, n, A, B;
unsigned C, D, Beg;
unsigned Cnt(0), Tmp(0);
set <pair<unsigned, unsigned> > S;
struct Qry {
  unsigned L, R, Nu;
  const inline char operator < (const Qry& x) const {
    unsigned BL((x.L + B - 2) / B);
    return (((L + B - 2) / B) ^ BL) ? (((L + B - 2) / B) < BL) : ((BL & 1) ? (R > x.R) : (R < x.R));
  }
}Q[500005];
inline void Add(unsigned x) {
  // ++C;
  // fprintf(stderr, "Add %u To %llu ->", x, Cur);
  set <pair<unsigned, unsigned> >::iterator It(S.insert(make_pair(a[x], x)).first), Ti(It), Tii(It);
  unsigned TA(x), TB, TC;
  if (((++Tii) != S.end()) && (Ti != S.begin())) {
    TB = (--Ti)->second, TC = Tii->second;
    Cur -= (TB < TC) ? (TC - TB) : (TB - TC);
    Cur += (TA < TC) ? (TC - TA) : (TA - TC);
    Cur += (TA < TB) ? (TB - TA) : (TA - TB);
  }
  else {
    if (Ti != S.begin()) TB = (--Ti)->second, Cur += (TB < TA) ? (TA - TB) : (TB - TA);
    if (Tii != S.end()) TC = Tii->second, Cur += (TC < TA) ? (TA - TC) : (TC - TA);
  }
  // fprintf(stderr, "%llu\n", Cur);
}
inline void Del(unsigned x) {
  // ++D;
  // fprintf(stderr, "Del %u To %llu ->", x, Cur);
  set <pair<unsigned, unsigned> >::iterator It(S.find(make_pair(a[x], x))), Ti(It), Tii(It);
  unsigned TA(x), TB, TC;
  if (((++Tii) != S.end()) && (Ti != S.begin())) {
    TB = (--Ti)->second, TC = Tii->second;
    Cur += (TB < TC) ? (TC - TB) : (TB - TC);
    Cur -= (TA < TC) ? (TC - TA) : (TA - TC);
    Cur -= (TA < TB) ? (TB - TA) : (TA - TB);
  }
  else {
    if (Ti != S.begin()) TB = (--Ti)->second, Cur -= (TB < TA) ? (TA - TB) : (TB - TA);
    if (Tii != S.end()) TC = Tii->second, Cur -= (TC < TA) ? (TA - TC) : (TC - TA);
  }
  S.erase(It);
  // fprintf(stderr, "%llu\n", Cur);
}
//  inline void Clr() {}
signed main() {
  freopen("rrads.in", "r", stdin);
  freopen("rrads.out", "w", stdout);
  // Beg = clock();
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), B = (n / sqrt(m)) + 1;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= m; ++i) Q[i].L = RD(), Q[i].R = RD(), Q[i].Nu = i;
  sort(Q + 1, Q + m + 1);
  // for (unsigned i(1); i <= m; ++i) printf("%u ", Q[i].Nu); putchar(0x0A);
  // printf("Block %u\n", B);
  unsigned NL(1), NR = (0);
  for (unsigned i(1); i <= m; ++i) {
    // fprintf(stderr, "Ref %u [%u, %u] %u\n", i, Q[i].L, Q[i].R, clock() - Beg);
    while (NR < Q[i].R) Add(++NR);
    while (NL > Q[i].L) Add(--NL);
    while (NL < Q[i].L) Del(NL++);
    while (NR > Q[i].R) Del(NR--);
    Ans[Q[i].Nu] = Cur;
  }
  // printf("C %u D %u\n", C, D);
  // printf("Time %u\n", clock() - Beg);
  for (unsigned i(1); i <= m; ++i) printf("%llu\n", Ans[i]);
  //  }
  // system("pause");
  return Wild_Donkey;
}