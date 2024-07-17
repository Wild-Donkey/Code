#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
const long double Ep(1e-12);
inline long double Squ (long double x) {return x * x;}
inline char Neq(long double x, long double y) {return (x + Ep < y) || (y + Ep < x); }
unsigned m, n, t;
unsigned Cnt(0), Tmp(0);
long double L, Sin, Cos, Move, Len, Scaning;
long double Ans;
struct Line {
  long double X1, X2, Y1, Y2, b, k, Val;
  inline void Rotate() {
    long double TmX, TmY;
    TmX = Y1 * Sin + X1 * Cos;
    TmY = Y1 * Cos - X1 * Sin - Move;
    X1 = TmX, Y1 = TmY;
    TmX = Y2 * Sin + X2 * Cos;
    TmY = Y2 * Cos - X2 * Sin - Move;
    X2 = TmX, Y2 = TmY;
    Val = sqrt((Squ(X2 - X1) + Squ(Y2 - Y1)) / Squ(X2 - X1));
    if(X1 > X2) swap(X1, X2), swap(Y1, Y2);
    k = (Y2 - Y1) / (X2 - X1), b = Y1 - (X1 * k);
  }
  inline void Prt() {
    printf("(%LF,%LF) (%LF,%LF) k %LF b %LF\n", X1, Y1, X2, Y2, k, b);
  }
  inline void Flip() {Y1 = -Y1, Y2 = -Y2, k = -k, b = -b;}
  inline long double Calc () const {return Scaning * k + b;}
  inline const char operator< (const Line& x) const{return Calc() < x.Calc();}
}Up[10005], Down[10005];
struct Range {
  long double Pos, Val;
  inline const char operator< (const Range& x) const{ return Pos < x.Pos;}
}UpR[20005], DownR[20005], Tot[40005];
struct Operate {
  long double Pos;
  Line* Val;
  char Type;
  inline const char operator< (const Operate& x) const{ return Pos < x.Pos;}
};
struct Node {
  Node* LS, * RS;
  Line* Mn, * Mx;
  unsigned Size;
  inline void Udt() {
    Size = LS->Size + RS->Size;
    Mn = LS->Mn, Mx = RS->Mx;
  }
  inline Node *Rotate() {
    if(!LS) return RS;
    if(!RS) return LS;
    if(Size <= 5) {if(LS) Udt(); return this;}
    if((LS->Size << 1) < RS->Size) {
      Node* Cur(RS);
      RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = LS, LS = Cur;
      Cur->Udt();
    }
    if((RS->Size << 1) < LS->Size) {
      Node* Cur(LS);
      LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = RS, RS = Cur;
      Cur->Udt();
    }
    Udt();
    return this;
  }
  inline Node *Insert(Line *x);
  inline Node *Delete(Line *x) {
//    printf("Down %u\n", this);
    --Size;
    if((!LS) && (!RS)) { if(Mn != x) printf("Cao\n"); return NULL;}
    if(RS->Mn == x || *(RS->Mn) < *x) RS = RS->Delete(x);
    else LS = LS->Delete(x);
    return Rotate();
  }
}N[20005], *Root(N), *CntN(N);
inline Node* Node::Insert (Line *x) {
  ++Size;
  if((!LS) && (!RS)) {
//    printf("Compare Leaf %LF %LF\n", Mn->Calc(), x->Calc());
    if((*Mn) < (*x)) Mx = x; else Mn = x;
    *(LS = ++CntN) = {NULL, NULL, Mn, Mn, 1};
    *(RS = ++CntN) = {NULL, NULL, Mx, Mx, 1};
    Udt();
    return this;
  }
//  printf("Compare %LF %LF\n", RS->Mn->Calc(), x->Calc()); 
  if(*(RS->Mn) < *x) RS = RS->Insert(x);
  else LS = LS->Insert(x);
  return Rotate();
}
inline void Build(Line* x, unsigned Lenx, Range* y, unsigned& Leny) {
  memset(N, 0, (CntN - N + 1) * sizeof(Node));
  Root = NULL, CntN = N, Leny = 0;
  Operate Op[Lenx << 1 + 2];
//  for (unsigned i(1); i <= Lenx; ++i) x[i].Prt(); 
  for (unsigned i(1); i <= Lenx; ++i) {
    Op[(i << 1) - 1] = {x[i].X1, x + i, 0};
    Op[i << 1] = {x[i].X2, x + i, 1};
  }
  sort(Op + 1, Op + (Lenx = (Lenx << 1)) + 1);
  Scaning = -1e10;
  for (unsigned i(1); i <= Lenx; ++i) {
//    printf("i %u Root %u\n", i, Root);
    long double Fill(0);
    if(Root && Root->Size) Fill = (Root->Mn)->Val;
//    printf("Done\n");
    if(Neq(Scaning, Op[i].Pos) && (Scaning > -9e9)) y[++Leny] = {Scaning, Fill};
//    if(Root && Root->Size) 
//      printf("Root Mn %u %LF Mx %u %LF Val %LF\n", Root->Mn - x, Root->Mn->Calc(), Root->Mx - x, Root->Mx->Calc(), Root->Mn->Val);
    Scaning = Op[i].Pos;
//    printf("%u %u %LF Val %LF\n", i, Op[i].Val - x, Op[i].Pos, Op[i].Val->Val);
    if(Op[i].Type) Root = Root->Delete(Op[i].Val);
    else {
      if(!Root) *(Root = ++CntN) = {NULL, NULL, Op[i].Val, Op[i].Val, 1};
      else Root = Root->Insert(Op[i].Val);
    }
//    if(Root) printf("Root %u Done %u\n", Root - N, Root->Size);
  }
  y[++Leny] = {Scaning, 0};
  return;
}
inline void Clr() {
  Ans = 0, n = RD();
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      Up[i].X1 = RDsg(), Up[i].Y1 = RDsg();
      Up[i].X2 = RDsg(), Up[i].Y2 = RDsg();
    }
//    for (unsigned i(1); i <= n; ++i) printf("[(%LF,%LF),(%LF,%LF)]\n", Up[i].X1, Up[i].Y1, Up[i].X2, Up[i].Y2);
    long double Len, StanB, StanK, StanX1, StanY1, StanX2, StanY2;
    StanX1 = RDsg(), StanY1 = RDsg();
    StanX2 = RDsg(), StanY2 = RDsg();
    if(StanX1 > StanX2) swap(StanX1, StanX2), swap(StanY1, StanY2); 
    Len = sqrt(Squ(StanX2 - StanX1) + Squ(StanY2 - StanY1));
    Sin = (StanY2 - StanY1) / Len;
    Cos = (StanX2 - StanX1) / Len;
    StanK = (StanY2 - StanY1) / (StanX2 - StanX1);
    StanB = StanY1 - (StanX1 * StanK);
    Move = StanB / sqrt(1 + StanK * StanK);
//    printf("Sin %LF Cos %LF Move %LF\n", Sin, Cos, Move);
    L = RD();
    unsigned Cntu(0), Cntd(0);
    for (unsigned i(1); i <= n; ++i) {
      Up[i].Rotate();// Up[i].Prt();
      if(Up[i].Y1 < 0) Down[++Cntd] = Up[i];
      else Up[++Cntu] = Up[i];
    }
    for (unsigned i(1); i <= Cntd; ++i) Down[i].Flip();
    Build(Up, Cntu, UpR, Cntu), Build(Down, Cntd, DownR, Cntd), n = 0;
    for (unsigned i(1), j(1); i <= Cntu || j <= Cntd;) {
      if(i > Cntu) {Tot[++n] = DownR[j++]; continue;}
      if(j > Cntd) {Tot[++n] = UpR[i++]; continue;}
      if(Neq(UpR[i].Pos, DownR[j].Pos)) {
        if(UpR[i].Pos < DownR[j].Pos) Tot[++n] = {UpR[i].Pos, UpR[i].Val + DownR[j - 1].Val}, ++i;
        else Tot[++n] = {DownR[j].Pos, DownR[j].Val + UpR[i - 1].Val}, ++j;
      } else Tot[++n] = {DownR[j].Pos, DownR[j].Val + UpR[i].Val}, ++j, ++i;
    }
//    printf("Up\n");
//    for (unsigned i(1); i <= Cntu; ++i) printf("%LF,%LF\n", UpR[i].Pos, UpR[i].Val); 
//    printf("\nDown\n");
//    for (unsigned i(1); i <= Cntd; ++i) printf("%LF,%LF\n", DownR[i].Pos, DownR[i].Val); 
//    printf("\Tot\n");
//    for (unsigned i(1); i <= n; ++i) printf("%LF,%LF\n", Tot[i].Pos, Tot[i].Val); putchar(0x0A);
//    printf("Done\n");
    long double Cur(0);
    for (unsigned i(1), j(1); i < n; ++i) {
      while ((j < n) && (Tot[j + 1].Pos - Tot[i].Pos <= L)) 
        Cur += Tot[j].Val * (Tot[j + 1].Pos - Tot[j].Pos), ++j;
      Ans = max(Ans, Cur + (L - Tot[j].Pos + Tot[i].Pos) * Tot[j].Val);
//      printf("%u %LF\n", i, Ans);
      Cur -= Tot[i].Val * (Tot[i + 1].Pos - Tot[i].Pos);
    }
    Cur = 0;
    for (unsigned i(n), j(n); j > 1; --j) {
      while ((i > 1) && (Tot[j].Pos - Tot[i - 1].Pos <= L)) 
        Cur += Tot[i - 1].Val * (Tot[i].Pos - Tot[i - 1].Pos), --i;
      Ans = max(Ans, Cur + (L - Tot[j].Pos + Tot[i].Pos) * Tot[i - 1].Val);
      Cur -= Tot[j - 1].Val * (Tot[j].Pos - Tot[j - 1].Pos);
    }
    printf("%.10LF\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*


*/
