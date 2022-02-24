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
struct Num {
  unsigned In, Out, Val;
}List[500005];
map<unsigned, vector<unsigned> > a;
bitset<32> Exi;
unsigned Move[500005], Bel[500005], BSet[32], Bin[32], B[32], b[32], m, n;
unsigned C(0), D, Rk;
unsigned Cnt(0), Ans(0);
int A;
//  inline void Clr() {}
void Delt(int x) {
  // printf("Del a[%u] = %u Bel %u\n", x, List[x].Val, Bel[x]);
  if (Bel[x] == 0x3f3f3f3f) return;
  unsigned Line(Bel[x]), XPos(0x3f3f3f3f), Xor, XSet;
  for (unsigned i(0); i <= 30; ++i) if (BSet[i] & Bin[Line]) {
    // if (x == 584) printf("Xor B %u b %u\n", i, b[i]);
    if (XPos == 0x3f3f3f3f) XPos = i, Xor = B[i], XSet = BSet[i];
    B[i] ^= Xor, BSet[i] ^= XSet;
  }
  // printf("XPos %u\n", XPos);
  for (unsigned i(0); i <= 30; ++i) if (b[i] == x) { b[i] = b[XPos]; break; }
  b[XPos] = Exi[Line] = 0, Bel[x] = 0x3f3f3f3f;
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
    A = RDsg(), Ans = 0;
    Num* Cur;
    if (A < 0) Cur = List + a[D = -A].back(), Cur->Out = i - 1, Move[i] = Cur - List, a[D].pop_back();
    else D = A, a[D].push_back(++Cnt), List[Move[i] = Cnt] = Num{ i, 0, D };
  }
  for (auto i : a) { D = i.first;  for (auto j : i.second) List[j].Out = n; }
  for (unsigned i(1); i <= n; ++i) {
    // printf("Bel[b[25] = %u] = %u\n", b[25], Bel[b[25]]);
    // printf("Bel[654] %u Bel[652] %u\n", Bel[654], Bel[652]);
    if (!(i % 50000)) fprintf(stderr, "Now %u\n", i);
    unsigned x(Move[i]);
    Num* Cur(List + x);
    Ans = 0, D = Cur->Val;
    if ((Cur->In) ^ i) Delt(x);
    else {
      // printf("Add a[%u] = %u\n", x, Cur->Val);
      unsigned Highest(0x3f3f3f3f), TmpS(0), Line(0), TmpD(D);
      for (unsigned j(30); ~j; --j) if (D & Bin[j]) {
        if (B[j]) D ^= B[j], TmpS ^= BSet[j];
        else { b[j] = x, B[j] = D, Highest = j; break; }
      }
      // printf("Highest %u\n", Highest);
      if (Highest ^ 0x3f3f3f3f) {
        for (unsigned j(0); j <= 30; ++j) if (!Exi[j]) { Exi[Line = Bel[x] = j] = 1; break; }
        BSet[Highest] = (TmpS | Bin[Line]);
        // printf("BSet %u = %u\n", Highest, BSet[Highest]);
      }
      else {
        unsigned Last(0x3f3f3f3f);
        // printf("Bel:");
        // for (unsigned j(0); j <= 30; ++j) if (b[j]) printf("(%u, %u) ", b[j], Bel[b[j]]); putchar(0x0A);
        for (unsigned j(0); j <= 30; ++j) if (b[j] && (TmpS & Bin[Bel[b[j]]]) && (List[b[j]].Out < Last))
          Last = List[b[j]].Out, Line = Bel[b[j]], Highest = j;
        // printf("Highest %u Out %u MeOut %u\n", Highest, Last, Cur->Out);
        if (Last < Cur->Out) {
          // printf("Change a[%u] = %u To %u Set %u To %u\n", b[Highest], B[Highest], LB, BSet[Highest], (LS ^ Bin[Line]));
          Bel[b[Highest]] = 0x3f3f3f3f, Bel[b[Highest] = x] = Line, TmpS ^= Bin[Line];
          for (unsigned j(0); j <= 30; ++j) if (BSet[j] & Bin[Line]) BSet[j] ^= TmpS;
        }
      }
    }
    // printf("Linear Basis:");
    // for (unsigned j(0); j <= 30; ++j) if (B[j]) printf("%u ", B[j]); putchar(0x0A);
    // printf("BSet:");
    // for (unsigned j(0); j <= 30; ++j) if (BSet[j]) printf("%u ", BSet[j]); putchar(0x0A);
    // printf("Now Have:");
    // for (unsigned j(1); j <= Cnt; ++j) if ((List[j].In <= i) && (List[j].Out >= i)) printf("%u ", List[j].Val); putchar(0x0A);
    for (unsigned j(30); ~j; --j) if (B[j] && (!(Ans & Bin[j]))) Ans ^= B[j];
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
645

4
3
2
-3
1

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

13
13
10
13
14
15
15
14
14
14
15
15
*/