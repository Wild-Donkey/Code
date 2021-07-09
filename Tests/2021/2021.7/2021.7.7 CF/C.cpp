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
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const double InfSm(0.00000000001);
unsigned a[10005], m, n, Cnt(0), t, Tmp(0);
char b[10005];
double A, B, C, D, Ans(0); 
inline void Clr() {
  Ans = 0.0; 
}
void DFS(double Now, double a, double b, double c, unsigned Dep) {
//  printf("Now %lf a %lf b %lf c %lf\n", Now, a, b, c);
//  printf("Dep %u Ans %lf\n", Dep, Ans);
  if(Now < InfSm) return;
  Ans += c * Now * Dep;
  register double newa, newb, newc, Delta;
  if(a > InfSm) {
    if(a >= D) Delta = D;
    else Delta = a;
    if(b > InfSm) {
      newb = b + (Delta / 2);
      newc = c + (Delta / 2);
    } else {
      newb = 0;
      newc = c + Delta;
    }
    DFS(Now * a, a - Delta, newb, newc, Dep + 1);
  }
  if(b > InfSm) {
    if(b >= D) Delta = D;
    else Delta = b;
    if(a > InfSm) {
      newa = a + (Delta / 2);
      newc = c + (Delta / 2);
    } else {
      newa = 0;
      newc = c + Delta;
    }
    DFS(Now * b, newa, b - Delta, newc, Dep + 1);
  }
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
    DFS(1.0, A, B, C, 0x1);
    printf("%.12lf\n", Ans);
  }
  return Wild_Donkey;
}

