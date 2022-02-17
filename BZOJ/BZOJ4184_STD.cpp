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
map<unsigned, vector<unsigned> > a;
vector<unsigned> Span[32];
unsigned Bel[500005], Set[500005], Pri[500005], BSet[32], Bin[32], B[32], Pos[32], Siz[32], m, n;
unsigned C, D, Rk, Line;
unsigned Cnt(0), Ans(0), Tmp(0);
int A;
bitset<500005> Del;
//  inline void Clr() {}
void insert(int i, unsigned Val, int s) {
  Span[i] = false, Set[i] = 0;
  for (unsigned j(30); ~j;--j) {
    if (Val[j])
    {
      if (B[j] == 0)
      {
        B[j] = Val, Span[i] = true;
        BSet[j] = Set[i], BSet[j][i] = true;
        break;
      }
      else Val ^= B[j], Set[i] ^= BSet[j];
    }
  }
}
void del(int i, int n, int m) {
  if (!Span[i]) return;
  int z = -1;
  for (int x = 0; x < n; x++) if (!Span[x] && Set[x][i]) { z = x; break; }
  if (z != -1) {
    Span[z] = true;
    bitset<1000> t(Set[z]);
    t[z] = true;
    for (int x = 0;x < n;x++) if (Set[x][i]) Set[x] ^= t;
    for (int x = 0;x < m;x++) if (B[x] != 0 && BSet[x][i]) BSet[x] ^= t;
    return;
  }
  for (int x = 0;x < m;x++) if (B[x] != 0 && BSet[x][i]) { z = x; break; }
  bitset<1000> t(BSet[z]), o(B[z]);
  B[z] = 0;
  for (int x = 0;x < m;x++) if (B[x] != 0 && BSet[x][i]) B[x] ^= o, BSet[x] ^= t;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}