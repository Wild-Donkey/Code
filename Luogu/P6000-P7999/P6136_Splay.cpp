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
inline unsigned RD() {    // Fast Read
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
unsigned a[100005], b[100005], m, n, RealN(0), Cnt(0), C, D, t, Tmp(0);
bool Flg(0);
struct Node {
  Node *Fa, *LS, *RS;
  unsigned Value, Size, Count;
}N[1100005], *CntN(N), *Root(N);
Node *Build(register unsigned Le, register unsigned Ri, register Node *Father) {
  if(Le ^ Ri) { // This Subtree is Bigger than 1
    unsigned Mid((Le + Ri) >> 1);
    Node *x(++CntN);
    x->Count = b[Mid];
    x->Size = b[Mid];
    x->Value = a[Mid];
    x->Fa = Father;
    if(Le ^ Mid) {
      x->LS = Build(Le, Mid - 1, x);
      x->Size += x->LS->Size;
    }
    x->RS = Build(Mid + 1, Ri, x);
    x->Size += x->RS->Size;
    return x;
  }
  (++CntN)->Count = b[Le];// Single Point
  CntN->Size = b[Le];
  CntN->Value = a[Le];
  CntN->Fa = Father;
  return CntN;
}
inline void Rotate(register Node *x) {  // 绕父旋转 
  if (x->Fa){ 
    Node *Father(x->Fa);                // 暂存父亲
    x->Fa = Father->Fa;                 // 父亲连到爷爷上 
    if(Father->Fa) {                    // Grandfather's Son (更新爷爷的儿子指针)
      if(Father == Father->Fa->LS) {    // Left Son
        Father->Fa->LS = x;
      }
      else {                            // Right Son
        Father->Fa->RS = x;
      }
    }
    x->Size = x->Count;                 // x 的 Size 的一部分 (x->Size = x->LS->Size + x->RS->Size + x->Count) 
    if(x == Father->LS) {               // x is the Left Son, Zag(x->Fa)
      if(x->LS) {
        x->Size += x->LS->Size;
      }
      Father->LS = x->RS, x->RS = Father;
      if(Father->LS) {
        Father->LS->Fa = Father;
      }
    }
    else {                              // x is the Right Son, Zig(x->Fa)
      if(x->RS) {
        x->Size += x->RS->Size;
      }
      Father->RS = x->LS, x->LS = Father;
      if(Father->RS) {
        Father->RS->Fa = Father;
      }
    }
    Father->Fa = x/*父亲的新父亲是 x*/, Father->Size = Father->Count/*Father->Size 的一部分*/;
    if(Father->LS) {                    // 处理 Father 两个儿子对 Father->Size 的贡献 
      Father->Size += Father->LS->Size;
    }
    if(Father->RS) {
      Father->Size += Father->RS->Size;
    }
    x->Size += Father->Size;            // Father->Size 更新后才能更新 x->Size 
  }
  return;
} 
void Splay(Node *x) {
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
  return;
}
void Insert(register Node *x, unsigned &y) {
  while (x->Value ^ y) {
    ++(x->Size);      // 作为加入元素的父节点, 子树大小增加 
    if(y < x->Value) {// 在左子树上 
      if(x->LS) {     // 有左子树, 往下走 
        x = x->LS;
        continue;
      }
      else {          // 无左子树, 建新节点 
        x->LS = ++CntN;
        CntN->Fa = x;
        CntN->Value = y;
        CntN->Size = 1;
        CntN->Count = 1;
        return Splay(CntN);
      }
    }
    else {            // 右子树的情况同理 
      if(x->RS) {
        x = x->RS;
      }
      else {
        x->RS = ++CntN;
        CntN->Fa = x;
        CntN->Value = y;
        CntN->Size = 1;
        CntN->Count = 1;
        return Splay(CntN); 
      }
    }
  }
  ++(x->Count), ++x->Size;  // 原来就有对应节点 
  Splay(x);                 // Splay 维护 BST 的深度复杂度 
  return;
}
void Delete(register Node *x, unsigned &y) {
  while (x->Value ^ y) {
    x = (y < x->Value) ? x->LS : x->RS;
    if(!x) {
      return;
    }
  }
  Splay(x);
  if(x->Count ^ 1) {      // Don't Need to Delete the Node
    --(x->Count), --(x->Size);
    return;
  }
  if(x->LS && x->RS) {    // Both Sons left
    register Node *Son(x->LS);
    while (Son->RS) {
      Son = Son->RS;
    }
    x->LS->Fa = NULL/*Delete x*/, Splay(Son);// Let the biggest Node in (x->LS) (the subtree) be the new root 
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
void Value_Rank(register Node *x, unsigned &y, unsigned &Rank) {
  while (x->Value ^ y) {  // Go Down
    if(y < x->Value) {    // Go Left
      if(x->LS) {
        x = x->LS;
        continue;
      }
      return;             // No more numbers smaller than y, Rank is the rank
    }
    else {                // Go Right
      if(x->LS) {
        Rank += x->LS->Size;    // The Left Subtree numbers
      }
      Rank += x->Count;         // Mid Point numbers
      if(x->RS) {
        x = x->RS;
        continue;
      }
      return;             // No more numbers bigger than y, Rank is the rank
    }
  }
  if(x->LS) {             // now, x->Value == y
    Rank += x->LS->Size;
  }
  return;
}
void Rank_Value(register Node *x, unsigned &y) {
  while (x) {
    if(x->LS) {
      if(x->LS->Size < y) {//Not in the Left
        y -= x->LS->Size;
      }
      else {            // In Left Subtree
        x = x->LS;
        continue;
      }
    }
    if(y > x->Count) {  // In Right Subtree 
      y -= x->Count;
      x = x->RS;
      continue;
    }
    return Splay(x);    // Just Look for x 
  }
}
void Before(register Node *x, unsigned &y) {
  while (x) {
    if(y <= x->Value) {   // Go left
      if(x->LS) {
        x = x->LS;
        continue;
      }
      while (x) {         // Go Up
        if(x->Value < y) {
          return Splay(x);
        }
        x = x->Fa;
      }
    }
    else {                // Go right
      if(x->RS) {
        x = x->RS;
        continue;
      }
      return Splay(x);    // Value[x] < Key
    }
  }
}
void After(register Node *x, unsigned &y) {
  while (x) {
    if(y >= x->Value) {     // Go right
      if(x->RS) {
        x = x->RS;
        continue;
      }
      while (x) {           // Go Up
        if(x->Value > y) {
          return Splay(x);
        }
        x = x->Fa;
      }
    }
    else {                  // Go left
      if(x->LS) {
        x = x->LS;
        continue;
      }
      return Splay(x);
    }
  }
}
signed main() {
  register unsigned Ans(0);  // 记录 
  n = RD();
  m = RD();
  a[0] = 0x7f3f3f3f;
  for (register unsigned i(1); i <= n; ++i) { // 原集合 
    a[i] = RD();
  }
  sort(a + 1, a + n + 1);                     // 排序 
  for (register unsigned i(1); i <= n; ++i) { // 去重 
    if(a[i] ^ a[i - 1]) { // A new number
      b[++RealN] = 1;
      a[RealN] = a[i];
    }
    else {                // Old number
      ++b[RealN];
    }
  }
  a[++RealN] = 0x7f3f3f3f;                    // 加入哨兵 
  b[RealN] = 1;
  Build(1, RealN, NULL);                      // 建树 
  Root = N + 1;                               // 初始化根 (根是第一个点, 因为递归建树是 DFS, 根是 DFS 序最小的) 
  for (register unsigned i(1), A, B, Last(0); i <= m; ++i) {
    A = RD();
    B = RD() ^ Last;
    switch(A) {   // 分别是对应的 6 个操作 
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
        After(Root, B);
        Last = Root->Value;
        Ans ^= Last;
        break;
      }
    }
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
