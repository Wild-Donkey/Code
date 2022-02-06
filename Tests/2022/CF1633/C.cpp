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
inline long long RDll() {
  long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
long long MyH, MyA, UrH, UrA, UpH, UpA;
long long A, B, MulMy, MulUr, Mul;
unsigned n, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
inline void Clr() {
  MyH = RDll(), MyA = RDll();
  UrH = RDll(), UrA = RDll();
  n = RD(), UpA = RDll(), UpH = RDll();
  Flg = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(0); i <= n; ++i) {
      A = MyH + (i * UpH);
      B = MyA + ((n - i) * UpA);
      MulMy = (A - 1) / UrA;
      MulUr = (UrH - 1) / B;
      Mul = min(MulMy, MulUr);
      if (UrH - (Mul * B) > B) continue;
      else { printf("YES\n"), Flg = 1; break; }
    }
    if (!Flg) printf("NO\n");
  }
  // system("pause");
  return Wild_Donkey;
}