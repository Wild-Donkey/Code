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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt[1000005], Ans(0), Tmp(0);
struct Node {
  vector<Node *> Edge;
  unsigned Dep;
  inline unsigned DFS(Node *Fa) {
    Dep = 0;
    for (auto i : Edge)
      if (i != Fa) { Dep = max(Dep, i->DFS(this)); }
    // printf("DFS %u\n", Dep + 1);
    Cnt[++Dep]++;
    return Dep;
  }
} N[1000005];
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].Edge.clear();
  memset(Cnt, 0, (n + 2) << 2), n = RD(), Ans = 0x3f3f3f3f;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(2); i <= n; ++i) {
      A = RD();
      N[A].Edge.push_back(N + i);
      N[i].Edge.push_back(N + A);
    }
    N[1].DFS(NULL);
    // for (unsigned i(1); i <= N[1].Dep; ++i) printf("%u ", Cnt[i]);
    // putchar(0x0A);
    for (unsigned i(N[1].Dep); ~i; --i) { Ans = min(Ans, i + Cnt[i + 1]); }
    printf("%u\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}