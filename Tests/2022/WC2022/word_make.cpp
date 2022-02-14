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
unsigned Cnt(0), Ans(0);
set<string> S;
//  inline void Clr() {}
signed main() {
  freopen("FYSWords.txt", "w", stdout);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(0); i < 26; ++i) {
    for (unsigned j(0); j < 5; ++j) {
      for (unsigned k(0); k < 26; ++k) {
        string Tmp("00000");
        for (unsigned l(0); l < 5; ++l) Tmp[l] = ('a' + i);
        Tmp[j] = 'a' + k, S.insert(Tmp);
        if (S.size() >= 8869) break;
      }
      if (S.size() >= 8869) break;
    }
    if (S.size() >= 8869) break;
  }
  for (auto i : S) { for (unsigned j(0); j < 5; ++j) putchar(i[j]); }
  //  }
  //  system("pause");
  return Wild_Donkey;
}