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
vector <char> To[65];
unsigned List[65], Do[65], f[65], g[65];
unsigned M, m, n, p, P, Q;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
struct Matrix {
  unsigned Val[65][65];
  inline Matrix operator * (Matrix& x) {
    Matrix TmpT;
    for (unsigned i(1); i <= Cnt; ++i) {
      memset(TmpT.Val[i], 0, (Cnt + 1) << 2);
      for (unsigned j(1); j <= Cnt; ++j) {
        for (unsigned k(1); k <= Cnt; ++k) {
          TmpT.Val[i][j] += Val[i][k] * x.Val[k][j];
        }
      }
    }
    return TmpT;
  }
}Mu, Eps;
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), M = 1 << (m = RD()), p = RD(), Q = p - (P = RD()) - 1;
  for (unsigned j(0); j < p; ++j) B |= (RD() << j);
  for (unsigned j(0); j < p; ++j) A |= (RD() << j);
  for (unsigned j(p - 1); ~j; --j) C |= (RD() << j);
  for (unsigned i(0); i < M; ++i, Flg = 0) {
    for (unsigned j(0); (j < m) && (!Flg); ++j) if((1 << j) & i) {
      i ^= (1 << j);
      if(j < P) Flg = (i & (A >> (P - j))) ? 1 : 0;
      else Flg = (i & (A << (j - P))) ? 1 : 0;
      i ^= (1 << j);
    }
    if(!Flg) List[++Cnt] = i;
  }
  for (unsigned i(1); i <= Cnt; ++i) {
    for (unsigned j(0); j < M; ++j) if((1 << j) & List[i]) {
      if(j < P) Do[i] |= (B >> (P - j));
      else Do[i] |= (B << (j - P));
      if(j < Q) Do[i] |= (C >> (Q - j));
      else Do[i] |= (C << (j - Q));
    }
//    printf("%u %u Do %u\n", i, List[i], Do[i]);
  }
  for (unsigned j(1); j <= Cnt; ++j) for (unsigned k(1); k <= Cnt; ++k)
    Eps.Val[j][k] = !(Do[j] & List[k]);
  for (unsigned i(1); i <= Cnt; ++i) Mu.Val[i][i] = 1;
  while (n) {
    if(n & 1) Mu = Mu * Eps;
    n >>= 1, Eps = Eps * Eps;
  }
  for (unsigned i(1); i <= Cnt; ++i) Ans += Mu.Val[1][i];
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

