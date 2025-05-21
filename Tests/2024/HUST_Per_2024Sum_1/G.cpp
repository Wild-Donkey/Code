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
const unsigned long long Mod(998244353);
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
unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
unsigned m, n;
unsigned A, B, C, D, t;
unsigned long long Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<Node*> Sons;
  char Val;
  unsigned long long f, g;
  void DFS(Node* Fa) {
    if (Val) ++f;
    else ++g;
    for (auto i : Sons) if (i != Fa) {
      i->DFS(this);
      unsigned long long F(f), G(g);
      f = (F + F * i->g + G * i->f) % Mod;
      g = (G + F * i->f + G * i->g) % Mod;
    }
  }
}N[100005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    N[i].Val = (RD() & 1);
  }
  for (unsigned i(1); i < n;++i) {
    A = RD(), B = RD();
    N[A].Sons.push_back(N + B);
    N[B].Sons.push_back(N + A);
  }
  N[1].DFS(NULL);
  for (unsigned i(1); i <= n;++i) Cnt += N[i].f, Ans += N[i].g;
  // for (unsigned i(1); i <= n;++i) printf("%u %llu %llu\n", i, N[i].f, N[i].g);
  Cnt %= Mod, Ans += Cnt, Ans %= Mod;
  Ans = Cnt * Pow(Ans, Mod - 2) % Mod;
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}