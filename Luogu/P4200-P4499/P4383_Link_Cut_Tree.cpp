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
#define INF 0x7fffffffffffffff
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
long long Ans[300005];
unsigned m, n;
unsigned A, B, D, t;
long long L(-300000000000), R(300000000000), C;
unsigned Cnt(0), Tmp(0);
struct Node {
  Node* Fa;
  vector <pair<Node*, int>> E;
  long long f[3];
  unsigned g[3];
}N[300005];
inline void DFS(Node* x) {
  x->f[0] = x->g[0] = 0, x->g[1] = 1, x->f[1] = -C, x->g[2] = x->f[2] = -100000000000000000;
  for (auto i : x->E) if (i.first != x->Fa) {
    Node* Cur(i.first);
    Cur->Fa = x, DFS(Cur);
    // printf("Son %u %d\n", Cur - N, i.second);
    long long Des(x->f[1] + Cur->f[1] + i.second + C);
    if (Cur->f[0] > 0) x->f[2] += Cur->f[0], x->g[2] += Cur->g[0];
    if (x->f[2] < Des) x->f[2] = Des, x->g[2] = x->g[1] + Cur->g[1] - 1;
    if (Cur->f[0] > 0) x->f[1] += Cur->f[0], x->g[1] += Cur->g[0];
    Des = x->f[0] + Cur->f[1] + i.second;
    if (x->f[1] < Des) x->f[1] = Des, x->g[1] = x->g[0] + Cur->g[1];
    if (Cur->f[0] > 0) x->f[0] += Cur->f[0], x->g[0] += Cur->g[0];
  }
  if (x->f[1] > x->f[0]) x->f[0] = x->f[1], x->g[0] = x->g[1];
  if (x->f[2] > x->f[0]) x->f[0] = x->f[2], x->g[0] = x->g[2];
  // printf("Done %u: %lld %lld %lld\n", x - N, x->f[0], x->f[1], x->f[2]);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD() + 1;
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RDsg();
    N[A].E.push_back(make_pair(N + B, C));
    N[B].E.push_back(make_pair(N + A, C));
  }
  B = 0, D = n;
  while (L <= R) {
    C = ((L + R) >> 1);
    DFS(N + 1), A = N[1].g[0];
    Ans[A] = N[1].f[0] + C * A;
    // printf("Do [%lld %lld] %lld Pos %u Ans %lld\n", L, R, C, A, Ans[A]);
    if (A == m) { printf("%lld\n", Ans[m])/*, system("pause")*/;return 0; }
    if (A > m) L = C + 1, D = A;
    else R = C - 1, B = A;
  }
  // printf("[%u, %u]\n", B, D);
  // for (unsigned i(1); i <= m; ++i) printf("(%u, %lld)\n", i * 1000, max(N[1].f[i][0], max(N[1].f[i][1], N[1].f[i][2])));
  printf("%lld\n", Ans[B] + (Ans[D] - Ans[B]) / (D - B) * (m - B));
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
(1000, 8369)
(2000, 15802)
(3000, 21909)
(4000, 27627)
(5000, 33140)
(6000, 38017)
(7000, 42683)
(8000, 47161)
(9000, 51439)
(10000, 55230)
(11000, 58701)
(12000, 62100)
(13000, 65265)
(14000, 68102)
(15000, 70767)
(16000, 73428)
(17000, 76000)
(18000, 78555)
(19000, 81042)
(20000, 83471)
(21000, 85715)
(22000, 87879)
(23000, 89979)
(24000, 92009)
(25000, 94022)
(26000, 96035)
*/