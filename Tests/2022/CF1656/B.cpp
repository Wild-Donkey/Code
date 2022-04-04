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
int K(0), A;
set<int> S;
unsigned m, n;
unsigned B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0); 
inline void Clr() {
  n = RD(), K = RDsg(), S.clear(), Flg = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      A = RDsg();
      if(S.find(A - K) != S.end()) Flg = 1;
      if(S.find(A + K) != S.end()) Flg = 1;
      S.insert(A);
    }
    printf(Flg ? "YES\n" : "NO\n");
  }
  return Wild_Donkey;
}

