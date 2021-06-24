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
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned Hd(0), m, n, A;
int Ans, B, Stack[100005], CntStack[100005];
char TmpNT(0), TmpTg(0);
struct Node {
  Node *LS, *RS;
  int Value, Size, Cnt, RealSize;
}N[100005], *PntStk[100005], *CntN(N), *Root(N), *TmpN, *TmpNF, *TmpF;
inline void Print (Node *x) {
  printf("Point %u Val %u\nReal %u Size %u\nCnt %u LS %u RS %u\n\n", x - N, x->Value, x->RealSize, x->Size, x->Cnt, x->LS - N, x->RS - N);
}
Node *Build(unsigned L, unsigned R) {
  if(L == R) {
    PntStk[Hd]->Size = PntStk[Hd]->Cnt = CntStack[L], PntStk[Hd]->LS = PntStk[Hd]->RS = NULL, PntStk[Hd]->Value = Stack[L], PntStk[Hd]->RealSize = 1;
    return PntStk[Hd--];
  }
  register unsigned Mid((L + R) >> 1);
  register Node *x(PntStk[Hd--]);
  x->RealSize = 1, x->Value = Stack[Mid], x->Size = x->Cnt = CntStack[Mid];
  if(L < Mid) x->LS = Build(L, Mid - 1), x->RealSize += x->LS->RealSize, x->Size += x->LS->Size;
  else x->LS = NULL;
  x->RS = Build(Mid + 1, R);
  x->RealSize += x->RS->RealSize, x->Size += x->RS->Size;
  return x;
}
inline void DFS(Node *x) {
  if(x->LS) DFS(x->LS);
  if(x->Cnt) PntStk[++Hd] = x, CntStack[Hd] = x->Cnt, Stack[Hd] = x->Value;
  if(x->RS) DFS(x->RS);
}
Node *Rebuild(Node *x) {
  Hd = 0, DFS(x);
  return Build(1, Hd);
}
void Insert(Node *x) {
  ++(x->Size);
  register Node *TmpofTmp(TmpF);
  register char TmpofTmpTg(TmpTg);
  TmpF = x;
  if(x->Value == B) {++(x->Cnt);}
  else {
    if(x->Value < B) {
      if(!(x->RS)) ++(x->RealSize), x->RS = ++CntN, x->RS->Value = B, x->RS->Cnt = x->RS->RealSize = x->RS->Size = 1;
      else TmpTg = 1, x->RealSize -= x->RS->RealSize, Insert(x->RS), x->RealSize += x->RS->RealSize;
    } else {
      if(!(x->LS)) ++(x->RealSize), x->LS = ++CntN, x->LS->Value = B, x->LS->Cnt = x->LS->RealSize = x->LS->Size = 1;
      else TmpTg = 0, x->RealSize -= x->LS->RealSize, Insert(x->LS), x->RealSize += x->LS->RealSize;
    }
  }
  x->RealSize = 1;
  if(x->LS) x->RealSize += x->LS->RealSize; 
  if(x->RS) x->RealSize += x->RS->RealSize;
  if(x->RealSize > 3 && x->Size) {
    if((!(x->LS)) || (!(x->RS))) {TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;return;}
    if((x->LS->Size * 2 < x->RS->Size) || (x->RS->Size * 2 < x->LS->Size)) TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;
    if(x->RealSize * 3 > x->Size * 4) TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;
  }
}
void Delete(Node *x) {
  register Node *TmpofTmp(TmpF);
  register char TmpofTmpTg(TmpTg);
  TmpF = x;
  if(x->Value == B) {if(x->Cnt) --(x->Cnt), --(x->Size);}
  else  if(x->Value > B) {if (x->LS) TmpTg = 0, x->Size -= x->LS->Size, Delete(x->LS), x->Size += x->LS->Size;}
        else if (x->RS) TmpTg = 1, x->Size -= x->RS->Size, Delete(x->RS), x->Size += x->RS->Size;
  x->RealSize = 1;
  if(x->LS) x->RealSize += x->LS->RealSize; 
  if(x->RS) x->RealSize += x->RS->RealSize; 
  if(x->RealSize > 3 && x->Size) {
    if((!(x->LS)) || (!(x->RS))) {TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;return;}
    if((x->LS->Size * 2 < x->RS->Size) || (x->RS->Size * 2 < x->LS->Size)) {TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;return;}
    if(x->RealSize * 3 > x->Size * 4) TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;
  }
}
void Rank (Node *x) {
  if(x->LS) if(x->Value > B) return Rank(x->LS); else Ans += x->LS->Size;
  if(x->Cnt) if(x->Value < B) Ans += x->Cnt;
  if(x->RS) return Rank(x->RS);
}
void Find(Node *x) {
  if(x->LS) if(x->LS->Size >= B) return Find(x->LS); else B -= x->LS->Size;
  if(x->Cnt) if(x->Cnt >= B) {Ans = x->Value; return;} else B -= x->Cnt;
  if(x->RS) return Find(x->RS);
}
int main() {
  n = RD(), N[0].Value = 0x3f3f3f3f, N[0].Size = 1;  
  for (register unsigned i(1); i <= n; ++i) {
    A = RD(), B = RDsg();
    switch(A) {
      case 1:{
        TmpN = NULL, Insert(Root);
        if(TmpN) {
          if(TmpN == Root) {Root = Rebuild(TmpN);break;}
          if(TmpNT) TmpNF->RS = Rebuild(TmpN);
          else TmpNF->LS = Rebuild(TmpN);
        }
        break;
      }
      case 2:{
        TmpN = NULL, Delete(Root);
        if(TmpN) {
          if(TmpN == Root) {Root = Rebuild(TmpN);break;}
          if(TmpNT) TmpNF->RS = Rebuild(TmpN);
          else TmpNF->LS = Rebuild(TmpN);
        }
        break;
      }
      case 3:{Ans = 1, Rank(Root);break;}
      case 4:{Find(Root);break;}
      case 5:{Ans = 0, Rank(Root), B = Ans, Find(Root);break;}
      case 6:{++B, Ans = 1, Rank(Root), B = Ans, Find(Root);break;}
    }
    if(A >= 3) printf("%d\n", Ans);
  }
  return Wild_Donkey;
}
