#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define LowBit(x) ((x)&((~(x))+1))
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
} 
const unsigned Bin[21] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
unsigned a[1100005], Ans(0);
unsigned m, n, t;
inline void Prt() {printf("1\n");for (unsigned i(Bin[n]); i; --i) printf("%u ", a[i]); putchar(0x0A);}
inline void Dif1 () {
  a[2] = 1;
  for (unsigned i(2); i <= n; ++i) for (unsigned j(Bin[i - 1]); j; --j) a[Bin[i] - j + 1] = a[j] | Bin[i - 1];
}
inline void DiMx () {
  for (unsigned i(2); i <= Bin[n]; ++i) a[i] = (LowBit(i - 1) ^ (Bin[n] - 1) ^ a[i - 1]);
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
  n = RD(), m = RD();
  if(!(m & 1)) {printf("0\n");return 0;}
  if(m == 1) {Dif1(), Prt(); return 0;}
  if(m == n - 1) {DiMx(), Prt();return 0;} 
  printf("0\n");
  return Wild_Donkey;
}
/*
1
3
1 1 1
*/
