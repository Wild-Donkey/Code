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
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned long long RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned long long Mod(1000000007), Mx(10000000005);
unsigned long long Ans(0), n;
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  char Isnt[Mx];
  memset(Isnt, 0, sizeof(Isnt));
  unsigned long long Prime[500000005];
  unsigned CntP(0);
  for (unsigned long long i(2); i <= 10000000000; ++i) {
    if(!Isnt[i]) Prime[++CntP] = i;
    if(!(i % 1000000));
    for (unsigned j(1); (Prime[j] * i <= 10000000000) && (j <= CntP); ++j) {
      Isnt[i * Prime[j]] = 1;
      if(!(i % Prime[j])) break;
    }
    if(!(i % 10000000))printf("Done %llu\n", i);
  }
  for (unsigned i(2); i <= CntP; ++i) {
    for (unsigned long long j(Prime[i] * Prime[i]); j <= 10000000000; j *= Prime[i])
      Isnt[j] = 0;
    if(!(i % 1000000))printf("Done %llu\n", i);
  }
  for (unsigned long long i(5000000000); i; --i) {
    if(!(Isnt[i])) Isnt[i << 1] = 0;
    if(!(i % 1000000))printf("Done %llu\n", i);
  }
  printf("%llu\n", CntP);
//  n = RD();455052446
  freopen("TableLast.out", "w", stdout);
  for (unsigned long long i(1); i <= 10000000000; ++i) {
    Ans = (Ans + (Isnt[i] ? 1 : (i - 1))) % Mod;
//    printf("%u %u\n", i, (unsigned)Isnt[i]);
    if(i > 9999000000) printf("%llu %llu\n", i, Ans);
  }
//  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
/*
455052446
*/
