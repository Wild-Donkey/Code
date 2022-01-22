#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
unsigned long long Ans(0x3f3f3f3f3f3f3f3f), a[105], f[105][35][105], m, n;
unsigned A, B, C, D, t;
unsigned Tmp(0);
struct Node {
  unsigned Dep;
  unsigned long long Val;
  inline const char operator < (const Node& x)const {return Val > x.Val;}
}N[105];
struct Tr {
  Tr* LS, * RS;
  unsigned Dep;
  unsigned long long Val;
}Tree[205], * CntT(Tree);
priority_queue <Node> Hu;
inline void Clr() {
  n = RD(), m = RD(), Ans = 0x3f3f3f3f3f3f3f3f;
  CntT = Tree + n;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  for (unsigned T(1); ; ++T){
    Clr();
    if(!(n | m)) break;
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    sort(a + 1, a + n + 1);
//    if(T == 183 && n > 5) {
//      printf("%u %u\n", n, m);
//      for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]);
//      putchar(0x0A);
//    }
//    if(n > 5) continue; 
    for (unsigned i(n + 1); i; --i) {
      for (unsigned j(0); j <= m; ++j) {
        for (unsigned k(n + 1); ~k; --k) {
          f[i][j][k] = 0X3F3F3F3F3F3F3F3F;
        }
      }
    }
    for (unsigned j(0); j <= m; ++j) {
      for (unsigned k(min((1 << j), (int)(n + 1))); ~k; --k) {
        f[n + 1][j][k] = 0;
      }
    }
    for (unsigned i(n); i; --i) {
      for (unsigned j(1); j <= m; ++j) {
        for (unsigned k(min((1 << j), (int)n)); ~k; --k) {
          f[i][j][k] = f[i + 1][j][k + 1] + j * a[i];
          if(k & 1) f[i][j][k] = min(f[i][j][k], f[i][j - 1][(k - 1) >> 1] + a[i]);
//          printf("%u,%u,%u:%llu\n", i, j, k, f[i][j][k]);
        }
      }
    }
    for (unsigned j(1); j <= m; ++j) {
      for (unsigned k(min((1 << j), (int)n)); ~k; --k) {
        Ans = min(f[1][j][k], Ans);
      }
    }
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
10 30
1 1 1 1 3 4 4 4 4 5
*/
