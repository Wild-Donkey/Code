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
unsigned PBrak[8192];
inline unsigned PopCnt(unsigned x) { return PBrak[x & 8191] + PBrak[x >> 13]; }
char a[1100005];
unsigned Border[1100005], Loop[1100005], Sub[1100005], Sum[27];
unsigned CurTot(0), m, n(0), Tot(0), PopTot(0), Cnt(0), CurCnt(0), Odd(0);
unsigned A, B, C, D, t;
unsigned long long Ans(0), TmpEve(0), TmpOdd(0);
inline void Clr() {
  memset(a, 0, n + 1), memset(Loop, 0, (n + 1) << 2);
  memset(Sum, 0, 108);
  scanf("%s", a + 1);
  n = strlen(a + 1);
  Cnt = Tot = Border[1] = 0, Loop[1] = 1, Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned i(1); i < 8192; ++i) PBrak[i] = PBrak[i >> 1] + (i & 1);
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(2); i <= n; ++i) {
      unsigned j(i - 1);
      while ((j) && (a[Border[j] + 1] ^ a[i])) j = Border[j];
      if (!j) Border[i] = a[i] == a[1];
      else Border[i] = Border[j] + 1;
      unsigned& k(Loop[i - Border[i]]);
      if (i % (i - Border[i])) Loop[i] = 1, Sub[i] = i;
      else k = max(i / (Sub[i] = i - Border[i]), k);
    }
    if (Sub[n] ^ n) --Loop[Sub[n]];
    // for (unsigned i(1); i <= n; ++i) printf("%u ", Sub[i]); putchar(0x0A);
    for (unsigned i(2); i <= n; ++i) if (Sub[i] ^ i) Loop[i] = Loop[Sub[i]] / (i / Sub[i]);
    // for (unsigned i(1); i <= n; ++i) printf("%u ", Border[i]); putchar(0x0A);
    // for (unsigned i(1); i <= n; ++i) printf("%u ", Loop[i]); putchar(0x0A);
    for (unsigned i(1); i <= n; ++i) Tot ^= (1 << (a[i] -= 'a'));
    CurTot = PopTot = PopCnt(Tot);
    Tot ^= (Cnt = (1 << a[1])), Sum[CurCnt = 1] = 1;
    if (Tot & (1 << a[1])) ++CurTot; else --CurTot;
    TmpEve = (PopTot ? 1 : 0), TmpOdd = (Tot ? 1 : 0);
    for (unsigned i(2); i < n; ++i) {
      if (Tot & (1 << a[i])) TmpOdd -= Sum[CurTot--]; else TmpOdd += Sum[++CurTot];
      Tot ^= (1 << a[i]);
      // printf("Odd %llu Eve %llu\n", TmpOdd, TmpEve);
      // printf("CurTot %u CurCnt %u\n", CurTot, CurCnt);
      Ans += TmpOdd * ((Loop[i] + 1) >> 1);
      Ans += TmpEve * (Loop[i] >> 1);
      if (Cnt & (1 << a[i])) --CurCnt; else ++CurCnt;
      ++Sum[CurCnt], Cnt ^= (1 << a[i]);
      TmpEve += (CurCnt <= PopTot);
      TmpOdd += (CurCnt <= CurTot);
    }
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}