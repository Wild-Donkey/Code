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
unsigned a[100005], b[100005], c[100005];
unsigned n, na, nb, A, B, t;
unsigned Cnt(0), Ans[50005][2];
char EdV[100005], Flg(0);
struct Node {
  vector<pair<Node*, unsigned> > Edge;
  char Vis;
  inline char DFS(unsigned Pre) {
    // printf("DFS %u %u\n", Pre, Cnt);
    Vis = 1;
    unsigned Lst(0), Cur(0);
    for (auto i : Edge) {
      Cur = i.second;
      if (!EdV[Cur]) {
        EdV[Cur] = 1;
        if ((!i.first->Vis) && (!i.first->DFS(Cur))) Cur = 0;
        if (Cur) {
          if (Lst)
            Ans[++Cnt][0] = Lst, Ans[Cnt][1] = Cur, Lst = 0;
          else
            Lst = Cur;
        }
      }
    }
    // printf("Lst %u\n", Lst);
    if (!Lst) return 1;
    if (Pre) Ans[++Cnt][0] = Pre, Ans[Cnt][1] = Lst;
    return 0;
  }
} N[200005];
inline void Clr() {
  memset(EdV, 0, n + 2);
  for (unsigned i(na + nb); i; --i) N[i].Edge.clear(), N[i].Vis = 0;
  n = RD(), Flg = Cnt = na = nb = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      A = RDsg() + 1000100000;
      a[i] = A - i;
      b[i] = A + i;
    }
    for (unsigned i(1); i <= n; ++i) c[i] = a[i];
    sort(c + 1, c + n + 1);
    na = unique(c + 1, c + n + 1) - c - 1;
    for (unsigned i(1); i <= n; ++i)
      a[i] = lower_bound(c + 1, c + na + 1, a[i]) - c;
    for (unsigned i(1); i <= n; ++i) c[i] = b[i];
    sort(c + 1, c + n + 1);
    nb = unique(c + 1, c + n + 1) - c - 1;
    for (unsigned i(1); i <= n; ++i)
      b[i] = lower_bound(c + 1, c + nb + 1, b[i]) - c;
    for (unsigned i(1); i <= n; ++i) {
      A = a[i], B = b[i];
      N[A].Edge.push_back({N + na + B, i});
      N[na + B].Edge.push_back({N + A, i});
    }
    for (unsigned i(1); i <= na; ++i)
      if (!N[i].Vis) Flg |= (!N[i].DFS(0));
    if ((Cnt << 1) != n) {
      printf("No\n");
    } else {
      printf("Yes\n");
      for (unsigned i(1); i <= Cnt; ++i)
        printf("%u %u\n", Ans[i][0], Ans[i][1]);
    }
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2
6
1 2 3 4 -3 2
4
1 2 3 0
*/