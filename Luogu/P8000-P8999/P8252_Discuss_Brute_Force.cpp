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
bitset<5005> S[5005];
vector<unsigned> V[1000005];
unsigned a[1000005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), A = B = C = 0;
  if(n <= 5000) for (unsigned i(1); i <= n; ++i) S[i] = 0;
  else for (unsigned i(1); i <= n; ++i) V[i].clear();
}
signed main() {
  freopen("discuss.in", "r", stdin);
  freopen("discuss.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      a[i] = RD();
      for (unsigned j(a[i]); j; --j) S[i][RD()] = 1;
    }
    for (unsigned i(2); i <= n; ++i) {
      for (unsigned j(1); j < i; ++j) if((S[j] & S[i]).count()) 
        if(((S[j] | S[i]).count()) > max(a[i], a[j])) {A = i, B = j; break;}
      if(A | B) break;
    }
    if(A | B) printf("YES\n%u %u\n", A, B);
    else printf("NO\n");
  }
  return Wild_Donkey;
}

