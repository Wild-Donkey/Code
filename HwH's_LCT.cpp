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
  char rdch(getchar() );
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
unsigned a[100005], b[100005], m, n, RealN(1), Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Last(0);
struct Node {
  Node *Fa, *LS, *RS;
  unsigned Value, Size, Count;
}N[1000005], *CntN(N), *Root(N);
inline void Clr() {}
inline void Point(Node *x) {
  printf("Point %u\n", x - N);
  if(!x) {
    printf("Empty Point, Oops!\n");
  }
  else {
    printf("Fa %u\n", x->Fa - N);
    printf("LS %u\n", x->LS - N);
    printf("RS %u\n", x->RS - N);
    printf("Value %u\n", x->Value);
    printf("Size %u\n", x->Size);
    printf("Count %u\n", x->Count);
  }
  printf("\n\n\n");
  return;
}
Node *Build(unsigned Le, unsigned Ri, Node *Father) {
//  printf("Build %u %u %u\n", Le, Ri, Father - N);
  if(Le ^ Ri) { // This Subtree is Bigger than 1
    unsigned Mid((Le + Ri) >> 1);
    Node *x(++CntN);
    x->Count = b[Mid];
    x->Size = b[Mid];
    x->Value = a[Mid];
    x->Fa = Father;
    if(Le ^ Mid) {
      x->LS = Build(Le, Mid - 1, x);
//      printf("LS %u %u\n", x->LS - N, x - N);
      x->Size += x->LS->Size; 
    }
    x->RS = Build(Mid + 1, Ri, x);
    x->Size += x->RS->Size;
  }
  else {      // Single Point
    (++CntN)->Count = b[Le];
    CntN->Size = b[Le];
    CntN->Value = a[Le];
    CntN->Fa = Father;
  }
  return CntN;
}
inline Node *GoLeft(Node *x) {
  while (x->LS) {
    x = x->LS;
  }
  return x;
}
inline Node *GoRight(Node *x) {
  while (x->RS) {
    x = x->RS;
  }
  return x;
} 

inline ll get(ll x)
{
 return tre[tre[x].fa].son[1]==x; 
}

inline void rotate(ll x)
{
  ll y=tre[x].fa,z=tre[y].fa;
  ll flag1=get(x),flag2=get(y);
  ll w=tre[x].son[flag1^1];
  
  tre[y].son[flag1]=w,tre[x].son[flag1^1]=y,tre[z].son[flag2]=x;
  tre[x].fa=z,tre[y].fa=x,tre[w].fa=y;
  
  pushup(y),pushup(x);
}

inline void Splay(ll x,ll gol)
{
  for(int fa;(fa=tre[x].fa)!=gol;rotate(x)) if(tre[fa].fa!=gol) rotate(get(x)==get(fa) ? fa : x);
  if(gol==0) rot=x;
}

//inline void pushdown(ll x)
//{
//  if(tre[x].tag)
//  {
//    std::swap(tre[x].son[1],tre[x].son[0]);
//    tre[tre[x].son[0]].tag^=1;
//    tre[tre[x].son[1]].tag^=1;
//    tre[x].tag=0;
//  }
//}

//inline void make(ll x)
//{
//  tre[x].tag^=1;
//  std::swap(tre[x].son[0],tre[x].son[1]);
//}
//
//inline void pushdown(ll x)
//{
//  if(tre[x].tag)
//  {
//    if(tre[x].son[0]) make(tre[x].son[0]);
//    if(tre[x].son[1]) make(tre[x].son[1]);
//    tre[x].tag=0;
//  }
//}

inline void updateall(ll x)
{
  if(notroot(x)) updateall(tre[x].fa);
  pushdown(x);
}

inline void Splay(ll x)
{
  updateall(x);
  ll y;
  while(notroot(x))
  {
    y=tre[x].fa;
    if(notroot(y)) rotate(get(x)==get(y) ? y : x);
    rotate(x);
  }
  pushup(x);
}

inline void access(ll x)
{
  for(int y=0;x;y=x,x=tre[x].fa)
  {
    Splay(x);
    tre[x].son[1]=y;
    pushup(x);
  }
}

inline void makeroot(ll x)
{
  access(x),Splay(x);
  tre[x].tag^=1;
  pushdown(x);
}

inline ll findroot(ll x)
{
  access(x),Splay(x);
  pushdown(x);
  while(tre[x].son[0]) pushdown(x=tre[x].son[0]);
  Splay(x);
  return x;
}

inline void split(ll x,ll y)
{
  makeroot(x);
  access(y),Splay(y);
}

inline void link(ll x,ll y)
{
  makeroot(x);
  tre[x].fa=y;
}

inline void cut(ll x,ll y)
{
  split(x,y);
  tre[y].son[0]=0;
  tre[x].fa=0;
  pushup(y);
}

inline void Rotate(Node *x) {
  Point(x);
  if (x->Fa) {
    Node *Father(x->Fa);
    x->Fa = Father->Fa;
    if(Father->Fa) {  // Grandfather
      if(Father == Father->Fa->LS) {  // Left Son
        Father->Fa->LS = x;
      }
      else {                          // Right Son
        Father->Fa->RS = x;
      }
    }
    x->Size = 0;
    if(x == Father->LS) { // Left Son, Zag
      if(x->LS) {
        x->Size += x->LS->Size;
      }
      Father->LS = x->RS, x->RS = Father;
    }
    else {                // Right Son, Zig
      if(x->RS) {
        x->Size += x->RS->Size;
      }
      Father->RS = x->LS, x->LS = Father;
    }
    Father->Fa = x, x->Size += Father->Size, Father->Size = 0;
    if(Father->LS) {
      Father->Size += Father->LS->Size;
    }
    if(Father->RS) {
      Father->Size += Father->RS->Size;
    }
    printf("Where?\n");
  }
  return;
} 
void Splay(Node *x) {
  printf("Splay %u\n", x - N);
  Point(x);
  if(x->Fa) {
    while (x->Fa->Fa) {
      if(x == x->Fa->LS) { // Boy
        if(x->Fa == x->Fa->Fa->LS) {  // Boy & Father
          Rotate(x->Fa);
        }
        else {                        // Boy & Mother
          Rotate(x);
        }
        Rotate(x);
      }
      else {                // Girl
        if(x->Fa == x->Fa->Fa->LS) {  // Girl & Father
          Rotate(x);
        }
        else {                        // Girl & Mother
          Rotate(x->Fa);
        }
        Rotate(x);
      }
    }
    Rotate(x);
  }
  Root = x;
  printf("??\n");
  return;
}
void Insert(Node *x, unsigned &y) {
  printf("Insert %u %u\n", x - N, y);
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
      Splay(x);
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
      Splay(x);
      return; 
    }
  }
  ++(x->Count);
  Splay(x);
  return;
}
void Delete(Node *x, unsigned &y) {
  printf("Delete %u %u\n", x - N, y);
  Point(x);
  if(y < x->Value) {
    if(x->LS) {
      Delete(x->LS, y);
    }
    return;
  }
  if(y > x->Value) {
    if(x->RS) {
      Delete(x->RS, y);
    }
    return;
  }
  Splay(x);
  if(x->Count ^ 1) {
    --(x->Count), --(x->Size);
    return;
  }
  x->Size = x->Count = 0; // Delete Node x
  if(x->LS && x->RS) {    // Both Sons
    x->LS->Fa = NULL, Splay(GoRight(x->LS));// Let the biggest Node in (x->LS) (the subtree) be the new root 
    Root->RS = x->RS;
    x->RS->Fa = Root;                       // The right son is still the right son 
    Root->Size = Root->LS->Size + Root->RS->Size;
    return;
  }
  if(x->LS) {
    
  }
  if(x->RS) {
    
  }
  return;
}
void Value_Rank(Node *x, unsigned &y, unsigned &Rank) {
  if(y < x->Value) {  // Go left
    if(x->LS) {
      Value_Rank(x->LS, y, Rank);
    }
    return;
  }
  Rank += x->LS->Size;// The Left Subtree numbers
  if(y > x->Value) {  // Go right
    Rank += x->Count; // Mid Point numbers
    if(x->RS) {
      Value_Rank(x->RS, y, Rank);
    }
    return;
  }
  return;
}
void Rank_Value(Node *x, unsigned &y) {
  if(y > x->LS->Size) {
    y -= x->LS->Size;
    if(y > x->Count) {
      y -= x->Count;
      return Rank_Value(x->LS, y);
    }
    else {
      return Splay(x);
    }
  }
  else {  // In Left Subtree
    return Rank_Value(x->LS, y);
  }
}
void Before(Node *x, unsigned &y) {
  if(y < x->Value) {  // Go left
    if(x->LS) {
      return Before(x->LS, y);
    }
    while (x) {
      if(x->Value <= y) {
        return Splay(x);
      }
      x = x->Fa;
    }
    printf("WDNMD!\n"); 
    return;
  }
  if(y > x->Value) {  // Go right
    if(x->RS) {
      return Before(x->RS, y);
    }
  }
  return Splay(x);  // Value[x] <=  (Key-1) 
}
void After(Node *x, unsigned &y) {
  if(y > x->Value) {  // Go right
    if(x->RS) {
      return Before(x->RS, y);
    }
    while (x) {
      if(x->Value >= y) {
        return Splay(x);
      }
      x = x->Fa;
    }
    printf("WDNMD!\n"); 
  }
  if(y < x->Value) {  // Go left
    if(x->LS) {
      return Before(x->LS, y);
    }
  }
  return Splay(x);  // Value[x] >=  (Key+1) 
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
    a[i] = RD();
  }
  sort(a + 1, a + n + 1);
  for (register unsigned i(1); i <= n; ++i) {
    if(a[i] ^ a[i - 1]) { // A new number
      b[RealN] = 1;
      a[RealN] = a[i];
      printf("%u %u %u\n", RealN, a[RealN], b[RealN]);
      ++RealN;
    }
    else {                // Old number
      ++b[RealN];
    }
  }
  Build(1, RealN - 1, NULL);
  Root = N + 1;
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    B = RD() ^ Last;
    switch(A) {
      case 1:{
        Insert(Root, B);
        break;
      }
      case 2:{
        Delete(Root, B);
        break;
      }
      case 3:{
        Last = 1;
        Value_Rank(Root, B, Last);
        printf("%u\n", Last);
        break;
      }
      case 4:{
        Rank_Value(Root, B);
        Last = Root->Value;
        printf("%u\n", Last);
        break;
      }
      case 5:{
        --B; 
        Before(Root, B);
        Last = Root->Value;
        printf("%u\n", Last);
        break;
      }
      case 6:{
        ++B;
        After(Root, B);
        Last = Root->Value;
        printf("%u\n", Last);
        break;
      }
      default :{
        printf("Because you silly!\n");
        break;
      }
    }
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



