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
unsigned Inv[100005];
unsigned long long a, b, p, Tmp;
unsigned n, A, B, C, D, t;
unsigned Cnt(0), Ans(0);
unordered_map<unsigned, unsigned> S;
unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % p; x = x * x % p, y >>= 1; }
  return Rt;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  p = RD(), a = RD(), b = RD(), n = sqrt(p - 1) + 1, Inv[n] = Pow(Tmp = Pow(a, n), p - 2) * b % p;
  for (unsigned i(n - 1); ~i; --i) S[Inv[i] = Inv[i + 1] * a % p] = i;
  for (unsigned i(0), j(1); i < n; ++i, j = j * Tmp % p)
    if (S.find(j) != S.end()) { printf("%u\n", (i * n + S[j]) % (p - 1));return 0; }
  printf("no solution\n");
  //  }
  // system("pause");
  return Wild_Donkey;
}