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
char Blc[4][8], S[5];
struct Node {
  Node* To[26];
}N[100005], * CntN(N);
inline void Calc(char Fs, char Sc, char Th, char Fo) {
  Node* Cur(N), * Cur1, * Cur2, * Cur3;
  for (char i1(0); i1 < 6; ++i1) {
    if (!(Cur->To[Blc[Fs][i1]])) Cur->To[Blc[Fs][i1]] = ++CntN;
    Cur1 = Cur->To[Blc[Fs][i1]];
    for (char i2(0); i2 < 6; ++i2) {
      if (!(Cur1->To[Blc[Sc][i2]])) Cur1->To[Blc[Sc][i2]] = ++CntN;
      Cur2 = Cur1->To[Blc[Sc][i2]];
      for (char i3(0); i3 < 6; ++i3) {
        if (!(Cur2->To[Blc[Th][i3]])) Cur2->To[Blc[Th][i3]] = ++CntN;
        Cur3 = Cur2->To[Blc[Th][i3]];
        for (char i4(0); i4 < 6; ++i4) {
          if (!(Cur3->To[Blc[Fo][i4]])) Cur3->To[Blc[Fo][i4]] = ++CntN;
        }
      }
    }
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (char i(0); i < 4; ++i) {
    scanf("%s", Blc[i]);
    for (char j(0); j < 6; ++j) Blc[i][j] -= 'A';
  }
  for (char i1(0); i1 < 4; ++i1) {
    for (char i2(0); i2 < 4; ++i2) if (i2 ^ i1) {
      for (char i3(0); i3 < 4; ++i3) if ((i3 ^ i1) && (i3 ^ i2)) {
        for (char i4(0); i4 < 4; ++i4) if ((i4 ^ i1) && (i4 ^ i2) && (i4 ^ i3)) {
          Calc(i1, i2, i3, i4);
        }
      }
    }
  }
  for (char i(0); i < n; ++i) {
    scanf("%s", S);
    Node* Cur(N);
    char Len(strlen(S)), Flg(0);
    for (char j(0); j < Len; ++j) {
      if (!Cur->To[S[j] - 'A']) { Flg = 1;break; }
      Cur = Cur->To[S[j] - 'A'];
    }
    printf(Flg ? "NO\n" : "YES\n");
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}