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
unsigned m, n, t, N = 0, NN;
unsigned long long Ans(0);
unsigned a[100005], b[100005];
vector<unsigned> c[100005];
char Lst[131072];
struct Node {
  unsigned Min, Mx;
};
inline void Clr() {}
signed main() {
  // freopen("color2.in", "r", stdin);
  // freopen("duel.out", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= m; ++i) c[RD()].push_back(i);
  while ((1 << N) < n) ++N;
  NN = (1 << N);
  for (unsigned i(N - 1), I(1 << (N)); ~i; --i, I >>= 1) {
    scanf("%s", Lst + NN - I);
  }
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    unsigned ITmpX[4], CurAns = 0;
    ITmpX[0] = RD();
    ITmpX[1] = RD();
    ITmpX[2] = RD();
    ITmpX[3] = RD();
    for (unsigned i(1); i <= n; ++i) b[i] = (a[i] ^ ITmpX[i % 4]);
    for (unsigned i(1); i <= n; ++i) {
      for (auto j : c[i]) Ans ^= j * CurAns;
    }
    printf("%u\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P11233_CSP2024_Color.cpp -O3
*/