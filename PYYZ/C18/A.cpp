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
const double Sin(sin(1)), Cos(cos(1));
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
struct Pnt {
  double Hor, Ver;
  unsigned R, Val;
  inline void Rotate() { double Tmp(Hor); Hor = Hor * Cos - Ver * Sin, Ver = Tmp * Sin + Ver * Cos; }
  inline double Dis(const Pnt* x) {
    double Dx(Hor - x->Hor), Dy(Ver - x->Ver);
    return sqrt(Dx * Dx + Dy * Dy);
  }
  inline const char operator < (const Pnt& x) const { return R < x.R; }
  inline void Prt() { printf("(%lf, %lf)\n", Hor, Ver); }
}P[100005];
struct Node {
  vector <Node*> Son;
  unsigned f, Val;
  char Vis;
  inline void DFS() {
    Vis = 1;
    unsigned Tmp(0);
    for (auto i : Son) i->DFS(), Tmp += i->f;
    f = max(Val, Tmp);
  }
}N[100005];
set <pair<double, unsigned> > S;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  // printf("Sin %lf Cos %lf\n", Sin, Cos);
  for (unsigned i(1); i <= n; ++i) P[i].Hor = RD(), P[i].Ver = RD(), P[i].R = RD(), P[i].Val = RD(), P[i].Rotate();// P[i].Prt();
  sort(P + 1, P + n + 1);
  for (unsigned i(1); i <= n; ++i) N[i].Val = P[i].Val;
  for (unsigned i(1); i <= n; ++i) {
    set <pair<double, unsigned> >::iterator It(S.lower_bound(make_pair(P[i].Hor, i))), Bac(It);
    if (Bac != S.begin()) {
      --Bac;
      while (P[i].Hor - (*Bac).first <= P[i].R) {
        if (P[i].Dis(P + (*Bac).second) < P[i].R) {
          N[i].Son.push_back(N + (*Bac).second);
          if (Bac != S.begin()) S.erase(Bac--);
          else { S.erase(Bac); break; }
        }
        else {
          if (Bac != S.begin()) --Bac;
          else break;
        }
      }
    }
    while ((It != S.end()) && ((*It).first - P[i].Hor <= P[i].R)) {
      if (P[i].Dis(P + (*It).second) < P[i].R) N[i].Son.push_back(N + (*It).second), S.erase(It++);
      else ++It;
    }
    S.insert(make_pair(P[i].Hor, i));
  }
  for (Node* i(N + n); i > N; --i) if (!(i->Vis)) i->DFS(), Ans += i->f;
  printf("%u\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
(0.841471, 0.540302)
3
3 4 2 3
6 4 7 5
9 4 1 4
1.620906 - 3.365884 = -1.744978
2.524413 + 2.161208 = 4.685621
*/