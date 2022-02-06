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
#define Lbt(x) ((x)&((~(x))+1))
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
unsigned long long T63((unsigned long long)1 << 63);
double Ans(0);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
struct Node {
  vector <Node*> Son;
  unsigned long long f[120][120];
  Node* Fa;
  unsigned Dep, Len;
}N[65];
inline unsigned long long Mul(unsigned long long x, unsigned long long y) {
  // printf("%lf * %lf = ", (double)x / T63, (double)y / T63);
  if ((!x) || (!y)) return 0;
  unsigned long long Tm2((T63 / Lbt(x)) << 1);
  x /= Lbt(x), y /= Tm2;
  // printf("%lf\n", (double)(x * y) / T63 * 2);
  return x * y;
}
inline void DFS(Node* x) {
  // printf("DFS %u\n", x - N);
  x->Len = x->Dep = 0, x->f[0][0] = ((unsigned long long)1 << 63);
  unsigned long long Tmp[120][120];
  for (auto i : x->Son) if (i != x->Fa) {
    i->Fa = x, DFS(i);// printf("Son %u\n", i - N);
    memset(Tmp, 0, sizeof(Tmp));
    for (unsigned Mem((x->Dep) << 1); (~Mem) && (Mem >= x->Dep); --Mem) {
      for (unsigned Med((x->Len) << 1); (~Med) && (Med >= x->Len); --Med) {
        for (unsigned Sm((i->Dep) << 1); (~Sm) && (Sm >= i->Dep); --Sm) {
          for (unsigned Sd((i->Len) << 1); (~Sd) && (Sd >= i->Len); --Sd) {
            // printf("%d %d %lf %d %d %lf\n", Mem, Med, (double)x->f[Mem][Med] / T63, Sm, Sd, (double)i->f[Sm][Sd] / T63);
            unsigned long long Mt(Mul(x->f[Mem][Med], i->f[Sm][Sd]));
            Tmp[max(Mem, Sm + 1)][max(Mem + Sm + 1, max(Med, Sd))] += Mt;
            Tmp[max(Mem, Sm + 2)][max(Mem + Sm + 2, max(Med, Sd))] += Mt;
          }
        }
      }
    }
    memcpy(x->f, Tmp, sizeof(Tmp));
    x->Len = max(x->Len, max(i->Len, x->Dep + i->Dep + 1));
    x->Dep = max(x->Dep, i->Dep + 1);
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) A = RD(), B = RD(), N[A].Son.push_back(N + B), N[B].Son.push_back(N + A);
  DFS(N + 1);
  for (unsigned Mem((N[1].Dep) << 1); Mem >= N[1].Dep; --Mem) {
    for (unsigned Med((N[1].Len) << 1); Med >= N[1].Len; --Med) {
      Ans += ((double)N[1].f[Mem][Med] / T63) * Med;
      // printf("(%u, %u) %llu %lf\n", Mem, Med, N[1].f[Mem][Med], (double)N[1].f[Mem][Med] / T63);
    }
  }
  printf("%.10lf", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
5
1 2
2 3
3 4
4 5
6

4
1 2
1 3
1 4
3.75

10
1 2
1 3
1 4
2 5
3 6
4 7
6 8
7 9
9 10
10.53125
*/