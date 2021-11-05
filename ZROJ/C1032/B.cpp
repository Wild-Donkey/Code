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
const unsigned long long Mod(1000000007);
unsigned long long Ans(0), f[52];
unsigned m, n, l;
unsigned A, B, C, D, t;
char a[100005], b[55];
//unsigned char Pos[205][55], *Hd[205];
vector<unsigned> Pos[205];
//  inline void Clr() {}
signed main() {
//  freopen("B4.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
//  fread(Pool + 1, 1, 100055, stdin);
  scanf("%s%s", a + 1, b + 1);
//  memcpy(a + 1, Pool + 1, n);
//  memcpy(b + 1, Pool + n + 2, m);
  f[0] = 1;
//  for (unsigned i(0); i < 205; ++i) Hd[i] = Pos[i];
//  for (unsigned i(m); i; --i) *(Hd[b[i]]++) = i;
  for (unsigned i(m); i; --i) Pos[b[i]].push_back(i); 
  for (unsigned j(1); j <= n; ++j) for (auto k:Pos[a[j]]) 
    f[k] += f[k - 1], f[k] -= (f[k] >= Mod) ? Mod : 0;
  Ans = f[m] + Mod * 100000, f[0] = 0;
//  printf("Contr %llu\n", f[m]);
  for (unsigned i(1); i <= n; ++i) if(a[i] == b[1]) {
    unsigned Lim(min(n, i + l - 1));
    memset(f + 2, 0, 400), f[1] = 1;
    for (unsigned j(i + 1); j <= Lim; ++j) {
      for (auto k:Pos[a[j]]) f[k] += f[k - 1];
      if (!(j & 255)) for (unsigned k(m); k; --k) f[k] %= Mod;
    }
//    for (unsigned k(m); k; --k) printf("%u %llu\n", k, f[k]);
    Ans -= f[m] % Mod;
  }
  printf("%llu\n", Ans % Mod);
//  }
  return Wild_Donkey;
}
/*
10 3 5
aabbababba
aaa
*/
