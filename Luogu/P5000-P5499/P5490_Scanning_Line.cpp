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
unsigned yList[200005], m, n, Cnty(0), A, B, t, Tmp(0), Last(0);
unsigned long long Ans(0);
char Pls;
struct Line {
  unsigned Ly, Ry, Posx;
  char Plus;
  inline const char operator<(const Line &x) const{
    return this->Posx < x.Posx;
  }
}Li[200005];
struct Node {
  Node *LS, *RS;
  unsigned Times, Lenth;
}N[400005], *CntN(N);
unsigned Change (Node *x, unsigned L, unsigned R) {
  if((B < L) || (A > R)) {  // Out Of Range
    if(x->Times) return yList[R] - yList[L - 1];
    else return x->Lenth;
  }
  if((A <= L) && (R <= B)) {// In Range
    if(Pls) ++(x->Times);
    else --(x->Times);
    if(x->Times) return yList[R] - yList[L - 1];
    else return x->Lenth;
  }
  register unsigned Mid((L + R) >> 1);
  if(!(x->LS)) x->LS = ++CntN;
  if(!(x->RS)) x->RS = ++CntN;
  x->Lenth = Change(x->LS, L, Mid) + Change(x->RS, Mid + 1, R);
  if(x->Times) return yList[R] - yList[L - 1];
  else return x->Lenth; 
}
int main() {
  n = RD();
  for (register unsigned i(1); i <= n; ++i)
    Li[(i << 1) - 1].Posx = RD() + 1, yList[(i << 1) - 1] = Li[(i << 1) - 1].Ly = Li[i << 1].Ly = RD() + 1, Li[i << 1].Posx = RD() + 1, yList[i << 1] = Li[(i << 1) - 1].Ry = Li[i << 1].Ry = RD() + 1, Li[(i << 1) - 1].Plus = 1;
  n <<= 1;
  sort(yList + 1, yList + n + 1);
  for (register unsigned i(1); i <= n; ++i)
    if(yList[i] ^ yList[Cnty])
      yList[++Cnty] = yList[i];
  n >>= 1;
  for (register unsigned i(1); i <= n; ++i) {
    Li[(i << 1) - 1].Ly = Li[i << 1].Ly = lower_bound(yList + 1, yList + Cnty + 1, Li[i << 1].Ly) - yList;
    Li[(i << 1) - 1].Ry = Li[i << 1].Ry = lower_bound(yList + 1, yList + Cnty + 1, Li[i << 1].Ry) - yList;
  }
  n <<= 1;
  sort(Li + 1, Li + n + 1);
  for (register unsigned i(1); i <= n; ++i) {
    if(Li[i].Posx ^ Li[i - 1].Posx)
      Ans += (unsigned long long)(Li[i].Posx - Li[i - 1].Posx) * Last;
    A = Li[i].Ly + 1, B = Li[i].Ry, Pls = Li[i].Plus;
    Last = Change(N, 1, Cnty);
  }
  printf("%llu\n", Ans);
  return Wild_Donkey;
}
