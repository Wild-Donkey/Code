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
unsigned Stack[100005], Hd(0), m, n, Cnt(0), A, D, t, TmpD(0x3f3f3f3f);
int Ans, B, C;
char TmpNT(0), TmpTg(0);
struct Node {
  Node *LS, *RS;
  int Value;
  unsigned Size;
  char Tag;
}N[100005], *PntStk[100005], *CntN(N), *Root(N), *TmpN, *TmpNF, *TmpF;
inline void Print (Node *x) {
  printf("Point %u Val %u\nReal %u Size %u\nTag %u LS %u RS %u\n\n", x - N, x->Value, x->Size, x->Tag, x->LS - N, x->RS - N);
}
Node *Build(unsigned L, unsigned R) {
  if(L == R) {
    PntStk[Hd]->LS = PntStk[Hd]->RS = NULL, PntStk[Hd]->Value = Stack[L], PntStk[Hd]->Size = 1;
    return PntStk[Hd--];
  }
  register unsigned Mid((L + R) >> 1);
  register Node *x(PntStk[Hd--]);
  x->Size = 1, x->Value = Stack[Mid];
  if(L < Mid) {
    x->LS = Build(L, Mid - 1);
    x->Size += x->LS->Size;
  } else {
    x->LS = NULL;
  }
  x->RS = Build(Mid + 1, R);
  x->Size += x->RS->Size;
  return x;
}
inline void DFS(Node *x) {
  if(x->LS) {
    DFS(x->LS);
  }
  if(!(x->Tag)) {
    PntStk[++Hd] = x;
    Stack[Hd] = x->Value;
//    printf("%u ", x->Value);
  }
  if(x->RS) {
    DFS(x->RS);
  }
}
Node *Rebuild(Node *x) {
//  printf("Rebuild %u\n", x - N);
  if(!(x->Size)) {printf("Caonima %u\n", x - N);return NULL;}
  Hd = 0;
  DFS(x);
//  putchar('\n');
  return Build(1, Hd);
}
void Insert(Node *x) {
//  printf("Insert ");
//  Print(x);
  ++(x->Size);
//  printf("x %u TmpF %u TmpT %u\n", x - N, TmpF - N, TmpTg);
  register Node *TmpofTmp(TmpF);
  register char TmpofTmpTg(TmpTg);
  TmpF = x;
  if(x->Value < B) {
    if(!(x->RS)) {
      x->RS = ++CntN;
      x->RS->Value = B;
      x->RS->Size = 1;
    } else {
      TmpTg = 1, Insert(x->RS);
    }
  } else {
    if(!(x->LS)) {
      x->LS = ++CntN;
      x->LS->Value = B;
      x->LS->Size = 1;
    } else {
      TmpTg = 0, Insert(x->LS);
    }
  }
  if(x->Size) {
//    printf("Do x %u TmpF %u TmpT %u\n", x - N, TmpofTmp - N, TmpofTmpTg);
    if((!(x->LS)) || (!(x->RS))) {
      TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;
      return;
    }
    if((x->LS->Size * 3 < x->RS->Size) || (x->RS->Size * 3 < x->LS->Size)) {
      TmpN = x, TmpNF = TmpofTmp, TmpNT = TmpofTmpTg;
      return;
    }
  }
}
void Delete(Node *x) {
  register Node *TmpofTmp(TmpF);
  register char TmpofTmpTg(TmpTg);
  TmpF = x;
  if(x->LS) {
    if(x->LS->Size >= B) {
      TmpTg = 0, x->Size -= x->LS->Size, Delete(x->LS), x->Size += x->LS->Size;
      return;
    }
    else {
      B -= x->LS->Size;
    }
  }
  if(!(x->Tag)) {
    if(B == 1) {
      if(x->Value == C) {
        x->Tag = 1, --x->Size;
      }
      return;
    }
    else --B;
  }
  if(x->RS) {
    TmpTg = 1, x->Size -= x->RS->Size, Delete(x->RS), x->Size += x->RS->Size;
    return;
  }
}
void Rank (Node *x) {
//  printf("Rank %u %u\n\n", x - N, Ans);
//  Print(x);
  if(x->Value >= B) if(x->LS) return Rank(x->LS);
  if(x->LS) Ans += x->LS->Size;
  if((!(x->Tag)) && (x->Value < B)) ++Ans;
  if(x->RS) Rank(x->RS);
//  printf("rank %u Here %u\n", Ans, x - N);
}
void Find(Node *x) {
//  printf("Find %u From %u\n", B, x - N);
  if(x->LS) {if(x->LS->Size >= B) return Find(x->LS); else B -= x->LS->Size;}
  if(!(x->Tag)) {if(B == 1) {Ans = x->Value; return;} else --B;}
  if(x->RS) return Find(x->RS);
}
int main() {
//  freopen("P3369_7.in", "r", stdin); 
//  freopen("P3369.out", "w", stdout); 
  n = RD();
  N[0].Value = 0x3f3f3f3f, N[0].Size = 1;  
  for (register unsigned i(1); i <= n; ++i) {
    A = RD();
    B = RDsg();
//    printf("%u %u %u\n", i, A, B);
    switch(A) {
      case 1:{
        TmpN = NULL, Insert(Root);
        if(TmpN) {
          if(TmpN == Root) {
            Root = Rebuild(TmpN);
            break;
          }
          if(TmpNT) {
            TmpNF->RS = Rebuild(TmpN);
          } else {
            TmpNF->LS = Rebuild(TmpN);
          }
        }
        break;
      }
      case 2:{
        Ans = 1, C = B, Rank(Root), B = Ans, TmpN = NULL, Delete(Root);
        if(TmpN) {
          if(TmpN == Root) {
            Root = Rebuild(TmpN);
            break;
          }
          if(TmpNT) {
            TmpNF->RS = Rebuild(TmpN);
          } else {
            TmpNF->LS = Rebuild(TmpN);
          }
        }
        break;
      }
      case 3:{Ans = 1, Rank(Root);break;}
      case 4:{Find(Root);break;}
      case 5:{Ans = 0, Rank(Root), B = Ans, Find(Root);break;}
      case 6:{++B, Ans = 1, Rank(Root), B = Ans, Find(Root);break;}
    }
//    if(A >= 3) if (Ans == 741921) printf("%u %u %d\n", i, A, Ans);
    if(A >= 3) printf("%d\n", Ans);
  }
  return Wild_Donkey;
}
