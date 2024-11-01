#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <unordered_map>
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
unsigned a[26005], Lef[26005], Rig[26005];
unsigned BlA[360][360], f[2][25005], *Lf(f[0]), *Cf(f[1]);
pair<unsigned, unsigned> b[26005];
unsigned List[25000][800];
unsigned Pool[10000000], Buck[26005];
unsigned m, n, N, Len, Bl;
unsigned Cnt(0);
unsigned Count(unsigned ll, unsigned lr, unsigned rl, unsigned rr) {
  unsigned CurC(0), Rt(0);
  unsigned lb(ll / Len), rb(rl / Len);
  unsigned llim((lb + 1) * Len), rlim((rb + 1) * Len);
  for (unsigned i(lb * Len), j(rb * Len); j < rlim; ++j) {
    while (i < llim && b[i] <= b[j])
      CurC += (b[i].second >= ll && b[i].second <= lr), ++i;
    if (b[j].second >= rl && b[j].second <= rr) Rt += CurC;
  }
  // printf("Count (%u,%u)(%u,%u) = %u\n", ll, lr, rl, rr, Rt);
  return Rt;
}
unsigned Dot_Seg(unsigned dl, unsigned dr, unsigned bl, unsigned br) {
  unsigned *Mr(Pool + (br + 1) * (n + 1)), *Ml(Pool + (bl) * (n + 1));
  unsigned Rt = 0;
  for (unsigned i(dl); i <= dr; ++i) Rt += Mr[a[i]] - Ml[a[i]];
  return (dl < bl * Len) ? ((dr - dl + 1) * (br - bl + 1) * Len - Rt) : Rt;
}
void Init() {
  N = n = RD(), m = RD(), Len = 70;
  while (n % Len) ++n;
  for (unsigned i(0); i < N; ++i) a[i] = RD() + n - N;
  for (unsigned i(N); i < n; ++i) a[i] = n - i;
  Bl = n / Len;
  for (unsigned i(0), I(0), *j(a), Cur(0); I < n; ++i, ++I) {
    for (unsigned k(0); k < i; ++k) Cur += (j[k] < j[i]);
    Lef[I] = Cur;
    if (i == Len - 1) j += Len, i = 0xffffffff, Cur = 0;
  }
  for (unsigned i(Len - 1), I(n - 1), *j(a + (Bl - 1) * Len), Cur(0); ~I;
       --i, --I) {
    for (unsigned k(i + 1); k < Len; ++k) Cur += (j[k] > j[i]);
    Rig[I] = Cur;
    if (!i) j -= Len, i = Len, Cur = 0;
  }
  for (unsigned i(0); i < n; ++i) b[i] = {a[i], i};
  for (unsigned i(0); i < n; i += Len) sort(b + i, b + i + Len);
  for (unsigned i(0), j(0), *K(Pool + (n + 1)); i < n; ++i) {
    ++Buck[a[i]];
    if (!((i + 1) % Len)) {
      memcpy(K, Buck, (n + 1) << 2);
      for (unsigned k(2); k <= n; ++k) K[k] += K[k - 1];
      ++j, K += n + 1;
    }
  }
  for (unsigned i(0); i < Bl; ++i) BlA[i][i] = Rig[i * Len];
  for (unsigned i(Bl - 2); ~i; --i) {
    for (unsigned j(i + 1); j < Bl; ++j) {
      BlA[i][j] = BlA[i][j - 1] + BlA[i + 1][j] - BlA[i + 1][j - 1];
      BlA[i][j] +=
          Count(i * Len, (i + 1) * Len - 1, j * Len, (j + 1) * Len - 1);
    }
  }
  // for (unsigned i(0); i < Bl; ++i) {
  //   for (unsigned j(i); j < Bl; ++j) printf("%lld ", BlA[i][j]);
  //   putchar(0x0A);
  // }
  // printf("Inited N %u n %u Bl %u Len %u\n", N, n, Bl, Len);
}
unsigned Calc(unsigned x, unsigned y) {
  ++Cnt;
  if (x == y) return 0;
  --x, --y;
  if (y - x <= 801 && List[x][y - x - 1]) return List[x][y - x - 1] - 1;
  int Rt = 0;
  if (x / Len == y / Len) {
    if (x % Len)
      return Lef[y] - Lef[x - 1] - Count((x / Len) * Len, x - 1, x, y);
    else
      return Lef[y];
  } else {
    unsigned bl(x / Len), br(y / Len);
    if (x % Len) ++bl, Rt += Rig[x];
    if ((y + 1) % Len) --br, Rt += Lef[y];
    Rt += BlA[bl][br];
    if (x % Len) Rt += Dot_Seg(x, bl * Len - 1, bl, br);
    if ((y + 1) % Len) Rt += Dot_Seg((br + 1) * Len, y, bl, br);
    if (x % Len && (y + 1) % Len)
      Rt += Count(x, bl * Len - 1, (br + 1) * Len, y);
  }
  // printf("Calc [%u, %u] = %lld\n", x + 1, y + 1, Rt);
  if (y - x <= 801) List[x][y - x - 1] = Rt + 1;
  return Rt;
}
void DP(unsigned l, unsigned r, unsigned Ol, unsigned Or) {
  if (l > r) return;
  unsigned Mid((l + r) >> 1), Chs(0x3f3f3f3f), Cur(0x3f3f3f3f), Tmp;
  for (unsigned i(Ol); i <= Or && i < Mid; ++i) {
    Tmp = Lf[i] + Calc(i + 1, Mid);
    if (Tmp < Cur) Cur = Tmp, Chs = i;
  }
  Cf[Mid] = Cur;
  DP(l, Mid - 1, Ol, Chs);
  DP(Mid + 1, r, Chs, Or);
}
signed main() {
  Init(), Lf[0] = 0;
  for (unsigned i(1); i <= N; ++i) Lf[i] = Calc(1, i);
  for (unsigned i(2); i <= m; ++i, swap(Lf, Cf)) {
    DP(i, N, i - 1, N - 1);
    memset(Cf, 0, (i + 1) << 2);
  }
  printf("%u\n", Lf[N]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P5574_CmdOI2019_MissionDeploy.cpp -static-libstdc++
clang P5574_CmdOI2019_MissionDeploy.cpp -std=c++17 -lstdc++
*/