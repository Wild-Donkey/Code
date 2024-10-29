#include <bits/stdc++.h>
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
#include <bits/stdc++.h>
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
unsigned a[110005], Lef[110005], Rig[110005];
pair<unsigned, unsigned> b[110005];
unsigned long long BlA[530][530];
unsigned Pool[53000005], Buck[110005];
unsigned m, n, Len, Bl;
unsigned A, B;
unsigned long long Ans(0);
//  inline void Clr() {}
unsigned Count(unsigned ll, unsigned lr, unsigned rl, unsigned rr) {
  unsigned lb(ll / Len), rb(rl / Len), CurC(0), Rt(0);
  unsigned llim((lb + 1) * Len), rlim((rb + 1) * Len);
  for (unsigned i(lb* Len), j(rb* Len); i < llim; ++i) {
    while (j < rlim && b[j] <= b[i])
      CurC += (b[j].second >= rl && b[j].second <= rr), ++j;
    if (b[i].second >= ll && b[i].second <= lr) Rt += CurC;
  }
  return Rt;
}
unsigned Dot_Seg(unsigned dl, unsigned dr, unsigned bl, unsigned br) {
  unsigned* Mr(Pool + (br + 1) * (n + 1)), * Ml(Pool + (bl) * (n + 1));
  unsigned Rt = 0;
  for (unsigned i(dl); i <= dr; ++i) Rt += Mr[a[i]] - Ml[a[i]];
  // printf("Dot [%u,%u] Seg [%u,%u] %u\n", dl, dr, bl, br, Rt);
  return (dl < bl * Len) ? Rt : (dr - dl + 1) * (br - bl + 1) * Len - Rt;
}
void Init() {
  n = RD(), m = RD(), Len = sqrt(n) * 0.6 + 1;
  // for (unsigned i(0); i < n; ++i) a[i] = i + 1;
  for (unsigned i(0); i < n; ++i) a[i] = RD();
  while (n % Len) a[n] = n + 1, ++n;
  Bl = n / Len;
  // printf("n %u Bl %u Len %u\n", n, Bl, Len);
  for (unsigned i(0), I(0), *j(a), Cur(0); I < n; ++i, ++I) {
    for (unsigned k(0); k < i; ++k) Cur += (j[k] > j[i]);
    Lef[I] = Cur;
    if (i == Len - 1) j += Len, i = 0xffffffff, Cur = 0;
  }
  for (unsigned i(Len - 1), I(n - 1), *j(a + (Bl - 1) * Len), Cur(0); ~I; --i, --I) {
    for (unsigned k(i + 1); k < Len; ++k) Cur += (j[k] < j[i]);
    Rig[I] = Cur;
    if (!i) j -= Len, i = Len, Cur = 0;
  }
  for (unsigned i(0); i < n; ++i) b[i] = { a[i], i };
  // for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  for (unsigned i(0); i < n; i += Len) sort(b + i, b + i + Len);
  // printf("Cur Bl %u\n", Bl);
  for (unsigned i(0), j(0), *K(Pool + (n + 1)); i < n; ++i) {
    ++Buck[a[i]];
    if (!((i + 1) % Len)) {
      memcpy(K, Buck, (n + 1) << 2);
      for (unsigned k(2); k <= n; ++k) K[k] += K[k - 1];
      ++j, K += n + 1;
    }
  }
  // printf("Cur Bl %u\n", Bl);
  for (unsigned i(0); i < Bl; ++i) BlA[i][i] = Rig[i * Len];
  for (unsigned i(Bl - 2); ~i; --i) {
    for (unsigned j(i + 1); j < Bl; ++j) {
      // printf("Here %u %u\n", i, j);
      BlA[i][j] = BlA[i][j - 1] + BlA[i + 1][j] - BlA[i + 1][j - 1];
      BlA[i][j] += Count(i * Len, (i + 1) * Len - 1, j * Len, (j + 1) * Len - 1);
    }
  }
}
unsigned long long Calc(unsigned x, unsigned y) {
  unsigned long long Rt = 0;
  if (x / Len == y / Len) {
    if (x % Len) return Lef[y] - Lef[x - 1] - Count((A / Len) * Len, A - 1, A, B);
    else return Lef[y];
  } else {
    unsigned bl(A / Len), br(B / Len);
    if (A % Len) ++bl, Ans += Rig[A];
    if ((B + 1) % Len) --br, Ans += Lef[B];
    // printf("[%u,%u] bl %u br %u Ans %llu\n", A, B, bl, br, Ans);
    Ans += BlA[bl][br];
    // printf("%llu\n", Ans);
    if (A % Len) Ans += Dot_Seg(A, bl * Len - 1, bl, br);
    if ((B + 1) % Len) Ans += Dot_Seg((br + 1) * Len, B, bl, br);
    if (A % Len && (B + 1) % Len) Ans += Count(A, bl * Len - 1, (br + 1) * Len, B);
  }
  return Ans
}
unsigned DP(long long x) {
  long long TmpDp;
  for (unsigned i(1); i <= n; ++i) {
    TmpDp = f[j] +


      Calc(j + 1, i) - x;
    if (f[i] < TmpDp)
      f[i] = TmpDp, g[i] = g[j] + 1;
  }
  return g[n];
}
signed main() {
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  long long L(0), R(312487500), Mid;
  while (L < R) {
    Mid = ((L + R) >> 1);
    DP()
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P5574_CmdOI2019_MissionDeploy.cpp
*/