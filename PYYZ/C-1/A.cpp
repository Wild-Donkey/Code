#include <algorithm>
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
const unsigned long long Mod(1000000007);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Matrix {
  unsigned long long Nu[4];
  inline Matrix operator* (Matrix x) {
    Matrix Rt;
    Rt.Nu[0] = (Nu[0] * x.Nu[0] + Nu[1] * x.Nu[2]) % Mod;
    Rt.Nu[1] = (Nu[0] * x.Nu[1] + Nu[1] * x.Nu[3]) % Mod;
    Rt.Nu[2] = (Nu[2] * x.Nu[0] + Nu[3] * x.Nu[2]) % Mod;
    Rt.Nu[3] = (Nu[2] * x.Nu[1] + Nu[3] * x.Nu[3]) % Mod;
    return Rt;
  }
  inline Matrix Pow(unsigned x) {
    Matrix Rt(*this), X(*this);
    --x;
    while (x) {if(x & 1) Rt = Rt * X; X = X * X, x >>= 1;}
    return Rt;
  }
  inline void Minus() {
    if(Nu[1]) --Nu[1]; else Nu[1] = 1000000006;
    if(Nu[2]) --Nu[2]; else Nu[2] = 1000000006;
    if(Nu[3]) --Nu[3]; else Nu[3] = 1000000006;
  }
}Ma, a;
inline void Clr() {
  n = RD(), m = RD();
  Ma.Nu[0] = 0, Ma.Nu[1] = Ma.Nu[2] = Ma.Nu[3] = 1;
  Ma = Ma.Pow(n + 1), Ma.Minus();
  a.Nu[0] = a.Nu[1] = 1, a.Nu[2] = a.Nu[3] = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    a = a * Ma.Pow(m);
    printf("%llu\n", a.Nu[0]);
  }
  //  system("pause");
  return Wild_Donkey;
}

