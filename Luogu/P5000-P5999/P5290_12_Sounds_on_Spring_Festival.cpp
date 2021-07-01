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
using namespace std;
inline int RD() {
  char ich(getchar());
  unsigned intmp(0);
  while ((ich < '0') || (ich > '9')) {
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp = (intmp << 3) + (intmp << 1) + ich - '0';
    ich = getchar();
  }
  return intmp;
}
unsigned n, Stack[200005], Pos, Bin[20], Log[200005], A;
unsigned long long Ans(0);
struct Heap {
  Heap *LS, *RS, *Fa;
  unsigned Value;
}H[400005], *CntH(H), *HP;
struct Node {
  Node *Son, *Bro;
  Heap *Value;
  unsigned Size;
}N[200005];
void Up (Heap *x) {
  if(x->Fa) {
    if(x->Fa->Value < x->Value) {
      swap(x->Fa->Value, x->Value);
      Up(x->Fa);
    }
  }
}
void Down(Heap *x) {
  if(x->RS) {
    if(x->LS->Value < x->RS->Value) {
      if(x->RS->Value > x->Value) {
        swap(x->Value, x->RS->Value);
        Down(x->RS);
      }
    } else {
      if(x->LS->Value > x->Value) {
        swap(x->Value, x->LS->Value);
        Down(x->LS);
      }
    }
  } else {
    if(x->LS) {
      if(x->LS->Value > x->Value) {
        swap(x->Value, x->LS->Value);
        Down(x->LS);
      }
    }
  }
}
Heap *Find(Heap *x, unsigned L, unsigned R) {
  if(L == R) return x;
  register unsigned Mid((L + R) >> 1);
  if(Pos <= Mid) {
    if(!x->LS) x->LS = ++CntH, x->LS->Value = 0, x->LS->Fa = x;
    return Find(x->LS, L, Mid);
  } else {
    if(!x->RS) x->RS = ++CntH, x->RS->Value = 0, x->RS->Fa = x;
    return Find(x->RS, Mid + 1, R); 
  }
}
void DFS(Node *x) {
  if(!(x->Son)) return;
  register Node *now(x->Son), *Tmp(now);
  register unsigned Pop(0);
  while (now) {
    DFS(now);
    if(now->Size > Tmp->Size) {
      Pop = max(Pop, Tmp->Size);
      Tmp = now;
    }
    if(Tmp != now) Pop = max(Pop, now->Size);
    now = now->Bro;
  }
  now = x->Son;
  for (register unsigned i(1); i <= Pop; ++i) {
    Stack[i] = 0;
  }
  while (now) {
    for (register unsigned i(1); i <= Pop && now->Size; ++i) {
      Stack[i] = max(Stack[i], now->Value->Value);
      Pos = now->Size - Bin[Log[now->Size]];
      HP = Find(now->Value, 0, Bin[Log[now->Size]] - 1);
      swap(HP->Value, now->Value->Value);
      HP->Value = 0;
      Down(now->Value);
      --(now->Size);
    }
    now = now->Bro;
  }
  Stack[++Pop] = x->Value->Value;
  for (register unsigned i(1); i <= Pop; ++i) {
    ++(Tmp->Size);
    Pos = Tmp->Size - Bin[Log[Tmp->Size]];
    HP = Find(Tmp->Value, 0, Bin[Log[Tmp->Size]] - 1);
    HP->Value = Stack[i];
    Up(HP);
  }
  x->Value = Tmp->Value;
  x->Size = Tmp->Size;
  return;
}
int main() {
  n = RD();
  for (register unsigned i(1), j(0); i <= n; i <<= 1, ++j) {
    Bin[j] = i, Log[i] = j;
  }
  for (register unsigned i(1); i <= n; ++i) {
    Log[i] = max(Log[i - 1], Log[i]);
  }
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Value = ++CntH;
    N[i].Value->Value = RD();
    N[i].Size = 1;
  }
  for (register unsigned i(2); i <= n; ++i) {
    A = RD();
    N[i].Bro = N[A].Son;
    N[A].Son = N + i;
  }
  DFS(N + 1);
  while (N[1].Size) {
    Pos = N[1].Size - Bin[Log[N[1].Size]];
    Ans += Find(N[1].Value, 0, Bin[Log[N[1].Size]] - 1)->Value;
    --N[1].Size;
  }
  printf("%llu\n", Ans);
  return 0;
}
