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
map<unsigned, unsigned> M;
unsigned m, n;
unsigned A, B(0), C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned Gcd(unsigned x, unsigned y) {
  unsigned TmpG;
  while (y) { TmpG = x, x = y, y = TmpG % y; }
  return x;
}
//  inline void Clr() {}
signed main() {
  freopen("A3.in", "r", stdin);
//  freopen("My.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    printf("%u\n", i);
    A = RD();
    for (map<unsigned, unsigned>::iterator j(M.begin()); j != M.end(); ) {
      B = Gcd(A, j->first);
      if(B ^ (j->first)) { if(M.find(B) != M.end()) M[B] = min(M[B], j->second + 1); else M[B] = j->second + 1; ++j; }
      else ++j;
    }
    M[A] = 0;
    if(D ^ (M.begin()->first)) Cnt = 0, D = M.begin()->first;
    if(A == D) ++Cnt;
//    for (auto j:M) printf("%u %u\n", j.first, j.second);
  }
  printf("Gcd %u Ans %u\n", D, M[D]);
  if(Cnt) Ans = 0; else Cnt = 1;
  printf("%u\n", M[D] + n - Cnt);
//  }
  return Wild_Donkey;
}

