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
const unsigned long long Mod(1000000007);
unsigned long long Ans(0), n;
unsigned long long Prime[10000005], CntP(0);
bitset<10000005> Isnt;
inline void Shri() {
  for (unsigned i(2); i <= 10000000; ++i) {
    if(!Isnt[i]) Prime[++CntP] = i;
    for (unsigned j(1); (Prime[j] * i <= 10000000) && (j <= CntP); ++j) {
      Isnt[i * Prime[j]] = 1;
      if(!(i % Prime[j])) break;
    }
  }
  for (unsigned i(2); i <= CntP; ++i) {
    for (unsigned long long j(Prime[i] * Prime[i]); j <= 10000000; j *= Prime[i])
      Isnt[j] = 0;
  }
  for (unsigned i(5000000); i; --i) {
    if(!(Isnt[i])) Isnt[i << 1] = 0;
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Shri();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    Ans += Isnt[i] ? 1 : (i - 1);
//    printf("%u %u\n", i, (unsigned)Isnt[i]);
    if(Ans >= Mod) Ans -= Mod; 
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
