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
const unsigned long long Base1(241), Base2(239);
unsigned long long Tmp1, Tmp2;
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char IO[1505];
set<pair<unsigned long long, unsigned long long> > St;
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Ans = n = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", IO), m = strlen(IO), Tmp1 = Tmp2 = 0;
    for (unsigned j(0); j < m; ++j) {
      Tmp1 = Tmp1 * Base1 + IO[j];
      Tmp2 = Tmp2 * Base2 + IO[j];
    }
    if(St.count(make_pair(Tmp1, Tmp2))) --Ans;
    else St.insert(make_pair(Tmp1, Tmp2));
  }
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

