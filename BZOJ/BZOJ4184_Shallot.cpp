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
signed main() {
  // freopen("P4184_1.in", "r", stdin);
  // freopen("P4184_1.my", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Bin[0] = 1, memset(Bel, 0x3f, (n + 1) << 2);
  for (unsigned i(1); i <= 30; ++i) Bin[i] = (Bin[i - 1] << 1);
  for (unsigned i(0); i <= 30; ++i) Pos[i] = Siz[i] = i;
  for (unsigned i(1); i <= n; ++i) {
    A = RDsg(), Ans = 0;
    if (A < 0) {
      D = -A, Del[Rk = a[D].back()] = 1, a[D].pop_back();
      printf("Del %u at %u Line %u\n", D, Rk, Bel[Rk]);
      if (Bel[Rk] < 0x3f3f3f3f) {//Line:Posi XPos:Posi
        Line = Bel[Rk];
        char Flg(0);
        while (Span[Line].size()) {
          unsigned Cur(Span[Line].back());
          if ((!Del[Cur]) && (Bel[Cur] >= 0x3f3f3f3f)) {
            Flg = 1, BSet[Siz[Line]] = Set[Cur], B[Siz[Line]] = Pri[Cur], Bel[Cur] = Line, Span[Line].pop_back();break;
          }
          Span[Line].pop_back();
        }
        if (!Flg) {
          printf("No Flg\n");
          unsigned Xor(0), XPos(0x3f3f3f3f), XSet(0), LB(), RB;
          for (unsigned j(0); j <= 30; ++j) if (BSet[j] & Bin[Line]) {//j:Size
            if (XPos >= 0x3f3f3f3f) XPos = Pos[j], Xor = B[j], XSet = BSet[j];
            B[j] ^= Xor, BSet[j] ^= XSet;
            // printf("Xor %u O(%u) S(%u)\n", j, B[j], BSet[j]);
          }
          swap(Siz[XPos], Siz[Line]);
          Pos[Siz[XPos]] = XPos, Pos[Siz[Line]] = Line;
        }
      }
    }
    else {
      a[D = A].push_back(++Cnt);
      char Flg(0);
      Set[Cnt] = 0, Pri[Cnt] = D;
      printf("Add %u %u\n", D, Cnt);
      for (unsigned j(30); ~j; --j) if (D & Bin[j]) {//j:Size
        // Span[j].push_back(Cnt);
        if (B[j]) D ^= B[j], Set[Cnt] ^= BSet[j];
        else { Flg = 1, B[j] = D, Bel[Cnt] = Pos[j], BSet[j] = (Set[Cnt] ^= Bin[Pos[j]]); break; }
      }
      if (!D) for (unsigned j(30); ~j; --j) if (Set[Cnt] & Bin[j]) Span[j].push_back(Cnt);
    }
    // printf("BSet 28 %u\n", BSet[28]);
    // for (unsigned i(30); ~i; --i) if (BSet[i] & Bin[28]) printf("%u ", i); putchar(0x0A);
    printf("Linear Basis:");
    for (unsigned j(30); ~j; --j) if (B[j]) printf("%u ", B[j]); putchar(0x0A);
    // printf("Changed:");
    // for (unsigned j(0); j <= 30; ++j) printf("%u ", Pos[j]); putchar(0x0A);
    for (unsigned j(30); ~j; --j) if (B[j] && (!(Ans & Bin[j]))) Ans ^= B[j];
    printf("%u\n", Ans);
  }
  // for (unsigned i(0); i <= 30; ++i) { printf("Span[%u]:", i); for (auto j : Span[i]) printf("%u ", j); putchar(0x0A); }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
5
1
3
2
-1
-3
4
4
6
2
-4
804966563 462804480 142037845 84649062 56671664 31364915 11081142 6334661 2296913 1380907 964562 449251 247371 74228 48551 16953 10446 6214 3317 1049 699 485 158 75 59 16 11 6 3
804966563 462804480 142037845 84649062 56671664 31364915 11081142 6334661 2296913 1380907 964562 449251 247371 74228 48551 16953 10446 6214 3317 1049 699 485 158 75 59 16 11 6 3
804966563 ^ 462804480 = 879691427
879691427 ^ 142037845 = 1008227830
1008227830 ^ 56671664 = 1064888390
1064888390 ^ 11081142 = 1070726640
1070726640 ^ 2296913 = 1072886177
1072886177 ^ 964562 = 1073497715
1073497715 ^ 247371 = 1073709112
1073709112 ^ 16953 = 1073725953
1073725953 ^ 10446 = 1073736399
1073736399 ^ 6214 = 1073738377
1073738377 ^ 3317 = 1073741436
1073741436 ^ 485 = 1073741721
1073741721 ^ 75 = 1073741778
1073741778 ^ 59 = 1073741801
1073741801 ^ 16 = 1073741817
 11 6 3
84649062 31364915 6334661 1380907 449251 74228 48551 1049 699 158
*/