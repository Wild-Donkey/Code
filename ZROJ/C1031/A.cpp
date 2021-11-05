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
unordered_map<unsigned short, unsigned long long> f[55][8200];
//  inline void Clr() {}
signed main() {
  freopen("A2.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  f[0][0][0x1fff] = 1;
  for (unsigned char i(1); i <= n; ++i) a[i] = RD();
  for (unsigned char i(0); i < n; ++i) {
    for (unsigned short j(0); j <= 0x1fff; ++j) {
//      printf("ij %u %u\n", i, j);
      for (auto k:f[i][j]) {
        if(f[i + 1][j].find(k.first) == f[i + 1][j].end()) f[i + 1][j][k.first] = k.second;
        else f[i + 1][j][k.first] += k.second;
        if(f[i + 1][j ^ a[i]].find(k.first & a[i]) == f[i + 1][j ^ a[i]].end())
          f[i + 1][j ^ a[i]][k.first & a[i]] = k.second;
        else f[i + 1][j ^ a[i]][k.first & a[i]] += k.second;
      }
    }
  }
  for (unsigned short j(0); j <= 0x1fff; ++j) {
    if(f[n][j].find(j) != f[n][j].end()) Ans += f[n][j][j];
  }
  printf("%llu\n", Ans + 1);
//  }
  return Wild_Donkey;
}

