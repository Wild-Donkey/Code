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
unsigned DistPool[10000005], * TopDist(DistPool);
unsigned short Hr[20005], Ve[20005];
unsigned short m, n, nm, A, B, C, D, Hd, Tl;
unsigned long long TM[10];
unsigned Ans(0), q;
unsigned Pos(unsigned short x, unsigned short y) { return (x - 1) * m + y - 1; }
struct Square;
struct Node {
  unsigned short Globalx, Globaly, Len;
  unsigned* ButDis;
  char Inque;
  Square* Bel;
} N[20005], * LinePool[20005], * Q[65005], ** TopLine(LinePool);
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
void SPFA(Node* Now) {
  // printf("%u at (%u, %u) from %u\n", Now - N, Now->Globalx, Now->Globaly, Now->Bel - S);
  register Square* Sq(Now->Bel);
  register Node* Cur;
  register unsigned NumFld, * DistP(Now->ButDis), CurD, * CDP;
  Hd = Tl = 0, Q[++Tl] = Now, DistP[Sq->Num(Now)] = 0;
  while (Tl ^ Hd) {
    Cur = Q[++Hd], Cur->Inque = 0;
    NumFld = Sq->Num(Cur), CDP = DistP + NumFld, CurD = *CDP;
    if (NumFld >= Sq->Width) {
      if (*(CDP - Sq->Width) > CurD + Ve[Cur - N - m]) {
        *(CDP - Sq->Width) = CurD + Ve[Cur - N - m];
        if (!((Cur - m)->Inque)) Q[++Tl] = Cur - m, Q[Tl]->Inque = 1;
      }
    }
    if (Cur->Globalx + 1 < Sq->LUx + Sq->Height) {
      if (*(CDP + Sq->Width) > CurD + Ve[Cur - N]) {
        *(CDP + Sq->Width) = CurD + Ve[Cur - N];
        if (!((Cur + m)->Inque)) Q[++Tl] = Cur + m, Q[Tl]->Inque = 1;
      }
    }
    if (Cur->Globaly > Sq->LUy) {
      if (*(CDP - 1) > CurD + Hr[Cur - N - 1]) {
        *(CDP - 1) = CurD + Hr[Cur - N - 1];
        if (!((Cur - 1)->Inque)) Q[++Tl] = Cur - 1, Q[Tl]->Inque = 1;
      }
    }
    if (Cur->Globaly + 1 < Sq->LUy + Sq->Width) {
      if (*(CDP + 1) > CurD + Hr[Cur - N]) {
        *(CDP + 1) = CurD + Hr[Cur - N];
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
      Cur->ButDis = TopDist, TopDist += Number, SPFA(Cur);
    }
  }
  else {  // Vertical
    Now->Mid = Now->LUy + (Now->Width >> 1);
    Div(Now->LS = ++CntS, x, y, _x, Now->Mid - 1);
    if (Now->Width > 2) Div(Now->RS = ++CntS, x, Now->Mid + 1, _x, _y);
    for (register Node* Cur(N + Pos(Now->LUx, Now->Mid)), *Des(N + Pos(Now->LUx + Now->Height - 1, Now->Mid)); Cur <= Des; Cur += m) {
      Cur->Bel = Now;
      Cur->ButDis = TopDist, TopDist += Number, SPFA(Cur);
    }
  }
}
void Qry(Square* Now) {
  // printf("In (%u %u) %u * %u, Div %u\n", Now->LUx, Now->LUy, Now->Height, Now->Width, Now->Mid);
  // printf("%u 's Sons %u %u\n", Now - S, Now->LS - S, Now->RS - S);
  register unsigned NumA(Now->Num(A, B)), NumB(Now->Num(C, D)), Number(Now->Height * Now->Width);
  if (Now->Width < Now->Height) {
    for (register Node* Cur(N + Pos(Now->Mid, Now->LUy)), *Des(N + Pos(Now->Mid, Now->LUy + Now->Width - 1)); Cur <= Des; ++Cur) {
      if (!(Cur->ButDis)) Cur->ButDis = TopDist, TopDist += Number, SPFA(Cur);
      Ans = min(Cur->ButDis[NumA] + Cur->ButDis[NumB], Ans);
    }
    if (C < Now->Mid) return Qry(Now->LS);
    if (A > Now->Mid) return Qry(Now->RS);
  }
  else {
    for (register Node* Cur(N + Pos(Now->LUx, Now->Mid)), *Des(N + Pos(Now->LUx + Now->Height - 1, Now->Mid)); Cur <= Des; Cur += m) {
      if (!(Cur->ButDis)) Cur->ButDis = TopDist, TopDist += Number, SPFA(Cur);
      Ans = min(Cur->ButDis[NumA] + Cur->ButDis[NumB], Ans);
    }
    if ((B < Now->Mid) && (D < Now->Mid)) return Qry(Now->LS);
    if ((B > Now->Mid) && (D > Now->Mid)) return Qry(Now->RS);
  }
}
int main() {
  freopen("P3350_16.in", "r", stdin);
  freopen("P3350.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  TM[0] = clock();
  memset(DistPool, 0x3f, sizeof(DistPool));
  n = RD(), m = RD(), nm = n * m;
  for (register unsigned short i(1), k(0); i <= n; ++i, ++k) {
    for (register unsigned short j(1); j < m; ++j, ++k) {
      Hr[k] = RD();
    }
  }
  for (register unsigned short i(1), k(0); i < n; ++i) {
    for (register unsigned short j(1); j <= m; ++j, ++k) {
      Ve[k] = RD();
    }
  }
  for (register unsigned short i(1), k(0); i <= n; ++i) {
    for (register unsigned short j(1); j <= m; ++j, ++k) {
      N[k].Globalx = i, N[k].Globaly = j;
    }
  }
  TM[1] = clock();
  Div(S, 1, 1, n, m);
  TM[2] = clock();
  // if (n > 100 && m > 100) Ve[1000000000] = 1;
  scanf("%u", &q);
  for (register unsigned i(1); i <= q; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    if ((A == C) && (B == D)) { printf("0\n");continue; }
    if (A > C) swap(A, C), swap(B, D);
    Ans = 0x3f3f3f3f, Qry(S), printf("%u\n", Ans);
  }
  TM[3] = clock();
  printf("Pre %llu Div %llu Ask %llu\n", TM[1] - TM[0], TM[2] - TM[1], TM[3] - TM[2]);
  // system("pause");
  //  }
  return Wild_Donkey;
}
