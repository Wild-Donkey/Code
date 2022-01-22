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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Chose[3005][3005];
char f[3005][3005];
char a[200005];
inline void Prt(unsigned Len, unsigned L) {
//  printf("[%u, %u]\n", L, L + Len - 1);
  if(Len <= 3) return;
  unsigned R(L + Len - 1);
  if(Chose[Len][L] > L + 1) printf("%u %u\n", ((L - 1) % n) + 1, ((Chose[Len][L] - 1) % n) + 1);
  if(R - 1 > Chose[Len][L]) printf("%u %u\n", ((R - 1) % n) + 1, ((Chose[Len][L] - 1) % n) + 1);
  Prt(Chose[Len][L] - L + 1, L);
  Prt(R - Chose[Len][L] + 1, Chose[Len][L]);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), scanf("%s", a + 1);
  for (unsigned i(1); i < n; ++i) a[n + i] = a[i];
  for (unsigned i(1); i <= n; ++i) if(a[i] ^ a[i + 1]) f[2][i] = 1;
  for (unsigned Len(3); Len <= n; ++Len) {
    for (unsigned i(1); i <= n; ++i) {
      if(a[i] ^ a[i + Len - 1]) {
        for (unsigned len(2); len < Len; ++len) {
          if((a[i + len - 1] ^ a[i]) && (a[i + len - 1] ^ a[i + Len - 1])) {
            if(f[len][i] & f[Len - len + 1][i + len - 1]){
              f[Len][i] = 1, Chose[Len][i] = i + len - 1;
              break;
            }
          }
        }
      }
    }
  }
  for (unsigned i(1); i <= n; ++i) {
    if(f[n][i]) {Prt(n, i); break;}
  }
//  }
  return Wild_Donkey;
}

