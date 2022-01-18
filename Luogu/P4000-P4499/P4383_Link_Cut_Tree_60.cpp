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
unsigned m, n;
unsigned A, B, D, t;
int C;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node* Fa;
  vector <pair<Node*, int>> E;
  long long f[105][3];
}N[300005];
inline void DFS(Node* x) {
  memset(x->f, 0xaf, ((m + 1) * 3) << 3);
  x->f[0][0] = x->f[1][1] = 0;
  for (auto i : x->E) if (i.first != x->Fa) {
    Node* Cur(i.first);
    Cur->Fa = x, DFS(Cur);
    for (unsigned j(m); j; --j) {
      for (unsigned k(1); k <= j; ++k) {
        long long Mx(max(Cur->f[k][0], max(Cur->f[k][1], Cur->f[k][2])));
        if (Mx < 0) continue;
        if (Cur->f[k][1] >= 0) {
          x->f[j][2] = max(x->f[j][2], x->f[j - k + 1][1] + Cur->f[k][1] + i.second);
          x->f[j][1] = max(x->f[j][1], x->f[j - k][0] + Cur->f[k][1] + i.second);
        }
        x->f[j][2] = max(x->f[j][2], x->f[j - k][2] + Mx);
        x->f[j][1] = max(x->f[j][1], x->f[j - k][1] + Mx);
        x->f[j][0] = max(x->f[j][0], x->f[j - k][0] + Mx);
      }
    }
  }
  // printf("Done %u\n", x - N);
  // for (unsigned j(0); j <= m; ++j) printf("%lld %lld %lld\n", x->f[j][0], x->f[j][1], x->f[j][2]);
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
  DFS(N + 1);
  // for (unsigned i(1); i <= m; ++i) printf("(%u, %lld)\n", i * 1000, max(N[1].f[i][0], max(N[1].f[i][1], N[1].f[i][2])));
  printf("%lld\n", max(N[1].f[m][0], max(N[1].f[m][1], N[1].f[m][2])));
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