#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
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
const char AvaC[12][2] = {{0, 1}, {3, 4}, {6, 7}, {1, 2}, {4, 5}, {7, 8},
                          {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}};
const char Prs[8][2] = {{6, 1}, {8, 3}, {4, 9}, {2, 7}, {6, 7}, {2, 9}, {4, 3}, {8, 1}};
unsigned Ten[10], A, t;
unsigned Q[400005], Hd(0), Tl(0);
unordered_map <unsigned, unsigned> Num;
inline void Cgith(unsigned& x, unsigned y, unsigned z) {
  x -= ((x / Ten[8 - y]) % 10) * Ten[8 - y] - z * Ten[8 - y];
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  Ten[0] = 1;
  for (unsigned i(1); i <= 9; ++i) Ten[i] = Ten[i - 1] * 10;
  for (unsigned i(0), j(0); i < 8; ++i) {
    j = Prs[i][0];
    j = j * 10 + Prs[i][1];
    j = j * 10 + 15 - Prs[i][0] - Prs[i][1];
    j = j * 10 + 20 - (Prs[i][0] << 1) - Prs[i][1];
    j = j * 10 + 5;
    j = j * 10 + (Prs[i][0] << 1) + Prs[i][1] - 10;
    j = j * 10 + Prs[i][0] + Prs[i][1] - 5;
    j = j * 10 + 10 - Prs[i][1];
    j = j * 10 + 10 - Prs[i][0];
    Q[++Tl] = j;
    Num.insert(make_pair(j, 0));
  }
  while (Hd ^ Tl) {
    unsigned Cur(Q[++Hd]), Ev[9], Des(Num.find(Cur)->second + 1);
    for (unsigned i(8), j(Cur); ~i; --i) Ev[i] = j % 10, j /= 10;
    for (unsigned i(0); i < 12; ++i) {
      unsigned To(Cur);
      Cgith(To, AvaC[i][0], Ev[AvaC[i][1]]);
      Cgith(To, AvaC[i][1], Ev[AvaC[i][0]]);
      if(Num.find(To) == Num.end()) Num.insert(make_pair(To, Des)), Q[++Tl] = To;
    }
  };
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    A = 0;
    for (unsigned i(0); i < 9; ++i) A = A * 10 + RD();
    printf("%u\n", Num.find(A)->second);
  }
  return Wild_Donkey;
}
/*
6 1 8
7 5 3
2 9 4

a b (15 - a - b)
(20 - 2a - b) 5 (2a + b - 10)
(a + b - 5) (10 - b) (10 - a)

5 < a + b < 15
10 < 2a + b < 20
*/
