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
typedef pair<unsigned long long, unsigned> Node;
unsigned m, n;
unsigned A, B, C, D, t;
unsigned long long Ans(0);
unsigned long long a[100005];
pair<unsigned long long, unsigned> Lef[100005], Rig[100005];
Node Find(Node *Tr, unsigned x) {
  Node Rt{0, 0};
  while (x) Rt = max(Rt, Tr[x]), x -= LowBit(x);
  return Rt;
}
void Edi(Node *Tr, Node x) {
  unsigned X(x.second);
  while (X <= n) Tr[X] = max(Tr[X], x), X += LowBit(X);
}
inline void Clr() {
  memset(Lef, 0, (1 + n) * sizeof(Node));
  memset(Rig, 0, (1 + n) * sizeof(Node));
  Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);2
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    n = RD();
    for (unsigned i(1); i <= n; ++i)
      a[i] = RD(), Edi(Lef, {a[i], i}), Edi(Rig, {a[i], n - i + 1});
    for (unsigned i(1); i <= n; ++i) {
      Node FdL(Find(Lef, i - 1)), FdR(Find(Rig, n - i));
      if (min(FdL, FdR).first > a[i]) Ans += min(FdL, FdR).first - a[i];
    }
    m = RD();
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD();
      Node FdL(Find(Lef, A - 1)), FdR(Find(Rig, n - A));
      if (A == 1 || A == n) {
        a[A] += B, Edi(Lef, {a[A], A}), Edi(Rig, {a[A], n - A + 1});
      }
      Node LR(Find(Rig, n - FdL.second)), RL(Find(Lef, FdR.second - 1));
      unsigned long long Bef(a[A]);
      a[A] += B, Edi(Lef, {a[A], A}), Edi(Rig, {a[A], n - A + 1});
      if (min(FdL, FdR).first >= a[A]) {
        Ans -= B, printf("%llu\n", Ans);
        continue;
      }
      if (min(FdL, FdR).first <= Bef) {
        printf("%llu\n", Ans);
        continue;
      }
      Ans -= min(FdL, FdR).first - Bef;
    }
  }
  //  system("pause");
  return Wild_Donkey;
}