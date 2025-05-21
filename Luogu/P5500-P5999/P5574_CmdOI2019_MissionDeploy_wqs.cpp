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
unsigned a[26005], Lef[26005], Rig[26005], g[25005];
long long BlA[325][325], f[25005];
pair<unsigned, unsigned> b[26005];
unordered_map<unsigned, int> Ca;
unsigned Pool[10000000], Buck[26005];
unsigned m, n, N, Len, Bl;
unsigned Cnt(0);
int Count(unsigned ll, unsigned lr, unsigned rl, unsigned rr) {
  int CurC(0), Rt(0);
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
int Dot_Seg(unsigned dl, unsigned dr, unsigned bl, unsigned br) {
  unsigned *Mr(Pool + (br + 1) * (n + 1)), *Ml(Pool + (bl) * (n + 1));
  int Rt = 0;
  for (unsigned i(dl); i <= dr; ++i) Rt += Mr[a[i]] - Ml[a[i]];
  return (dl < bl * Len) ? ((dr - dl + 1) * (br - bl + 1) * Len - Rt) : Rt;
}
void Init() {
  N = n = RD(), m = RD();
  Len = sqrt(n) * 0.5 + 1;
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
int Calc(unsigned x, unsigned y) {
  ++Cnt;
  if (x == y) return 0;
  --x, --y;
  // if (Ca.count((x << 16) | y))
  //   printf("Here %u, %u = %d\n", x, y, Ca[(x << 16) | y]);
  if (Ca.count((x << 16) | y)) return Ca[(x << 16) | y];
  int Rt = 0;
  // printf("Hello %u, %u\n", x, y);
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
  return Ca[(x << 16) | y] = Rt;
}
short Best[26005][2];
unsigned Hd, Tl;
unsigned DP(long long x) {
  // printf("Dp %lld\n", x);
  Hd = Tl = 0;
  Best[Tl][0] = 0, Best[Tl++][1] = 1, f[0] = 0, g[0] = 0;
  for (unsigned i(1); i <= N; ++i) {
    while (Tl - Hd > 1) {
      if ((Best[Hd + 1][1]) <= i)
        ++Hd;
      else
        break;
    }
    unsigned Cur(Best[Hd][0]);
    f[i] = f[Cur] + Calc(Cur + 1, i) + x, g[i] = g[Cur] + 1;
    // printf("%u g %u Ans %lld\n", i, g[i], f[i] - x * g[i]);
    if (i == N) return g[i];
    while ((Tl > Hd) && Best[Tl - 1][1] > i &&
           f[i] + Calc(i + 1, Best[Tl - 1][1]) + x < f[Best[Tl - 1][1]])
      --Tl;
    unsigned L(i + 1), R(N + 1), Mid;
    if (Tl > Hd) {
      Cur = Best[Tl - 1][0];
      while (L < R) {
        Mid = ((L + R) >> 1);
        if (f[i] + Calc(i + 1, Mid) <= f[Cur] + Calc(Cur + 1, Mid))
          R = Mid;
        else
          L = Mid + 1;
      }
      if (L <= N)
        Best[Tl][0] = i, Best[Tl++][1] = L, f[L] = f[i] + Calc(i + 1, L) + x;
    } else
      Best[Tl][0] = i, Best[Tl++][1] = i + 1, f[i + 1] = f[i] + x;
    // printf("%u -> [%u, %u]\n", Best.back().first, Best.back().second, N);
  }
  // printf("DP %lld -> %u, Ans %lld\n", x, g[N] + 1, f[N] - x * g[N]);
  return g[N];
}
signed main() {
  Init();
  // printf("Done\n");
  // return 0;
  long long L(0), R(100000000), Mid, TmpD;
  while (L < R) {
    TmpD = DP(Mid = ((L + R + 1) >> 1));
    if (TmpD < m)
      R = Mid - 1;
    else
      L = Mid;
  }
  DP(L), printf("%lld\n", f[N] - L * m);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P5574_CmdOI2019_MissionDeploy.cpp -static-libstdc++
clang P5574_CmdOI2019_MissionDeploy.cpp -std=c++17 -lstdc++
*/