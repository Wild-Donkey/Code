#include <cstdio>
#include <iostream>
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
unsigned m(1), n, A, B, t, Ans(0), Pos, Bin[20], Log[1000006];
struct Node {
  Node *LS, *RS, *Fa;
  unsigned Val;
}N[1000005], *CntN(N), *Tmp;
Node *Find(Node *x, unsigned L, unsigned R) {
//  printf("Find %u [%u, %u]\n", x - N, L, R);
  if(L == R) {return x;}
  register unsigned Mid((L + R) >> 1);
  if(Pos <= Mid) {
    if(!x->LS) x->LS = ++CntN, x->LS->Val = 0xffffffff, x->LS->Fa = x;
    return Find(x->LS, L, Mid);
  }else {
    if(!x->RS) x->RS = ++CntN, x->RS->Val = 0xffffffff, x->RS->Fa = x;
    return Find(x->RS, Mid + 1, R);
  }
}
void Down(Node *x) {
  if(x->LS && x->RS) {
    if(x->LS->Val > x->RS->Val) {
      if(x->Val > x->RS->Val) {
        swap(x->Val, x->RS->Val);
        Down(x->RS);
      }
    } else {
      if(x->Val > x->LS->Val) {
        swap(x->Val, x->LS->Val);
        Down(x->LS);
      }
    }
  } else {
    if(x->LS) {
      if(x->Val > x->LS->Val) {
        swap(x->Val, x->LS->Val);
        Down(x->LS);
      }
    }
    if(x->RS) {
      if(x->Val > x->RS->Val) {
        swap(x->Val, x->RS->Val);
        Down(x->RS);
      }
    }
  }
}
void Up(Node *x) {
  if(x->Fa) {
    if(x->Fa->Val > x->Val) {
      swap(x->Fa->Val, x->Val);
      Up(x->Fa);
    }
  }
}
int main() {
  n = RD(), N->Val = 0x3f3f3f3f; 
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j) {
    Bin[j] = i, Log[i] = j;
  }
  for (register unsigned i(1); i <= n; ++i) {
    Log[i] = max(Log[i - 1], Log[i]);
  }
  for (register unsigned i(1); i <= n; ++i) {
    A = RD();
    if(A ^ 1) {
      if(A ^ 2) {
        Pos = m - Bin[Log[m]];
        Tmp = Find(N, 0, Bin[Log[m]] - 1);
        swap(N->Val, Tmp->Val);
        Tmp->Val = 0xffffffff;
        Down(N);
      } else {
        printf("%u\n", N->Val);
      }
    } else {
      ++m, Pos = m - Bin[Log[m]];
      Tmp = Find(N, 0, Bin[Log[m]] - 1);
      Tmp->Val = RD();
      Up(Tmp);
    }
  }
  return Wild_Donkey;
}
