#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
unsigned V[105], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char IO[105];
bitset<105> a[105];
struct Gro {
  bitset<105> Set;
  unsigned long long Val;
  inline const char operator <(const Gro& x) const {return Val > x.Val;}
}Epsi, Cur;
priority_queue<Gro> Q;
//  inline void Clr() {}
signed main() {
//  freopen("A.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) V[i] = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", IO + 1);
    for (unsigned j(1); j <= n; ++j) a[i][j] = IO[j] - '0';
  }
  Epsi.Set = Epsi.Val = 0, Q.push(Epsi);
  while (m--) {
    if(!Q.size()) {
      printf("-1\n");
      return 0;
    }
    Cur = Q.top(), Q.pop();
    unsigned Last(n);
    for (; Last; --Last) if(Cur.Set[Last]) break;
    for (unsigned i(Last + 1); i <= n; ++i) if((a[i] & Cur.Set) == Cur.Set)
      Epsi.Set = Cur.Set, Epsi.Set[i] = 1, Epsi.Val = Cur.Val + V[i], Q.push(Epsi);
  }
  printf("%llu\n", Cur.Val);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2 5
1 2
01
10
100

*/
