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
unsigned Width[1005], Min, m, n, Cnt(0), C, D, t, Ans(-1), Tmp(0), W;
char Exist[1005];
struct Hill {
  unsigned Hight, Pos;
  inline const char operator<(const Hill &x) const{
    return (this->Hight ^ x.Hight) ? (this->Hight < x.Hight) : (this->Pos < x.Pos);
  }
}H[1005], A, B;
int main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    Exist[H[i].Hight = RD()] = 1, H[i].Pos = i;
  }
  H[++n].Hight = 0x3f3f3f3f, H[n].Pos = 0;
  H[++n].Hight = 0x3f3f3f3f, H[n].Pos = n - 1;
  sort(H + 1, H + n + 1);
//  for (register unsigned i(1); i <= n; ++i) {
//    printf("H[%u] = %u %u\n", i, H[i].Pos, H[i].Hight);
//  }
  Min = H[1].Hight; 
  for (register unsigned i(Min), L(0x3f3f3f3f), R(0); i <= 1000; ++i) {
    if(Exist[i]) {
      A.Hight = i;
      B.Hight = i + 1;
      L = min(L, upper_bound(H + 1, H + n + 1, A)->Pos);
      R = max(R, (lower_bound(H + 1, H + n + 1, B) - 1)->Pos);
      Width[i] = R - L + 1;
//      printf("%u\n", Width[i]);
    } else {
      Width[i] = Width[i - 1];
    }
//    printf("W[%u] = %u\n", i, Width[i]);
  }
  for (register unsigned i(Min); i <= 1000; ++i) {
    if(m < Width[i]) {
      W = Width[i];
      break;
    }
    m -= Width[i];
    Ans = i, W = Width[i];
  }
  ++Ans;
//  printf("%u %u\n", m, Ans);
  if(m >= (n - 2)) {
    W = n - 2;
    Ans += m / W;
    m %= W;
  }
  Tmp = __gcd(W, m);
  if(!Ans) {
    printf("%u/%u\n", m / Tmp, W / Tmp);
    return 0;
  }
  if(!m) {
    printf("%u\n", Ans);
    return 0;
  }
  printf("%u+%u/%u\n", Ans, m / Tmp, W / Tmp);
//  }
  return Wild_Donkey;
}
