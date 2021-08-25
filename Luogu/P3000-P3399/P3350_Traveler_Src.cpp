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
inline unsigned short RD() {
  unsigned short intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned Dis[20005], Complexity(0), Befr;
unsigned short Hr[20005], Ve[20005];
unsigned short m, n, nm, A, B, C, D;
unsigned long long TM[10];
unsigned q, Prt[100005], Cnt(0), Hd, Tl;
unsigned Pos(unsigned short x, unsigned short y) { return (x - 1) * m + y - 1; }
struct Square;
struct Node {
  unsigned short Globalx, Globaly;
  char Inque;
  Square* Bel;
} N[20005], * Q[10000005];
unsigned Pos(Node* x) { return (x->Globalx - 1) * m + x->Globaly - 1; }
struct Square {
  Square* LS, * RS;
  unsigned short Width, Height, LUx, LUy, Mid;
  Node** Line;
  unsigned** List;
  inline int GlobalNum(const int x, const int y) {
    return Pos(LUx + x - 1, LUy + y - 1);
  }
  inline int Num(const int x, const int y) {
    return (x - LUx) * Width + y - LUy;
  }
  inline int Num(Node* Now) {
    return (Now->Globalx - LUx) * Width + Now->Globaly - LUy;
  }
} S[20005], * CntS(S);
struct Ques {
  unsigned A, B, NumQ;
}Quest[100005], QTmp[100005];
struct Dij {
  unsigned Fst, Scd;
  Dij(unsigned x, unsigned y) { Fst = x, Scd = y; }
  inline const char operator<(const Dij& x) const { return this->Scd > x.Scd; }
};
priority_queue <Dij> DijQ;
void Dijkstra(Node* Now) {
  // printf("%u at (%u, %u) from %u\n", Now - N, Now->Globalx, Now->Globaly, Now->Bel - S);
  register Square* Sq(Now->Bel);
  register Node* Cur;
  register unsigned CurD, * CDP;
  Dis[Pos(Now)] = 0, DijQ.push(Dij(Now - N, 0));
  while (DijQ.size()) {
    ++Complexity;
    Cur = N + DijQ.top().Fst, Cur->Inque = 0, DijQ.pop();
    // printf("Cur %u\n", Cur - N);
    if (Now->Globalx > Sq->Width) {
      if (*(CDP - Sq->Width) > CurD + Ve[Cur - N - m]) {
        *(CDP - Sq->Width) = CurD + Ve[Cur - N - m];
        if (!((Cur - m)->Inque)) DijQ.push(Dij(Cur - m - N, *(CDP - Sq->Width))), (Cur - m)->Inque = 1;
      }
    }
    if (Cur->Globalx + 1 < Sq->LUx + Sq->Height) {
      if (*(CDP + Sq->Width) > CurD + Ve[Cur - N]) {
        *(CDP + Sq->Width) = CurD + Ve[Cur - N];
        if (!((Cur + m)->Inque)) DijQ.push(Dij(Cur + m - N, *(CDP + Sq->Width))), (Cur + m)->Inque = 1;
      }
    }
    if (Cur->Globaly > Sq->LUy) {
      if (*(CDP - 1) > CurD + Hr[Cur - N - 1]) {
        *(CDP - 1) = CurD + Hr[Cur - N - 1];
        if (!((Cur - 1)->Inque)) DijQ.push(Dij(Cur - 1 - N, *(CDP - 1))), (Cur - 1)->Inque = 1;
      }
    }
    if (Cur->Globaly + 1 < Sq->LUy + Sq->Width) {
      if (*(CDP + 1) > CurD + Hr[Cur - N]) {
        *(CDP + 1) = CurD + Hr[Cur - N];
        if (!((Cur + 1)->Inque)) DijQ.push(Dij(Cur + 1 - N, *(CDP + 1))), (Cur + 1)->Inque = 1;
      }
    }
  }
}
void SPFA(Node* Now) {
  // printf("%u at (%u, %u) from %u Before %u\n", Now - N, Now->Globalx, Now->Globaly, Now->Bel - S, Befr);
  register Square* Sq(Now->Bel);
  register Node* Cur;
  register unsigned* CDP(Dis + Pos(Sq->LUx, Sq->LUy));
  for (register unsigned i(1); i <= Sq->Height; ++i, CDP += m - Sq->Width)
    for (register unsigned j(1); j <= Sq->Width; ++j, ++CDP)
      *CDP = ((*CDP) ? (*CDP + Befr) : 0x3f3f3f3f);
  Hd = Tl = 0, Q[++Tl] = Now, CDP = Dis + Pos(Now), *CDP = 0;
  // CDP = Dis + Pos(Sq->LUx, Sq->LUy);
  // for (register unsigned i(1); i <= Sq->Height; ++i, CDP += m - Sq->Width)
  //   for (register unsigned j(1); j <= Sq->Width; ++j, ++CDP)
  //     printf("Scd %u %u %u\n", i, j, *CDP);
  // CDP = Dis + Pos(Now);
  // if (Now->Bel - S) {
  //   for (register unsigned i(1); i <= Sq->Height; ++i, CDP += m - Sq->Width)
  //     for (register unsigned j(1); j <= Sq->Width; ++j, ++CDP)
  //       printf("Scd %u %u %u\n", i, j, *CDP);
  //   CDP = Dis + Pos(Sq->LUx, Sq->LUy);
  // }
  while (Tl ^ Hd) {
    ++Complexity;
    Cur = Q[++Hd], Cur->Inque = 0, CDP = Dis + Pos(Cur);
    if (*CDP >= 0x3f3f3f3f) printf("Over %u %u, (%u, %u)\n", *CDP, CDP - Dis, Cur->Globalx, Cur->Globaly);
    if (Cur->Globalx > Sq->LUx) {
      if (*(CDP - m) > *CDP + Ve[Cur - N - m]) {
        *(CDP - m) = *CDP + Ve[Cur - N - m];
        if (!((Cur - m)->Inque)) Q[++Tl] = Cur - m, Q[Tl]->Inque = 1;
      }
    }
    if (Cur->Globalx + 1 < Sq->LUx + Sq->Height) {
      if (*(CDP + m) > *CDP + Ve[Cur - N]) {
        *(CDP + m) = *CDP + Ve[Cur - N];
        if (!((Cur + m)->Inque)) Q[++Tl] = Cur + m, Q[Tl]->Inque = 1;
      }
    }
    if (Cur->Globaly > Sq->LUy) {
      if (*(CDP - 1) > *CDP + Hr[Cur - N - 1]) {
        *(CDP - 1) = *CDP + Hr[Cur - N - 1];
        if (!((Cur - 1)->Inque)) Q[++Tl] = Cur - 1, Q[Tl]->Inque = 1;
      }
    }
    if (Cur->Globaly + 1 < Sq->LUy + Sq->Width) {
      if (*(CDP + 1) > *CDP + Hr[Cur - N]) {
        *(CDP + 1) = *CDP + Hr[Cur - N];
        if (!((Cur + 1)->Inque)) Q[++Tl] = Cur + 1, Q[Tl]->Inque = 1;
      }
    }
  }
}
void Div(Square* Now, int x, int y, int _x, int _y) {
  Now->LUx = x, Now->LUy = y;
  Now->Height = _x - x + 1, Now->Width = _y - y + 1;
  register int Number(Now->Width * Now->Height);
  if ((Now->Height == 1) && (Now->Width == 1)) return;
  if (Now->Width < Now->Height) {  // Horizon
    Now->Mid = Now->LUx + (Now->Height >> 1);
    Div(Now->LS = ++CntS, x, y, Now->Mid - 1, _y);
    if (Now->Height > 2) Div(Now->RS = ++CntS, Now->Mid + 1, y, _x, _y);
    for (register Node* Cur(N + Pos(Now->Mid, Now->LUy)), *Des(N + Pos(Now->Mid, Now->LUy + Now->Width - 1)); Cur <= Des; ++Cur) {
      Cur->Bel = Now;
    }
  }
  else {  // Vertical
    Now->Mid = Now->LUy + (Now->Width >> 1);
    Div(Now->LS = ++CntS, x, y, _x, Now->Mid - 1);
    if (Now->Width > 2) Div(Now->RS = ++CntS, x, Now->Mid + 1, _x, _y);
    for (register Node* Cur(N + Pos(Now->LUx, Now->Mid)), *Des(N + Pos(Now->LUx + Now->Height - 1, Now->Mid)); Cur <= Des; Cur += m) {
      Cur->Bel = Now;
    }
  }
}
void Qry(Square* Now, unsigned Pre, unsigned Pro) {
  // printf("Qry %u %u %u %u %u\n", Now - S, Now->LUx, Now->LUy, Now->Width, Now->Height);
  memcpy(QTmp, Quest + Pre, (Pro - Pre + 1) * sizeof(Ques));
  register unsigned Number(Now->Height * Now->Width), NPre(Pre - 1), NPro(Pro + 1), OPre(NPre), OPro(NPro), NumA, NumB;
  Pro -= Pre, Pre = 0;
  for (register unsigned i(1), *CDP(Dis + Pos(Now->LUx, Now->LUy)); i <= Now->Height; ++i, CDP += m - Now->Width)
    for (register unsigned j(1); j <= Now->Width; ++j, ++CDP)
      *CDP = 0;// printf("(%u, %u) = (%u, %u)\n", Now->LUx + i - 1, Now->LUy + j - 1, N[CDP - Dis].Globalx, N[CDP - Dis].Globaly);
  if (Now->Width < Now->Height) {
    Dis[Pos(Now->Mid, Now->LUy)] = 0;
    for (register Node* Cur(N + Pos(Now->Mid, Now->LUy)), *Des(N + Pos(Now->Mid, Now->LUy + Now->Width - 1)); Cur <= Des; ++Cur) {
      Befr = Dis[Pos(Cur)], SPFA(Cur);
      for (register unsigned i(Pre); i <= Pro; ++i)
        Prt[QTmp[i].NumQ] = min(Dis[QTmp[i].A] + Dis[QTmp[i].B], Prt[QTmp[i].NumQ]);
    }
    for (register unsigned i(Pre); i <= Pro; ++i) {
      if (N[QTmp[i].B].Globalx < Now->Mid) Quest[++NPre] = QTmp[i];
      if (N[QTmp[i].A].Globalx > Now->Mid) Quest[--NPro] = QTmp[i];
    }
  }
  else {
    Dis[Pos(Now->LUx, Now->Mid)] = 0;
    for (register Node* Cur(N + Pos(Now->LUx, Now->Mid)), *Des(N + Pos(Now->LUx + Now->Height - 1, Now->Mid)); Cur <= Des; Cur += m) {
      Befr = Dis[Pos(Cur)], SPFA(Cur);
      for (register unsigned i(Pre); i <= Pro; ++i)
        Prt[QTmp[i].NumQ] = min(Dis[QTmp[i].A] + Dis[QTmp[i].B], Prt[QTmp[i].NumQ]);
    }
    for (register unsigned i(Pre); i <= Pro; ++i) {
      if ((N[QTmp[i].A].Globaly < Now->Mid) && (N[QTmp[i].B].Globaly < Now->Mid)) Quest[++NPre] = QTmp[i];
      if ((N[QTmp[i].A].Globaly > Now->Mid) && (N[QTmp[i].B].Globaly > Now->Mid)) Quest[--NPro] = QTmp[i];
    }
  }
  if (NPre ^ OPre) Qry(Now->LS, OPre + 1, NPre);
  if (NPro ^ OPro) Qry(Now->RS, NPro, OPro - 1);
}
int main() {
  // freopen("P3350_19.in", "r", stdin);
  // freopen("P3350.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  TM[0] = clock();
  n = RD(), m = RD(), nm = n * m;
  for (register unsigned short i(1), k(0); i <= n; ++i, ++k)
    for (register unsigned short j(1); j < m; ++j, ++k)
      Hr[k] = RD();
  for (register unsigned short i(1), k(0); i < n; ++i)
    for (register unsigned short j(1); j <= m; ++j, ++k)
      Ve[k] = RD();
  for (register unsigned short i(1), k(0); i <= n; ++i)
    for (register unsigned short j(1); j <= m; ++j, ++k)
      N[k].Globalx = i, N[k].Globaly = j;
  TM[1] = clock();
  Div(S, 1, 1, n, m);
  TM[2] = clock();
  // if (n > 100 && m > 100) Ve[1000000000] = 1;
  scanf("%u", &q);
  for (register unsigned i(1); i <= q; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    if ((A == C) && (B == D)) { Prt[i] = 0;continue; }
    if (A > C) swap(A, C), swap(B, D);
    Quest[++Cnt].A = Pos(A, B), Quest[Cnt].B = Pos(C, D);
    Quest[Cnt].NumQ = i, Prt[i] = 0x3f3f3f3f;
  }
  // for (register unsigned i(1); i <= q; ++i) {
  //   printf("NumBer %u for %u and %u\n", Quest[i + 1].NumQ, Quest[i + 1].A - N, Quest[i + 1].B - N);
  // }
  Qry(S, 1, Cnt);
  for (register unsigned i(1); i <= q; ++i) printf("%u\n", Prt[i]);
  TM[3] = clock();
  // printf("Pre %llu Div %llu Ask %llu\n", TM[1] - TM[0], TM[2] - TM[1], TM[3] - TM[2]);
  // system("pause");
  //  }
  // printf("In %u\n", Complexity);
  return Wild_Donkey;
}
