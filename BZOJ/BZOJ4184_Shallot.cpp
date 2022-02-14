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
unsigned Bel[500005], Set[500005], BSet[32], b[32], Bin[32], B[32], m, n;
unsigned Stack[33], STop(0);
unsigned C, D, Rk, Line;
unsigned Cnt(0), Ans(0), Tmp(0);
int A;
bitset<500005> Del
;
//  inline void Clr() {}
signed main() {
  freopen("P4184_1.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Bin[0] = 1, memset(Bel, 0x3f, (n + 1) << 2);
  for (unsigned i(1); i <= 30; ++i) Bin[i] = (Bin[i - 1] << 1);
  for (unsigned i(1); i <= n; ++i) {
    A = RDsg(), Ans = 0;
    if (A < 0) {
      D = -A, Del[Rk = a[D].back()] = 1, a[D].pop_back();
      // printf("Del %u at %u Line %u\n", D, Rk, Bel[Rk]);
      if (Bel[Rk] < 0x3f3f3f3f) {
        Line = Bel[Rk];
        char Flg(0);
        while (Span[Line].size()) {
          unsigned Cur(Span[Line].back());
          if ((!Del[Cur]) && (Bel[Cur] >= 0x3f3f3f3f)) {
            Flg = 1, b[Line] = Cur, Bel[Cur] = Line, Span[Line].pop_back();break;
          }
          Span[Line].pop_back();
        }
        if (!Flg) {
          unsigned Xor(0), XPos(0x3f3f3f3f), XSet(0), LB, RB;
          for (unsigned j(0); j <= 30; ++j) if (BSet[j] & Bin[Line]) {
            if (XPos >= 0x3f3f3f3f) XPos = j, Xor = B[j], XSet = BSet[j];
            Stack[++STop] = j;
          }
          while (STop) {
            unsigned Cur(Stack[STop--]);
            B[Cur] ^= Xor, BSet[Cur] ^= XSet;
            LB = (Bin[Line] & BSet[Cur]) >> Line;
            RB = (Bin[XPos] & BSet[Cur]) >> XPos;
            if (LB ^ RB) BSet[XPos] ^= (Bin[Line] ^ BSet[XPos]);
          }
          Span[Line].assign(Span[XPos].begin(), Span[XPos].end()), Span[XPos].clear();
          b[Line] = b[XPos], b[XPos] = 0, Bel[b[Line]] = Line;
        }
      }
    }
    else {
      a[D = A].push_back(++Cnt);
      char Flg(0);
      for (unsigned j(30); ~j; --j) if (D & Bin[j]) {
        Span[j].push_back(Cnt);
        if (B[j]) D ^= B[j], Set[Cnt] ^= BSet[j];
        else { Flg = 1, B[j] = D, Bel[b[j] = Cnt] = j, BSet[j] = (Set[Cnt] ^= Bin[j]); break; }
      }
    }
    printf("Linear Basis:");
    for (unsigned j(30); ~j; --j) if (B[j]) printf("%u ", B[j]); putchar(0x0A);
    for (unsigned j(30); ~j; --j) if (B[j] && (!(Ans & Bin[j]))) Ans ^= B[j];
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
4 6 7
*/