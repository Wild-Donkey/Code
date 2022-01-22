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
#define Min(x,y) ((x)<(y))?(x):(y)
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned Mod(1000000007);
unsigned Ans(0), f[55];
unsigned m, n, l;
unsigned A, B, C, D, t;
char a[100005], b[55];
vector <unsigned> Pos[205];
//  inline void Clr() {}
signed main() {
//  freopen("B4.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), l = RD();
  scanf("%s%s", a + 1, b + 1);
  f[0] = 1;
  for (unsigned i(m); i; --i) Pos[b[i]].push_back(i);
  for (unsigned j(1); j <= n; ++j) for (auto k:Pos[a[j]])
    f[k] += f[k - 1], f[k] -= (f[k] >= Mod) ? Mod : 0;
  Ans = f[m];
//  printf("Contr %llu\n", f[m]);
  for (unsigned i(1); i <= n; ++i) {
    if(a[i] == b[1]) {
//      printf("Now [%u, %u]\n", i, i + l);
      unsigned Lim(min(n, i + l - 1));
      memset(f, 0, 220), f[1] = 1;
      for (unsigned j(i + 1); j <= Lim; ++j) for (auto k:Pos[a[j]])
        f[k] += f[k - 1], f[k] -= (f[k] >= Mod) ? Mod : 0;
//      printf("Contr %llu\n", f[m]);
        Ans -= (Ans >= f[m]) ? f[m] : (f[m] - Mod);
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

