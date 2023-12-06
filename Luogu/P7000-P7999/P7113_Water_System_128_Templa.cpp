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
template <typename TNum>
inline void Prt(TNum x) {
  char Stack[50], *STop(Stack);
  while (x > 0) *(++STop) = (x % 10) + '0', x /= 10;
  if (STop == Stack) {
    putchar('0');
    return;
  }
  while (STop > Stack) putchar(*(STop--));
}
template <typename TNum>
TNum Gcd(TNum x, TNum y) {
  TNum TmpG(x);
  while (y > 0) TmpG = x, x = y, y = TmpG % y;
  return x;
}
template <typename TNum>
struct Div {
  TNum Up, Down;
  inline Div<TNum> operator+(Div<TNum> x) {
    Div<TNum> TmpP(*this);
    TNum G(Gcd<TNum>(Down, x.Down));
    x.Down = x.Down / G, Down = Down / G;
    TmpP.Up = (x.Up * Down) + (Up * x.Down);
    Down *= G;
    TmpP.Down = x.Down * Down;
    G = Gcd<TNum>(TmpP.Up, TmpP.Down);
    TmpP.Up /= G, TmpP.Down /= G;
    return TmpP;
  }
  inline Div<TNum> Di(TNum x);
  inline void Set(TNum x) { Down = 1, Up = x; }
};
void Prtd(Div<unsigned __int128>& x) {
  Prt<unsigned __int128>(x.Up), putchar(' '), Prt<unsigned __int128>(x.Down),
      putchar(0x0A);
}
template <typename TNum>
inline Div<TNum> Div<TNum>::Di(TNum x) {
  Div<TNum> TmpP(*this);
  TNum G(Gcd<TNum>(Up, x));
  TmpP.Up /= G, x /= G, TmpP.Down *= x;
  return TmpP;
}
struct Node {
  vector<Node*> E;
  Div<unsigned __int128> Val;
  unsigned Idg, Odg;
} N[100005], *Q[100005], *End[100005];
unsigned n, m;
unsigned Hd(0), Tl(0), CntEn(0);
unsigned A, B, C, D;
signed main() {
  n = RD(), m = RD();
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
  for (unsigned i(m + 1); i <= n; ++i) N[i].Val.Set(0);
  while (Hd < Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i : Cur->E)
      if (!(--(i->Idg))) Q[++Tl] = i;
  }
  for (unsigned i(1); i <= n; ++i) {
    // printf("Cur %u Odg %u Val ", Q[i] - N, Q[i]->Odg), Prtd(Q[i]->Val);
    if (!(Q[i]->Odg)) continue;
    Div<unsigned __int128> No(Q[i]->Val.Di(Q[i]->Odg));
    for (auto j : Q[i]->E) j->Val = j->Val + No;
  }
  for (unsigned i(1); i <= CntEn; ++i) Prtd(End[i]->Val);
  return 0;
}
/*
293845623 123489763

10 1
4 2 3 4 5
3 6 7 8
3 7 10 8
1 7
2 8 10
2 8 9
2 9 8
1 10
1 10
0

*/