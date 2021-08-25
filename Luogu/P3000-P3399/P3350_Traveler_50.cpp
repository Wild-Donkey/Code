#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned DistPool[10000005];
unsigned* TopDist(DistPool);
unsigned Hr[20005], Ve[20005];
unsigned short m, n, nm, A, B, C, D, t;
unsigned Ans(0), Tmp(0), q;
char b[10005];
unsigned Pos(unsigned short x, unsigned short y) { return (x - 1) * m + y - 1; }
struct Square;
struct Node {
  unsigned short Globalx, Globaly, Len;
  unsigned* ButDis;
  char Inque;
  Square* Bel;
} N[20005], * LinePool[20005], ** TopLine(LinePool);
struct Quu {
  Node* Nd;
  unsigned Dist;
  inline const char operator< (const Quu& x) const {
    return this->Dist > x.Dist;
  }
} QTmp;
priority_queue<Quu> Q;
struct Square {
  Square* LS, * RS;
  unsigned short Width, Height, LUx, LUy, Mid;
  Node** Line;
  inline short Cut() { return (Width < Height) ? Width : Height; }
  unsigned** List;
  inline short GlobalNum(const short x, const short y) {
    return Pos(LUx + x - 1, LUy + y - 1);
  }
  inline short Num(const short x, const short y) {
    return (x - LUx) * Width + y - LUy;
  }
  inline short Num(Node* Now) {
    return (Now->Globalx - LUx) * Width + Now->Globaly - LUy;
  }
} S[20005], * CntS(S);
inline void Print(Node* x) {
  printf("(%u, %u) from %u\n", x->Globalx, x->Globaly, x->Bel - S);
}
void Dijkstra(Node* Now) {
  // printf("%u at (%u, %u) from %u\n", Now - N, Now->Globalx, Now->Globaly, Now->Bel - S);
  register Square* Sq(Now->Bel);
  register Node* Cur;
  QTmp.Nd = Now, Now->ButDis[Sq->Num(Now)] = QTmp.Dist = 0, Q.push(QTmp);
  while (Q.size()) {
    Cur = Q.top().Nd, Q.pop(), Cur->Inque = 0;
    // printf("BFS ");
    // Print(Cur);
    if (Cur->Globalx > Sq->LUx) {
      if (Now->ButDis[Sq->Num(Cur->Globalx - 1, Cur->Globaly)] > Now->ButDis[Sq->Num(Cur)] + Ve[Pos(Cur->Globalx - 1, Cur->Globaly)]) {
        Now->ButDis[Sq->Num(Cur->Globalx - 1, Cur->Globaly)] = Now->ButDis[Sq->Num(Cur)] + Ve[Pos(Cur->Globalx - 1, Cur->Globaly)];
        if (!(N[Pos(Cur->Globalx - 1, Cur->Globaly)].Inque)) {
          QTmp.Nd = N + Pos(Cur->Globalx - 1, Cur->Globaly);
          QTmp.Dist = Now->ButDis[Sq->Num(QTmp.Nd)];
          QTmp.Nd->Inque = 1;
          Q.push(QTmp);
        }
      }
    }
    if (Cur->Globalx + 1 < Sq->LUx + Sq->Height) {
      if (Now->ButDis[Sq->Num(Cur->Globalx + 1, Cur->Globaly)] > Now->ButDis[Sq->Num(Cur)] + Ve[Pos(Cur->Globalx, Cur->Globaly)]) {
        Now->ButDis[Sq->Num(Cur->Globalx + 1, Cur->Globaly)] = Now->ButDis[Sq->Num(Cur)] + Ve[Pos(Cur->Globalx, Cur->Globaly)];
        if (!(N[Pos(Cur->Globalx + 1, Cur->Globaly)].Inque)) {
          QTmp.Nd = N + Pos(Cur->Globalx + 1, Cur->Globaly);
          QTmp.Dist = Now->ButDis[Sq->Num(QTmp.Nd)];
          QTmp.Nd->Inque = 1;
          Q.push(QTmp);
        }
      }
    }
    if (Cur->Globaly > Sq->LUy) {
      if (Now->ButDis[Sq->Num(Cur->Globalx, Cur->Globaly - 1)] > Now->ButDis[Sq->Num(Cur)] + Hr[Pos(Cur->Globalx, Cur->Globaly - 1)]) {
        Now->ButDis[Sq->Num(Cur->Globalx, Cur->Globaly - 1)] = Now->ButDis[Sq->Num(Cur)] + Hr[Pos(Cur->Globalx, Cur->Globaly - 1)];
        if (!(N[Pos(Cur->Globalx, Cur->Globaly - 1)].Inque)) {
          QTmp.Nd = N + Pos(Cur->Globalx, Cur->Globaly - 1);
          QTmp.Dist = Now->ButDis[Sq->Num(QTmp.Nd)];
          QTmp.Nd->Inque = 1;
          Q.push(QTmp);
        }
      }
    }
    if (Cur->Globaly + 1 < Sq->LUy + Sq->Width) {
      if (Now->ButDis[Sq->Num(Cur->Globalx, Cur->Globaly + 1)] > Now->ButDis[Sq->Num(Cur)] + Hr[Pos(Cur->Globalx, Cur->Globaly)]) {
        Now->ButDis[Sq->Num(Cur->Globalx, Cur->Globaly + 1)] = Now->ButDis[Sq->Num(Cur)] + Hr[Pos(Cur->Globalx, Cur->Globaly)];
        if (!(N[Pos(Cur->Globalx, Cur->Globaly + 1)].Inque)) {
          QTmp.Nd = N + Pos(Cur->Globalx, Cur->Globaly + 1);
          QTmp.Dist = Now->ButDis[Sq->Num(QTmp.Nd)];
          QTmp.Nd->Inque = 1;
          Q.push(QTmp);
        }
      }
    }
  }
}
void Div(Square* Now, short x, short y, short _x, short _y) {
  Now->LUx = x, Now->LUy = y;
  Now->Height = _x - x + 1, Now->Width = _y - y + 1;
  register short Number(Now->Width * Now->Height);
  if ((Now->Height == 1) && (Now->Width == 1)) return;
  if (Now->Width < Now->Height) {  // Horizon
    Now->Mid = Now->LUx + (Now->Height >> 1);
    Div(Now->LS = ++CntS, x, y, Now->Mid - 1, _y);
    if (Now->Height > 2) Div(Now->RS = ++CntS, Now->Mid + 1, y, _x, _y);
    for (register Node* Cur(N + Pos(Now->Mid, Now->LUy)), *Des(N + Pos(Now->Mid, Now->LUy + Now->Width - 1)); Cur <= Des; ++Cur) Cur->Bel = Now;
  }
  else {  // Vertical
    Now->Mid = Now->LUy + (Now->Width >> 1);
    Div(Now->LS = ++CntS, x, y, _x, Now->Mid - 1);
    if (Now->Width > 2) Div(Now->RS = ++CntS, x, Now->Mid + 1, _x, _y);
    for (register Node* Cur(N + Pos(Now->LUx, Now->Mid)), *Des(N + Pos(Now->LUx + Now->Height - 1, Now->Mid)); Cur <= Des; Cur += m) Cur->Bel = Now;
  }
}
void Qry(Square* Now) {
  // printf("In (%u %u) %u * %u, Div %u\n", Now->LUx, Now->LUy, Now->Height, Now->Width, Now->Mid);
  // printf("%u 's Sons %u %u\n", Now - S, Now->LS - S, Now->RS - S);
  register unsigned NumA(Now->Num(A, B)), NumB(Now->Num(C, D)), Number(Now->Height * Now->Width);
  if (Now->Width < Now->Height) {
    for (register Node* Cur(N + Pos(Now->Mid, Now->LUy)), *Des(N + Pos(Now->Mid, Now->LUy + Now->Width - 1)); Cur <= Des; ++Cur) {
      if (!(Cur->ButDis)) {
        Cur->ButDis = TopDist, TopDist += Number;
        memset(Cur->ButDis, 0x3f, (Number << 2));
        Dijkstra(Cur);
      }
      Ans = min(Cur->ButDis[NumA] + Cur->ButDis[NumB], Ans);
    }
    if (C < Now->Mid) return Qry(Now->LS);
    if (A > Now->Mid) return Qry(Now->RS);
  }
  else {
    for (register Node* Cur(N + Pos(Now->LUx, Now->Mid)), *Des(N + Pos(Now->LUx + Now->Height - 1, Now->Mid)); Cur <= Des; Cur += m) {
      if (!(Cur->ButDis)) {
        Cur->ButDis = TopDist, TopDist += Number;
        memset(Cur->ButDis, 0x3f, (Number << 2));
        Dijkstra(Cur);
      }
      Ans = min(Cur->ButDis[NumA] + Cur->ButDis[NumB], Ans);
    }
    if ((B < Now->Mid) && (D < Now->Mid)) return Qry(Now->LS);
    if ((B > Now->Mid) && (D > Now->Mid)) return Qry(Now->RS);
  }
}
int main() {
  //   freopen("P3350_16.in", "r", stdin);
  //   freopen("P3350.out", "w", stdout);
    //  t = RD();
    //  for (register unsigned T(1); T <= t; ++T){
    //  Clr();
  n = RD(), m = RD(), nm = n * m;
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j < m; ++j) {
      Hr[Pos(i, j)] = RD();
    }
  }
  for (register unsigned i(1); i < n; ++i) {
    for (register unsigned j(1); j <= m; ++j) {
      Ve[Pos(i, j)] = RD();
    }
  }
  // printf("      ");
  // for (register unsigned i(1); i <= m; ++i) {
  //   printf("%5u", i);
  // }
  // putchar('\n'), putchar('\n');
  // for (register unsigned i(1); i <= n; ++i) {
  //   printf("%5u", i);
  //   for (register unsigned j(1); j < m; ++j) {
  //     putchar('.'), printf("%5u", Hr[Pos(i, j)]);
  //   }
  //   putchar('\n');
  //   if (i < n) {
  //     for (register unsigned j(1); j <= m; ++j) {
  //       printf("%6u", Ve[Pos(i, j)]);
  //     }
  //     putchar('\n');
  //   }
  // }
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= m; ++j) {
      N[Pos(i, j)].Globalx = i, N[Pos(i, j)].Globaly = j;
    }
  }
  Div(S, 1, 1, n, m);
  q = RD();
  for (register unsigned i(1); i <= q; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    if ((A == C) && (B == D)) {
      printf("0\n");
      continue;
    }
    if (A > C) swap(A, C), swap(B, D);
    Ans = 0x3f3f3f3f, Qry(S), printf("%u\n", Ans);
  }
  // system("pause");
  //  }
  return Wild_Donkey;
}