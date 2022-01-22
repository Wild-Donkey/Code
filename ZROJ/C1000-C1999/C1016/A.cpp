#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
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
unsigned long long Ans(1), Fac[300005], Inv[300005], Sum[300005];
unsigned a[300005], FlLen[300005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Fall {
  unsigned Beg, Len;
  inline const char operator < (const Fall& x) const{return Beg < x.Beg;}
};
set <Fall> SF;
inline unsigned long long Pow(unsigned long long x) {
  unsigned long long PTm(1);
  unsigned y(Mod - 2);
  while (y) {
    if(y & 1) PTm = PTm * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return PTm;
}
inline void Change (unsigned Pos) {
  set<Fall>::iterator It(SF.upper_bound((Fall){Pos, 0}));
  --It;
//  printf("Cut Left %u\n", distance(SF.begin(), It));
//  printf("[%u, %u] %llu\n", It->Beg, It->Beg + It->Len - 1, Pow(Ans));
  if(It->Beg < Pos) {
    if(a[Pos] > a[Pos - 1]) {
      Fall Cur(*It);
      SF.erase(It);
      It = SF.insert((Fall){Pos, Cur.Beg + Cur.Len - Pos}).first;
      Ans = Ans * Fac[It->Len - 1] % Mod;
      Ans = Ans * (n - Pos + 1) % Mod;
      Ans = Ans * Inv[Cur.Len - 1] % Mod;
      Cur.Len = Pos - Cur.Beg;
      Ans = Ans * Fac[Cur.Len - 1] % Mod;
      It = SF.insert(Cur).first;
      ++It;
    }
  }
//  printf("Cut Right %u\n", distance(SF.begin(), It));
//  printf("[%u, %u] %llu\n", It->Beg, It->Beg + It->Len - 1, Pow(Ans));
  if(It->Beg + It->Len - 1 > Pos) {
    if(a[Pos] < a[Pos + 1]) {
      Fall Cur(*It);
      SF.erase(It);
      It = SF.insert((Fall){Pos + 1, Cur.Beg + Cur.Len - Pos - 1}).first;
      Ans = Ans * Fac[It->Len - 1] % Mod;
      Ans = Ans * (n - Pos) % Mod;
      Ans = Ans * Inv[Cur.Len - 1] % Mod;
      Cur.Len = Pos - Cur.Beg + 1;
      Ans = Ans * Fac[Cur.Len - 1] % Mod;
      It = SF.insert(Cur).first;
    }
  }
//  printf("Add Left %u\n", distance(SF.begin(), It));
//  printf("[%u, %u] %llu\n", It->Beg, It->Beg + It->Len - 1, Pow(Ans));
  if((It->Beg == Pos) && (Pos > 1)) {
    if(a[Pos - 1] > a[Pos]) {
      unsigned TmpL(It->Len);
      Ans = Ans * Pow(n - Pos + 1) % Mod;
      Ans = Ans * Inv[TmpL - 1] % Mod;
      SF.erase(It--);
      Fall Cur(*It);
      SF.erase(It);
      Ans = Ans * Inv[Cur.Len - 1] % Mod;
      Cur.Len += TmpL;
      Ans = Ans * Fac[Cur.Len - 1] % Mod;
      It = SF.insert(Cur).first;
    }
  }
//  printf("Add Right %u\n", distance(SF.begin(), It));
//  printf("[%u, %u] %llu\n", It->Beg, It->Beg + It->Len - 1, Pow(Ans));
  if((It->Beg + It->Len - 1 == Pos) && (Pos < n)) {
    if(a[Pos + 1] < a[Pos]) {
      Ans = Ans * Pow(n - Pos) % Mod;
      Fall Cur(*It);
      SF.erase(It++);
      Ans = Ans * Inv[It->Len - 1] % Mod;
      SF.erase(It);
      Ans = Ans * Inv[Cur.Len - 1] % Mod;
      Cur.Len += It->Len;
      Ans = Ans * Fac[Cur.Len - 1] % Mod;
      It = SF.insert(Cur).first;
    }
  }
}
signed main() {
//    freopen("ex_a3.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), a[n + 1] = 0x3f3f3f3f, Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[n] = Pow(Fac[n]);
  for (unsigned i(n - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  for (unsigned i(1), j(1); i <= n; ++i) if(a[i] < a[i + 1]) FlLen[++Cnt] = i + 1 - j, j = i + 1;
  for (unsigned i(Cnt); i; --i) Sum[i] = Sum[i + 1] + FlLen[i];
  Ans = Inv[n];
  for (unsigned i(Cnt); i; --i) Ans = Ans * Sum[i] % Mod;
  for (unsigned i(Cnt); i; --i) Ans = Ans * Fac[FlLen[i] - 1] % Mod;
  for (unsigned i(Cnt), j(0); i; --i) j += FlLen[i], SF.insert((Fall){n - j + 1, FlLen[i]});
  printf("%llu\n", Pow(Ans));
  for (unsigned i(1); i <= m; ++i) {
    Cnt = 0, A = RD(), B = RD();
    swap(a[A], a[B]);
    Change(A), Change(B);
    printf("%llu\n", Pow(Ans));
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
 
