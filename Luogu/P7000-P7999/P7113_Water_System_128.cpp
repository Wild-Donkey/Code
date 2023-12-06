#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
inline unsigned RD() {
  unsigned TmpRD(0);
  char TmpRC(getchar());
  while ((TmpRC < '0') || (TmpRC > '9')) TmpRC = getchar();
  while ((TmpRC >= '0') && (TmpRC <= '9'))
    TmpRD = (TmpRD << 3) + (TmpRD << 1) + TmpRC - '0', TmpRC = getchar();
  return TmpRD;
}
unsigned __int128 Gcd(unsigned __int128 x, unsigned __int128 y) {
  unsigned __int128 TmpG;
  while (y > 0) TmpG = x, x = y, y = TmpG % y;
  return x;
}
inline void Prtn(unsigned __int128 x) {
  char Stack[50], *STop(Stack);
  while (x) *(++STop) = (x % 10) + '0', x /= 10;
  while (STop > Stack) putchar(*(STop--));
}
struct Div {
  unsigned __int128 Up, Down;
  inline Div operator+(Div x) {
    Div TmpP(*this);
    unsigned __int128 G(Gcd(Down, x.Down));
    x.Down = x.Down / G, Down = Down / G;
    TmpP.Up = (x.Up * Down) + (Up * x.Down);
    Down *= G;
    TmpP.Down = x.Down * Down;
    G = Gcd(TmpP.Up, TmpP.Down);
    TmpP.Up /= G, TmpP.Down /= G;
    return TmpP;
  }
  inline Div Di(unsigned __int128 x) {
    Div TmpP(*this);
    unsigned __int128 G(Gcd(Up, x));
    TmpP.Up /= G, x /= G, TmpP.Down *= x;
    return TmpP;
  }
  inline void Set(unsigned __int128 x) { Down = 1, Up = x; }
  inline void Prt() { Prtn(Up), putchar(' '), Prtn(Down), putchar(0x0A); }
};
struct Node {
  vector<Node*> E;
  Div Val;
  unsigned Idg, Odg;
} N[100005], *Q[100005], *End[100005];
unsigned n, m;
unsigned CntEn(0), Hd(0), Tl(0);
unsigned A, B, C, D;
signed main() {
  //  freopen("water3.in", "r", stdin);
  //  freopen("water.out", "w", stdout);
  n = RD(), m = RD();
  //  for (unsigned i(1); i <= 50; ++i) printf("%u %Lf\n", i, Ten[i]);
  for (unsigned i(1); i <= n; ++i) {
    N[i].Odg = RD(), N[i].Val.Set(0);
    if (!(N[i].Odg)) End[++CntEn] = N + i;
    for (unsigned j(1); j <= N[i].Odg; ++j) {
      B = RD();
      N[i].E.push_back(N + B);
      ++(N[B].Idg);
    }
  }
  for (unsigned i(1); i <= m; ++i) Q[++Tl] = N + i, N[i].Val.Set(1);
  while (Hd < Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i : Cur->E)
      if (!(--(i->Idg))) Q[++Tl] = i;
  }
  for (unsigned i(1); i <= n; ++i) {
    if (!(Q[i]->Odg)) continue;
    Div No(Q[i]->Val.Di(Q[i]->Odg));
    for (auto j : Q[i]->E) j->Val = j->Val + No;
  }
  for (unsigned i(1); i <= CntEn; ++i) End[i]->Val.Prt();
  return 0;
}