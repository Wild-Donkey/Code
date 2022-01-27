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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Name[105][25], IO[205];
set <pair<unsigned, unsigned> > S;
//  inline void Clr() {}
signed main() {
  freopen("save.in", "r", stdin);
  freopen("save.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    memset(IO, 0, sizeof(IO));
    scanf("%s%s", Name[i], IO);
    A = strlen(IO), B = 0;
    for (unsigned j(2); j < A; ++j) if ((IO[j - 2] == 's') && (IO[j - 1] == 'o') && (IO[j] == 's')) ++B;
    S.insert(make_pair(B, i));
  }
  B = S.rbegin()->first;
  for (auto i : S) if (i.first == B) printf("%s ", Name[i.second]); putchar(0x0A);
  printf("%u\n", B);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
2
adam
ineedhelpsosineedhelpsos
mark
ineedmorehelpsoshelpmesossoshelpme

mark
3


3
susan
sosososososos
jack
sossossossos
allen
soshelpsossossossossos
*/