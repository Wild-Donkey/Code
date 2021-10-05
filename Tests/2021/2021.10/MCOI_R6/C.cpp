#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const unsigned Mod(1000000007);
unsigned m, n, Cnt(0), A, B, C, D, t, Ans[200005], Tmp(0);
unsigned Pre[200005];
int Ex, Ey;
bool b[10005];
inline void Clr() {
  n = RD();
}
inline unsigned Exgcd(unsigned x, unsigned y, int &Unx, int &Uny) {
  if(!y) {
    Unx = 1, Uny = 0;
    return x;
  }
  unsigned TmpG(Exgcd(y, x % y, Uny, Unx));
  Uny -= x / y * Unx;
  return TmpG;
} 
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      A = RD(), B = RD(), C = RD();
      D = Exgcd(A, B, Ex, Ey);
      A /= D, B /= D, C /= D;
      Ex %= B; if(Ex < 0) Ex += B;
      Pre[i] = (unsigned long long)Ex * C % Mod;
      Ans[i] = Mod + Pre[i] - Pre[i - 1];
      if(Ans[i] >= Mod) Ans[i] -= Mod;
    }
    for (register unsigned i(1); i <= n; ++i) printf("%u ", Ans[i]);
    putchar('\n');
  }
  return Wild_Donkey;
}


