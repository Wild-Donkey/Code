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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node *Son[2], *Fa, *Father;
  unsigned Size;
  inline void Udt() {
//    printf("Udt %u LR %u, %u\n", this, Son[0], Son[1]);
    Size = 1 + (Son[0] ? Son[0]->Size : 0) + (Son[1] ? Son[1]->Size : 0);
  }
  inline void Rotate() {
//    printf("Rotate %u Fa %u\n", this, Fa);
    char Chirality(this == Fa->Son[1]);
    Node* Cur(Fa);
    Fa = Cur->Fa;
    if(Cur->Fa) {
//      printf("FaFa %u SonS %u %u\n", Fa, Fa->Son[0], Fa->Son[1]);
      char ChiraC(Cur == Fa->Son[1]);
      if(Fa->Son[ChiraC] == Cur) Fa->Son[ChiraC] = this;
    }
    Cur->Son[Chirality] = Son[Chirality ^ 1];
    if(Son[Chirality ^ 1]) Son[Chirality ^ 1]->Fa = Cur;
    Son[Chirality ^ 1] = Cur, Cur->Fa = this;
    Cur->Udt(), Udt();
  }
  inline void Splay() {
//    printf("Splay %u\n", this);
    while (Fa && Fa->Fa) {
      char Chira1(this == Fa->Son[1]), Chira2(Fa == Fa->Fa->Son[1]);
      if((Fa->Son[Chira1] != this) || (Fa->Fa->Son[Chira2] != Fa)) break;
//      printf("%u -> %u -> %u\n", this, Fa, Fa->Fa);
      if(Chira1 ^ Chira2) Rotate(); else Fa->Rotate();
      Rotate();
    }
    if((Fa) && ((Fa->Son[0] == this) || (Fa->Son[1] == this))) Rotate();
  }
  inline void Access() {
    Splay(), Son[1] = NULL, Udt();
    while (Fa) Fa->Splay(), Fa->Son[1] = this, Rotate();
  }
}N[200005];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(0); i < n; ++i) N[i].Father = N[i].Fa = N + min(i + RD(), n);
//  for (unsigned i(0); i < n; ++i) printf("Fa %u(%u) = %u\n", i, N + i, N[i].Father - N);
  m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD();
    Node* Cur(N + RD());
    if(A & 1) {
      Cur->Access();
      printf("%u\n", Cur->Size - 1);
    } else {
      Cur->Father->Access(), Cur->Splay();
      Cur->Father = Cur->Fa = min(Cur + RD(), N + n);
    }
  }
//  }
  return Wild_Donkey;
}

