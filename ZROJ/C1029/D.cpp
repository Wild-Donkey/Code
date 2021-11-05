#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
const unsigned long long Base(50021), Mod(100000007);
unsigned a[50005], m, n;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
unsigned Stack[50005], Top(0);
unsigned Cnt[50005], Hash[50005];
unordered_map<unsigned, unsigned> Have[50005];
bitset<100000010> Yep;
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) Have[i].clear();
  n = 0, scanf("%u", &n), Ans = 2;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  for (; ;) {
    Clr();
    if(!n) return 0;
    for (unsigned i(1); i <= n; ++i) Have[i][a[i] = RD()] = 1, Cnt[i] = 1;
    if(n <= 2) {printf("%u\n", n); continue;}
    for (unsigned i(1); i <= n; ++i) Hash[i] = 1;
    for (unsigned Len(2); Len < n; ++Len) {
      for (unsigned i(n - Len + 1); i; --i) {
        if(!Have[i][a[i + Len - 1]]) Have[i][a[i + Len - 1]] = ++Cnt[i];
        Hash[i] = (Hash[i] * Base + Have[i][a[i + Len - 1]]) % Mod;
//        if(!Yep[Hash[i]]) printf("[%u, %u]\n", i, i + Len - 1);
        if(!Yep[Hash[i]]) Yep[Hash[i]] = 1, ++Ans, Stack[++Top] = Hash[i];
      }
      for (;Top;)Yep[Stack[Top--]] = 0; 
    }
    printf("%u\n", Ans);
  }
  return Wild_Donkey;
}

