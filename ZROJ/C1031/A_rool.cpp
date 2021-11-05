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
unsigned long long Ans(0); 
unsigned short a[55];
unsigned char n;
unsigned short List[30000005][2];
unsigned Cnt(0), Tmp;
unsigned F[8200][8200];
unsigned long long f[30000005], g[30000005];
signed main() {
//  freopen("A2.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned char i(1); i <= n; ++i) a[i] = RD();
  f[F[0x1fff][0] = ++Cnt] = 1, List[Cnt][0] = 0x1fff, List[Cnt][1] = 0; 
  for (unsigned char i(0); i < n; ++i) {
    memcpy(g, f, (Cnt + 1) << 3), Tmp = Cnt;
    for (unsigned j(1); j <= Tmp; ++j) {
      unsigned Xo(List[j][1] ^ a[i + 1]), An(List[j][0] & a[i + 1]);
      if(!F[An][Xo]) F[An][Xo] = ++Cnt, List[Cnt][0] = An, List[Cnt][1] = Xo;
      f[F[An][Xo]] += g[j];
    }
//    printf("Cnt %u\n", Cnt);
  }
  for (unsigned j(0); j <= 0x1fff; ++j) {
    Ans += f[F[j][j]];
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

