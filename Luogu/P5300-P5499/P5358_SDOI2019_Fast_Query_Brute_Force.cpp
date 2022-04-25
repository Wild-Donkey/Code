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
const unsigned long long Mod(10000019);
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline unsigned RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return ((rdtp * rdsg) % (int)Mod + (int)Mod) % (int)Mod;
}
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0);}
unsigned Q[100005][3], a[100005];
unsigned m, n, t, Val;
unsigned A, B, C, D;
unsigned Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Val = 0;
  for (unsigned i(1); i <= m; ++i) {
    Q[i][0] = A = RD();
    if(A ^ 6) {
      if(A ^ 5) { if(A == 1) Q[i][1] = RD(), Q[i][2] = RDsg(); else Q[i][1] = RDsg(); }
      else Q[i][1] = RD();
    }
    printf("%u %u %u\n", i, Q[i][1], Q[i][2]);
  }
  t = RD();
  for (unsigned i(1); i <= t; ++i) {
    A = RD() % m, B = RD() % m;
    for (unsigned j(1); j <= m; ++j) {
      D = ((A + (unsigned long long)B * j) % m) + 1;
      printf("Do %u\n", D);
      switch(Q[D][0]) {
        case (1) :{
          a[Q[D][1]] = Q[D][2];
          break;
        }
        case (2) :{
          for (unsigned k(1); k <= n; ++k) Mn(a[k] += Q[D][1]); 
          break;
        }
        case (3) :{
          for (unsigned k(1); k <= n; ++k) a[k] = (unsigned long long)a[k] * Q[D][1] % Mod; 
          break;
        }
        case (4) :{
          for (unsigned k(1); k <= n; ++k) a[k] = Q[D][1]; 
          break;
        }
        case (5) :{
          printf("%u\n", a[Q[D][1]]), Mn(Ans += a[Q[D][1]]);
          break;
        }
        case (6) :{
          Tmp = 0;
          for (unsigned k(1); k <= n; ++k) Mn(Tmp += a[k]);
          printf("%u\n", Tmp), Mn(Ans += Tmp); 
          break;
        }
      }
//      for (unsigned k(1); k <= n; ++k) printf("%u ", a[k]); putchar(0x0A);
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}
/*
83474 83474 83474 83474 83474 83474 83474
*/
