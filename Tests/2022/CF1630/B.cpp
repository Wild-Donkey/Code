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
unsigned a[200005], Sum[200005], m, n;
unsigned A, B, C, D, t;
unsigned Ans(0);
struct Node {
  Node* Nxt, * Pre;
  unsigned L, R;
  int Del;
}N[200005], * Hd(N + 1);
inline void Clr() {
  memset(Sum, 0, (n + 1) << 2);
  n = RD(), m = RD(), A = ((n - m + 1) >> 1) + m;
  Ans = n - 1, C = 1, D = n;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    // printf("Need %u\n", A);
    for (unsigned i(1); i <= n; ++i) ++Sum[a[i] = RD()];
    for (unsigned i(1); i <= n; ++i) Sum[i] += Sum[i - 1];
    for (unsigned i(1); i <= n; ++i) {
      if (Sum[i] < A) continue;
      B = upper_bound(Sum + 0, Sum + i, Sum[i] - A) - Sum;
      if (i - B < Ans) Ans = i - B, C = B, D = i;
    }
    printf("%u %u\n", C, D);
    for (unsigned i(1); i <= n; ++i) {
      N[i].Nxt = N + i + 1, N[i].Pre = N + i - 1, N[i].L = N[i].R = i;
      N[i].Del = (((a[i] < C) || (a[i] > D)) ? 1 : (-1));
    }
    N[1].Pre = N[n].Nxt = NULL;
    Node* Cur(Hd = N + 1);
    while (Cur) {
      if ((Cur->Pre) && (Cur->Pre->Del + Cur->Del >= 0)) {
        Cur->L = Cur->Pre->L, Cur->Del += Cur->Pre->Del;
        Cur->Pre = Cur->Pre->Pre;
        if (Cur->Pre) Cur->Pre->Nxt = Cur;
        else Hd = Cur;
      }
      else Cur = Cur->Nxt;
    }
    Cur = Hd;
    for (unsigned i(1); i < m; ++i) {
      if ((Cur->Nxt) && (Cur->Nxt->Del + Cur->Del == -1)) printf("%u %u\n", Cur->L, Cur->Nxt->R), Cur = Cur->Nxt;
      else printf("%u %u\n", Cur->L, Cur->R);
      Cur = Cur->Nxt;
    }
    C = Cur->L;
    while (Cur) D = Cur->R, Cur = Cur->Nxt;
    printf("%u %u\n", C, D);
  }
  // system("pause");
  return Wild_Donkey;
}