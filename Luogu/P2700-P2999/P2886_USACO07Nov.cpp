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
unsigned a[205], m, n;
unsigned A[205], B[205], C[205], D, E, t;
unsigned Ans(0), Tmp(0);
struct Matrix {
  unsigned Mt[205][205];
  const Matrix operator*(const Matrix& x) const {
    Matrix Rt;
    // printf("Multi\n");
    for (unsigned i(1); i <= n; ++i)
      for (unsigned j(1); j <= n; ++j) {
        Rt.Mt[i][j] = 0x3f3f3f3f;
        for (unsigned k(1); k <= n; ++k)
          Rt.Mt[i][j] = min(Rt.Mt[i][j], Mt[i][k] + x.Mt[k][j]);
      }
    // printf("Done\n");
    return Rt;
  }
  const Matrix Pow(unsigned x) const {
    Matrix Rt, TmpM(*this);
    for (unsigned i(1); i <= n; ++i)
      for (unsigned j(1); j <= n; ++j) Rt.Mt[i][j] = 0x3f3f3f3f;
    for (unsigned i(1); i <= n; ++i) Rt.Mt[i][i] = 0;
    while (x) {
      // printf("Pow %u\n", x);
      if (x & 1) Rt = Rt * TmpM;
      TmpM = TmpM * TmpM, x >>= 1;
      // printf("Then\n");
    }
    return Rt;
  }
} Gr;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  t = RD(), m = RD(), D = RD(), E = RD();
  a[++n] = D, a[++n] = E;
  memset(Gr.Mt, 0x3f, sizeof(Gr.Mt));
  for (unsigned i(1); i <= m; ++i)
    C[i] = RD(), a[++n] = A[i] = RD(), a[++n] = B[i] = RD();
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  D = lower_bound(a + 1, a + n + 1, D) - a;
  E = lower_bound(a + 1, a + n + 1, E) - a;
  for (unsigned i(1); i <= m; ++i) {
    A[i] = lower_bound(a + 1, a + n + 1, A[i]) - a;
    B[i] = lower_bound(a + 1, a + n + 1, B[i]) - a;
    Gr.Mt[A[i]][B[i]] = Gr.Mt[B[i]][A[i]] = min(Gr.Mt[A[i]][B[i]], C[i]);
  }
  // printf("Here\n");
  Gr = Gr.Pow(t);
  printf("%u\n", Gr.Mt[D][E]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}