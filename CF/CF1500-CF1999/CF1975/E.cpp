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
#define Three(x) ((x) >= 2 ? 2 : (x))
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned Cnt[2][3];
unsigned m, n, Glb(0);
unsigned A, B, C, D, t;
struct Node {
  vector<Node *> Sons;
  Node *Fat;
  unsigned BlkSon, CntM[3];
  char Col;
  void DFS(Node *Fa) {
    Fat = Fa;
    for (auto i : Sons)
      if (i != Fa) {
        BlkSon += i->Col, i->DFS(this);
        CntM[Three(i->BlkSon)] += i->Col;
      }
    Cnt[Fa && Fa->Col][Three(BlkSon)] += Col;
  }
} N[200005];
void EdiFa(Node *x, char y) {
  char Fa(x->Fat && x->Fat->Col);
  if (y) {
    if ((x->BlkSon) <= 2) {
      --Cnt[Fa][x->BlkSon - 1], ++Cnt[Fa][x->BlkSon];
      if (x->Fat) --(x->Fat->CntM[x->BlkSon - 1]), ++(x->Fat->CntM[x->BlkSon]);
    }
  } else {
    if ((x->BlkSon) <= 1) {
      --Cnt[Fa][x->BlkSon + 1], ++Cnt[Fa][x->BlkSon];
      if (x->Fat) --(x->Fat->CntM[x->BlkSon + 1]), ++(x->Fat->CntM[x->BlkSon]);
    }
  }
}
inline void Clr() {
  memset(Cnt, 0, 24);
  for (unsigned i(1); i <= n; ++i)
    N[i].Sons.clear(), memset(N[i].CntM, 0, 12), N[i].BlkSon = 0;
  n = RD(), m = RD(), Glb = 0;
}

signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) Glb += N[i].Col = RD();
    for (unsigned i(1); i < n; ++i) {
      C = RD(), D = RD();
      N[C].Sons.push_back(N + D);
      N[D].Sons.push_back(N + C);
    }
    N[1].DFS(NULL);
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), N[A].Col ^= 1;
      Glb += N[A].Col ? 1 : -1;
      char TmFa(N[A].Fat && N[A].Fat->Col);
      Cnt[TmFa][Three(N[A].BlkSon)] += (N[A].Col) ? 1 : -1;

      if (N[A].Fat) {
        N[A].Fat->CntM[Three(N[A].BlkSon)] += (N[A].Col) ? 1 : -1;
        N[A].Fat->BlkSon += N[A].Col ? 1 : -1;
        if (N[A].Fat->Col) EdiFa(N[A].Fat, N[A].Col);
      }

      Cnt[N[A].Col ^ 1][0] -= N[A].CntM[0], Cnt[N[A].Col][0] += N[A].CntM[0];
      Cnt[N[A].Col ^ 1][1] -= N[A].CntM[1], Cnt[N[A].Col][1] += N[A].CntM[1];
      Cnt[N[A].Col ^ 1][2] -= N[A].CntM[2], Cnt[N[A].Col][2] += N[A].CntM[2];
      // printf("Tot %u\n", Glb);
      // printf("%u %u %u %u\n%u %u %u %u\n", Cnt[0][0], Cnt[0][1], Cnt[0][2],
      //        Cnt[0][3], Cnt[1][0], Cnt[1][1], Cnt[1][2], Cnt[1][3]);
      printf((((!Cnt[0][0]) && Cnt[0][1] + Cnt[1][0] == 2) || Glb == 1)
                 ? "Yes\n"
                 : "No\n");
    }
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1
6 10
1 1 1 1 1 1
1 2
2 3
2 4
2 5
2 6
3
4
5
6
1
2
1
2
3
1

1
5 1
1 1 1 0 1
1 2
2 3
3 4
4 5
3

6
5 3
1 1 1 1 1
3 5
2 5
3 4
1 5
1
1
1
4 4
0 0 0 0
1 2
2 3
1 4
1
2
3
2
1 1
1
1
1 1
0
1
2 1
1 0
1 2
1
5 4
1 0 0 0 0
1 2
1 3
1 5
3 4
4
3
2
5

*/