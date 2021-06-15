#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Stack[2005][2], n, Cnt(0), A, B, C, D, t, Bucket[2005], Pos[2005], Fa[2005], Ans(0), Tmp(0), Dis[2005][2005], Qry(1);
unsigned Find(unsigned x) {
  register unsigned Tmpx(x);
  while (Fa[Tmpx] ^ Tmpx) {
    Tmpx = Fa[Tmpx];
  }
  return Fa[x] = Tmpx;
} 
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  memset(Dis, 0x3f, sizeof(Dis));
  for (register unsigned i(1); i <= n; ++i) {
    Fa[i] = i;
  }
  while (Cnt + 1 < n) {
    printf("? %u\n", Qry);
    fflush(stdout);
    for (register unsigned i(1); i <= n; ++i) {
      Dis[i][Qry] = Dis[Qry][i] = RD();
      if(Dis[Qry][i] == 1) {
        if(Find(Qry) ^ Find(i)) {
          Fa[Fa[i]] = Fa[Qry];
          Stack[++Cnt][0] = Qry;
          Stack[Cnt][1] = i;
        }
      }
    }
    memset(Bucket, 0, sizeof(Bucket));
    for (register unsigned i(1); i <= n; ++i) {
      ++Bucket[Dis[Qry][i]], Pos[Dis[Qry][i]] = i;
    } 
    register unsigned Pre(Qry), Disi(1);
    for (; Disi <= n; ++Disi) {
      if(Bucket[Disi] ^ 1) break;
      if(Find(Pre) ^ Find(Pos[Disi])) {
//        printf("Link %u %u\n", Pre, Pos[Disi]);
        Fa[Fa[Pos[Disi]]] = Fa[Pre];
        Stack[++Cnt][0] = Pre;
        Stack[Cnt][1] = Pos[Disi];
      }
      Pre = Pos[Disi];
    }
    for (register unsigned i(1); i <= n; ++i) {
      if(Dis[Qry][i] == Disi) {
        if(Find(Pre) ^ Find(i)) {
          Fa[Fa[i]] = Fa[Pre];
          Stack[++Cnt][0] = Pre;
          Stack[Cnt][1] = i;
        }
      }
    }
    Disi = 0;
    for (register unsigned i(1); i <= n; ++i) {
      if(Find(Qry) ^ Find(i)) {
        if(Dis[Qry][i] < Dis[Qry][Disi]) {
          Disi = i;
        }
      }
    }
    Qry = Disi;
  }
  printf("!\n");
  for (register unsigned i(1); i < n; ++i) {
    printf("%u %u\n", Stack[i][0], Stack[i][1]);
  }
  fflush(stdout);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
