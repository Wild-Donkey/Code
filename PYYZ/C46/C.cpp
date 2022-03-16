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
const unsigned long long Mod(998244353);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned long long Inv(unsigned long long x) {
  unsigned y(998244351);
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
struct Node {
  vector<pair<unsigned, Node*> > E;
  vector<vector<unsigned> > f;
}N[1005];
inline void DFS (Node* x, Node* Fa) {
  for (auto i:x->E) {
    
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), k = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD(), C = RD(), C = C * Inv(RD()) % Mod;
    N[A].E.push_back({C, N + B}), N[B].E.push_back({C, N + A});
  }
  DFS(N + 1, NULL);
  while () {
    
  }
//  }
  return Wild_Donkey;
}

