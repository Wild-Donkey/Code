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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Last(0);
bool b[10005];
struct Node {
  Node *Fa, *LS, *RS;
  unsigned Value, Size, Count;
}N[100005], *CntN(N);
inline void Clr() {}
inline void Rotate(Node *x) {
  if (x->Fa) {
    if(x ^ (x->Fa->LS)) { // Right Son, Zag 
      
    }
    else {                // Left Son, Zig
      
    }
    if(x->Fa->Fa) {
      
    }
  }
  return;
} 
Node *Splay(Node *x) {
  while (x->Fa) {
    if(x->Fa->Fa) {
      if() {
        
      }
    }
    else {
      Rotate(x);
    }
  }
  return x;
}
Node *Find(Node *x, unsigned &y) {
  if(y < x->Value) {
    if(x->LS) {
      return Find(x->LS, y);
    }
    else {
      return NULL;
    }
  }
  if(y > x->Value) {
    if(x->RS) {
      return Find(x->RS, y);
    }
    else {
      return NULL;
    }
  }
  return x;
}
void Insert(Node *x, unsigned &y) {
  ++(x->Size);
  if(y < x->Value) {
    if(x->LS) {
      return Insert(x->LS, y);
    }
    else {
      x->LS = ++CntN;
      CntN->Fa = x;
      CntN->Value = y;
      CntN->Size = 1;
      CntN->Count = 1;
      return; 
    }
  }
  if(y > x->Value) {
    if(x->RS) {
      return Insert(x->RS, y);
    }
    else {
      x->RS = ++CntN;
      CntN->Fa = x;
      CntN->Value = y;
      CntN->Size = 1;
      CntN->Count = 1;
      return; 
    }
  }
  ++(x->Count);
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    Insert(N, &(RD()));
  }
  for (register unsigned i(1); i <= m; ++i) {
    
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



