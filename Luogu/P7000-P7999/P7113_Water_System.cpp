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
unsigned long long Gcd(unsigned long long x, unsigned long long y) {
  unsigned long long TmpG;
  while (y > 0) TmpG = x, x = y, y = TmpG % y;
  return x;
}
struct Div {
  unsigned long long Up, Down;
  inline Div operator+(Div x) {
    //    printf("Pls %Lf %Lf\n", Up / Down, x.Up / x.Down);
    Div TmpP(*this);
    unsigned long long G(Gcd(Down, x.Down));
    x.Down = x.Down / G, Down = Down / G;
    TmpP.Up = (x.Up * Down) + (Up * x.Down);
    Down *= G;
    TmpP.Down = x.Down * Down;
    G = Gcd(TmpP.Up, TmpP.Down);
    TmpP.Up /= G, TmpP.Down /= G;
    //    printf("Plused %Lf %Lf\n", TmpP.Up, TmpP.Down);
    return TmpP;
  }
  inline Div Di(unsigned long long x) {
    //    printf("Divi %Lf %Lf / %u\n", Up, Down, x);
    Div TmpP(*this);
    long double G(Gcd(Up, (long double)x));
    TmpP.Up /= G, x /= G, TmpP.Down *= x;
    //    printf("Got %Lf %Lf\n", TmpP.Up, TmpP.Down);
    return TmpP;
  }
  inline void Set(unsigned long long x) { Down = 1, Up = x; }
  inline void Prt() { printf("%llu %llu\n", Up, Down); }
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
  for (unsigned i(1); i <= n; ++i)
    if (!(N[i].Idg)) Q[++Tl] = N + i, N[i].Val.Set(1);
  while (Hd < Tl) {
    Node* Cur(Q[++Hd]);
    //    printf("Cur %u\n", Cur - N);
    for (auto i : Cur->E)
      if (!(--(i->Idg))) Q[++Tl] = i;
  }
  for (unsigned i(1); i <= n; ++i) {
    if (!(Q[i]->Odg)) continue;
    //    printf("Do %u %Lf %Lf\n", Q[i] - N, Q[i]->Val.Up, Q[i]->Val.Down);
    Div No(Q[i]->Val.Di(Q[i]->Odg));
    for (auto j : Q[i]->E) j->Val = j->Val + No;
  }
  for (unsigned i(1); i <= CntEn; ++i) End[i]->Val.Prt();
  return 0;
}