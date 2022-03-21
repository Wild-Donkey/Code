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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
const unsigned long long Mod(1945342517);
unsigned long long Ans(0), Xor(0), m, n, M[100005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    n = RD();
    if(n >= 19260817) continue;
    M[++Cnt] = n;
  }
  sort(M + 1, M + Cnt + 1), m = 1;
  for (unsigned T(1), j(1); T <= Cnt; ++T){
    while(j < M[T]) m = (++j) * m % Mod;
    Ans += m, Xor ^= m;
  }
  printf("%llu %llu\n", Ans, Xor);
  return Wild_Donkey;
}
