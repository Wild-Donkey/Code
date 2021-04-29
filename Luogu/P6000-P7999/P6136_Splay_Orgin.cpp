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
unsigned a[100005], b[100005], m, n, RealN(0), Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Last(0);
bool Flg(0);
struct Node {
  Node *Fa, *LS, *RS;
  unsigned Value, Size, Count;
}N[1100005], *CntN(N), *Root(N);
inline void Clr() {}
inline void Point(Node *x) {
  printf("Point %u\n", x - N);
  if(!x) {
    printf("Empty Point, Oops!\n");
  }
  else {
    printf("Fa %.11u ", x->Fa - N);
    printf("Value %.11u ", x->Value);
    printf("Size %.11u ", x->Size);
    printf("Count %.11u\n", x->Count);
    printf("LS %.11u ", x->LS - N);
    if(x->LS) {
      printf("Val %.11u ", x->LS->Value);
    }
    else {
      printf("Empty    ");
    }
    printf("RS %.11u ", x->RS - N);
    if(x->RS) {
      printf("Val %.11u ", x->RS->Value);
    }
    else {
      printf("Empty    ");
    }
  }
  printf("\n\n");
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
    return x;
  }      
//    printf("%u %u %u\n", Le, a[Le], b[Le]);
  (++CntN)->Count = b[Le];// Single Point
  CntN->Size = b[Le];
  CntN->Value = a[Le];
  CntN->Fa = Father;
//  Point(CntN);
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
inline void Rotate(Node *x) {
//  printf("Rotate %u\n", x - N);
  if (x->Fa) {
    Node *Father(x->Fa);
    x->Fa = Father->Fa;
    if(Father->Fa) {  // Grandfather's 
      if(Father == Father->Fa->LS) {  // Left Son
        Father->Fa->LS = x;
      }
      else {                          // Right Son
        Father->Fa->RS = x;
      }
    }
    x->Size = x->Count;
    if(x == Father->LS) { // Left Son, Zag
      if(x->LS) {
        x->Size += x->LS->Size;
      }
      Father->LS = x->RS, x->RS = Father;
      if(Father->LS) {
        Father->LS->Fa = Father;
      }
    }
    else {                // Right Son, Zig
      if(x->RS) {
        x->Size += x->RS->Size;
      }
      Father->RS = x->LS, x->LS = Father;
      if(Father->RS) {
        Father->RS->Fa = Father;
      }
    }
    Father->Fa = x, Father->Size = Father->Count;
    if(Father->LS) {
      Father->Size += Father->LS->Size;
    }
    if(Father->RS) {
      Father->Size += Father->RS->Size;
    }
    x->Size += Father->Size;
  }
//  Point(x);
  return;
} 
void Splay(Node *x) {
//  printf("Splay %u\n", x - N);
//  Point(x);
  if(x->Fa) {
    while (x->Fa->Fa) {
      if(x == x->Fa->LS) { // Boy
        if(x->Fa == x->Fa->Fa->LS) {  // Boy & Father
          Rotate(x->Fa);
        }
        else {                        // Boy & Mother
          Rotate(x);
        }
      }
      else {                // Girl
        if(x->Fa == x->Fa->Fa->LS) {  // Girl & Father
          Rotate(x);
        }
        else {                        // Girl & Mother
          Rotate(x->Fa);
        }
      }
    }
    Rotate(x);
  }
  Root = x;
//  printf("??\n");
  return;
}
void Insert(Node *x, unsigned &y) {
//  printf("Insert %u %u\n", x - N, y);
//  Point(x);
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
      Splay(CntN);
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
      Splay(CntN);
      return; 
    }
  }
  ++(x->Count);
  Splay(x);
  return;
}
void Delete(Node *x, unsigned &y) {
//  printf("Delete %u %u\n", x - N, y);
//  Point(x);
  if(y < x->Value) {
    if(x->LS) {
      Delete(x->LS, y);
    }
//    else {
//      printf("%u %u CNMGXB\n", x - N, y);
//      Point(x);
//    }
    return;
  }
  if(y > x->Value) {
    if(x->RS) {
      Delete(x->RS, y);
    }
//    else {
//      printf("%u %u CNMGXB\n", x - N, y);
//      Point(x);
//    }
    return;
  }
  Splay(x);
  if(x->Count ^ 1) {
    --(x->Count), --(x->Size);
    return;
  }
  if(x->LS && x->RS) {    // Both Sons
    x->LS->Fa = NULL/*Delete x*/, Splay(GoRight(x->LS));// Let the biggest Node in (x->LS) (the subtree) be the new root 
//    printf("Boom?!\n");
    Root->RS = x->RS;
    x->RS->Fa = Root;                       // The right son is still the right son
    Root->Size = Root->Count + x->RS->Size;
    if(Root->LS) {
      Root->Size += Root->LS->Size; 
    }
    return;
  }
  if(x->LS) { // x is The Biggest Number
    x->LS->Fa = NULL; // x->LS is the new Root
    Root = x->LS; 
  }
  if(x->RS) { //x is The Smallest Number
    x->RS->Fa = NULL; // x->LS is the new Root
    Root = x->RS; 
  }
  return;
}
void Value_Rank(Node *x, unsigned &y, unsigned &Rank) {
//	if(Flg) {
//  	printf("Value_Rank %u %u %u\n", x - N, y, Rank);
//  	Point(x);
//	}
  if(y < x->Value) {  // Go left
//    printf("%u < %u???\n", y, x->Value);
    if(x->LS) {
      Value_Rank(x->LS, y, Rank);
    }
    return;
  }
//  printf("Then?\n");
  if(x->LS) {
    Rank += x->LS->Size;// The Left Subtree numbers
  }
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
//  printf("Rank_Value %u %u\n", x - N, y);
//  Point(x);
  if(x->LS) {
    if(y > x->LS->Size) {
      y -= x->LS->Size;
    }
    else {  // In Left Subtree
      return Rank_Value(x->LS, y);
    }
  }
  if(y > x->Count) {
    y -= x->Count;
    return Rank_Value(x->RS, y);
  }
  else {
    return Splay(x);
  }
  return;
}
void Before(Node *x, unsigned &y) {
//  printf("Before %u %u\n", x - N, y);
  if(y <= x->Value) {  // Go left
    if(x->LS) {
      return Before(x->LS, y);
    }
    while (x) {
      if(x->Value < y) {
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
//  printf("After %u %u\n", x - N, y);
//  Point(x);
  if(y > x->Value) {  // Go right
    if(x->RS) {
      return After(x->RS, y);
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
      return After(x->LS, y);
    }
  }
  return Splay(x);  // Value[x] >=  (Key+1) 
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("P6136_6.in", "r", stdin);
   freopen("std.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  m = RD();
  a[0] = 0x7f3f3f3f;
  if(n == 0) {
    a[1] = 0x7f3f3f3f;
    Build(1, 1, NULL);
  }
  else {
    for (register unsigned i(1); i <= n; ++i) {
      a[i] = RD();
    }
    sort(a + 1, a + n + 1);
    for (register unsigned i(1); i <= n; ++i) {
      if(a[i] ^ a[i - 1]) { // A new number
        b[++RealN] = 1;
        a[RealN] = a[i];
//        printf("%u %u %u\n", RealN, a[RealN], b[RealN]);
      }
      else {                // Old number
        ++b[RealN];
      }
    }
    a[++RealN] = 0x7f3f3f3f;
    b[RealN] = 1;
    Build(1, RealN, NULL);
  }
  Root = N + 1;
  for (register unsigned i(1); i <= m; ++i) {
//    if(i >= 329530) {
//    	Flg = 1;
//		}
    A = RD();
//    B = RD();
    B = RD() ^ Last;
//    printf("%u %u\n", A, B);
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
        Ans ^= Last;
        break;
      }
      case 4:{
        Rank_Value(Root, B);
        Last = Root->Value;
        Ans ^= Last;
        break;
      }
      case 5:{
        Before(Root, B);
        Last = Root->Value;
        Ans ^= Last;
        break;
      }
      case 6:{
        ++B;
        After(Root, B);
        Last = Root->Value;
        Ans ^= Last;
        break;
      }
      default :{
        printf("Because you silly!\n");
        break;
      }
    }
//    if(Flg) {
//      printf("%u\n", i);
      if(A >= 3) {
        printf("%u %u %u\n", i, A, Last);
//        printf("%u\n", Last);
//      }
    }
//  printf("%u\n", Ans);
  }
  printf("%u\n", Ans);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



