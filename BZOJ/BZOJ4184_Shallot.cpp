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
bitset<500005> Del;
bitset<32> Exi;
unsigned Set[500005], Bel[500005], BSet[32], Bin[32], B[32], m, n;
unsigned C, D, Rk, Line;
unsigned Cnt(0), Ans(0);
int A;
//  inline void Clr() {}
void Ins(int i, unsigned Val) {
  unsigned Highest(0x3f3f3f3f);
  for (unsigned j(30); ~j; --j) if (Val & Bin[j]) {
    // printf("B %u = %u\n", j, B[j]);
    if (B[j]) Val ^= B[j], Set[i] ^= BSet[j];
    else { B[j] = Val, Highest = j; break; }
  }
  if (Highest ^ 0x3f3f3f3f) for (unsigned j(0); j <= 30; ++j)
    if (!Exi[j]) { BSet[Highest] = (Set[i] | Bin[j]), Exi[Bel[i] = j] = 1; break; }
  // printf("%u Bel %u BSet = %u\n", i, Bel[i], BSet[Bel[i]]);
}
void Delt(int i) {
  Del[i] = 1;
  if (Bel[i] == 0x3f3f3f3f) return;
  unsigned z(0x3f3f3f3f), Line(Bel[i]);
  // for (int x(0); x < Cnt; x++) printf("Set %u = %u\n", x, Set[x]);
  for (int x(0); x < Cnt; x++) if ((!Del[x]) && (Bel[x] == 0x3f3f3f3f) && (Set[x] & Bin[Line])) { z = x; break; }
  // printf("Line %u Rep %u\n", Line, z);
  if (z ^ 0x3f3f3f3f) {// Replace i by z
    Bel[z] = Line;
    unsigned t(Set[z] ^ Bin[Line]);
    for (unsigned x(0); x < Cnt; ++x) if (Set[x] & Bin[Line]) Set[x] ^= t;
    for (unsigned x(0); x <= 30; ++x) if (BSet[x] & Bin[Line]) BSet[x] ^= t;
    return;
  }
  unsigned XPos(0x3f3f3f3f), Xor, XSet;
  for (unsigned x(0); x <= 30; ++x) if (BSet[x] & Bin[Line]) {
    if (XPos == 0x3f3f3f3f) XPos = x, Xor = B[x], XSet = BSet[x];
    B[x] ^= Xor, BSet[x] ^= XSet;
  }
  Exi[Line] = 0;
  // Base Contain i
  // printf("XPos %u\n", XPos);
  // XSet = (Bin[Line] ^ Bin[XPos]);
  // for (unsigned x(0); x < Cnt; ++x) if ((Set[x] & XSet) && ((XSet ^ Set[x]) & XSet)) Set[x] ^= XSet;
  // for (unsigned x(0); x <= 30; ++x) if ((BSet[x] & XSet) && ((XSet ^ BSet[x]) & XSet)) BSet[x] ^= XSet;

}
signed main() {
  freopen("P4184_1.in", "r", stdin);
  freopen("P4184.my", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  memset(Bel, 0x3f, sizeof(Bel));
  Bin[0] = 1;
  for (unsigned i(1); i <= 30; ++i) Bin[i] = (Bin[i - 1] << 1);
  // for (unsigned i(0); i <= 30; ++i) printf("Bin %u = %u\n", i, Bin[i]);
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    if (!(i % 10000)) fprintf(stderr, "Now %u\n", i);
    A = RDsg(), Ans = 0;
    if (A < 0) D = -A, Delt(a[D].back()), a[D].pop_back();
    else D = A, a[D].push_back(Cnt), Ins(Cnt++, D);
    // printf("Linear Basis:");
    // for (unsigned j(30); ~j; --j) if (B[j]) printf("%u ", B[j]); putchar(0x0A);
    // for (unsigned j(0); j < 4; ++j) printf("BSet[%u] = %u\n", j, BSet[j]);
    for (unsigned j(30); ~j; --j) if (B[j] && (!(Ans & Bin[j]))) Ans ^= B[j];
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
12
13
10
-13
7
14
8
12
-7
8
-8
11
-10
*/