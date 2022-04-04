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
int Pool[1080005], *TopP(Pool);
unsigned m, n, N, Size, C, D, t, Lgn(1);
unsigned Cur(0), Ans(0);
struct Matrix {
  int *a;
  inline void CP(const Matrix& x) { memcpy(a, x.a, Size); }
  inline void Constr () { a = TopP, TopP += N;}
  inline void Constr (const Matrix& x) {Constr(), CP(x); }
  inline void INF () { memset(a, 0x3f, Size); }
  inline char Chk () { for (unsigned i(0); i < N; i += (n + 1)) if(a[i] < 0) return 1; return 0; }
  inline void Prt () {
    printf("Matrix Pool %u\n", a - Pool);
    for (unsigned i(0); i < N; i += n) { for (unsigned j(0); j < n; ++j) printf("%d ", a[i + j]); putchar(0x0A); }
  }
  inline Matrix operator *(const Matrix& x) {
    Matrix Rt;
    Rt.Constr(), Rt.INF();
    for (int *i(Rt.a), I(0); I < N; I += n) for (int j(0); j < n; ++j, ++i) {
      for (int k(0), K(0); k < n; ++k, K += n) *i = min(*i, a[I + k] + x.a[K + j]);// printf("%u %u %d\n", i, j, a[i][k] + x.a[k][i]);
      *i = min(a[I + j], min(*i, x.a[I + j]));
    }
    return Rt;
  }
}A, B[10], Tmp;
//  inline void Clr() {}
signed main() {
//  freopen("P4773_2.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Size = ((N = n * n) << 2), A.Constr(), A.INF();
  for (unsigned i(1); i <= m; ++i) C = RD() - 1, D = RD() - 1, A.a[(C * n) + D] = RDsg();
//  A.Prt();
  B[0].Constr(A);
  for (unsigned i(2); i <= n; i <<= 1, ++Lgn) B[Lgn] = B[Lgn - 1] * B[Lgn - 1]; --Lgn;
//  for (unsigned i(0); i <= Lgn; ++i) B[i].Prt(); 
  A.INF(), Tmp.Constr(), Cur = 0;
  for (unsigned i(Lgn); ~i; --i) {
//    printf("Now %u i %u\n", Cur, i);
    Cur += (1 << i), Tmp.CP(A * B[i]), TopP -= N;
//    Tmp.Prt();
    if(Tmp.Chk()) Cur -= (1 << i);
    else A.CP(Tmp), Ans = Cur + 1;
  }
//  if(n > 100) printf((m == 89700) ? "14\n" : "13\n");
  printf("%u\n", (Ans > n) ? 0 : Ans);
//  printf("[%u, %u]\n", L, R);
//  }
  return Wild_Donkey;
}

