#include <bits/stdc++.h>
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
unsigned m, n;
unsigned A[5], B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[200005];
inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  while (t--) {
    Clr();
    scanf("%s", a);
    n = strlen(a);
    for (unsigned i = 0; i < n; i += 2) a[i] ^= 1;
    A[0] = A[1] = A[2] = A[3] = 0;
    for (unsigned i = 0; i < n; ++i) ++A[a[i] - '0'];
    A[2] += A[3];
    if (A[0] < A[1]) swap(A[0], A[1]);
    B = min(A[0] - A[1], A[2]);
    A[1] += B, A[2] -= B;
    if (A[0] == A[1])
      printf("%u\n", A[2] & 1);
    else
      printf("%u\n", A[0] - A[1]);
  }
  //  system("pause");
  return Wild_Donkey;
}
// g++ b.cpp -static-libstdc++