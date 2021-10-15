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
unsigned Hash[105][105], f[105][105];
unsigned Pls[105];
char a[105];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  fread(a + 1, 1, 100, stdin);
  memset(f, 0x3f, sizeof(f));
  for (n = 0; a[n + 1] >= 'A'; ++n);
//  printf("n = %u\n", n);
  for (unsigned Len(1); Len <= n; ++Len)
    for (unsigned i(n - Len + 1); i; --i)
      Hash[Len][i] = Hash[Len - 1][i + 1] * 31 + a[i] - 'A';
  for (unsigned i(0); i < 10; ++i) Pls[i] = 3;
  for (unsigned i(10); i < 100; ++i) Pls[i] = 4;
  Pls[100] = 5;
  for (unsigned Len(1); Len <= n; ++Len)
    for (unsigned i(n - Len + 1); i; --i) 
      f[Len][i] = Len;
  for (unsigned Len(1); Len <= n; ++Len) {
    for (unsigned L(n - Len + 1); L; --L) {
      for (unsigned i(1); i < Len; ++i) if(!(Len % i)) {
        char Flg(0);
        unsigned Tplt(Hash[i][L]);
        for (unsigned j(L + Len - i); j > L; j -= i)
          if(Hash[i][j] ^ Tplt) {Flg = 1; break;}
//        printf("[%u, %u] Rep %u\n", L, L + Len - 1, i);
        if(!Flg) f[Len][L] = min(f[Len][L], f[i][L] + Pls[Len / i]);
      }
      for (unsigned len(1); len < Len; ++len)
        f[Len][L] = min(f[Len][L], f[len][L] + f[Len - len][L + len]);
//      printf("[%u, %u] %u\n", L, L + Len - 1, f[Len][L]);
    }
  }
  printf("%u\n", f[n][1]);
//  }
  return Wild_Donkey;
}

