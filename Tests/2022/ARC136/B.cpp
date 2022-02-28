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
vector<unsigned> Pos[5005];
unsigned a[5005], b[5005];
char A[5005];
unsigned Ans(0), Tmp(0);
unsigned B, C, D, t, m, n;
char Flg(0), Dou(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) Pos[RD()].push_back(i);
  for (unsigned i(1); i <= 5000; ++i) if (Pos[i].size() > 1) Dou = 1;
  for (unsigned i(1); i <= n; ++i) {
    B = RD();
    if (!(Pos[B].size())) { Flg = 1; continue; }
    b[i] = Pos[B].back(), Pos[B].pop_back();
  }
  // for (unsigned i(1); i <= n; ++i) printf("%u ", b[i]); putchar(0x0A);
  if (Flg) { printf("No\n"); return 0; }
  if (Dou) { printf("Yes\n"); return 0; }
  for (unsigned i(0); i <= n; ++i) {
    for (unsigned j(b[i] + 1); j <= 5000; ++j) Ans += A[j];
    A[b[i]] = 1;
  }
  printf((Ans & 1) ? "No\n" : "Yes\n");
  //  }
//  system("pause");
  return Wild_Donkey;
}