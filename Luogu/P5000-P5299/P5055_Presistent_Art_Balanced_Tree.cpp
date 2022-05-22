#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline long long RD() {
  long long rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
long long OV, Ans(0);
unsigned m, n, A, B, C, D;
struct Node {
  Node* LS, *RS;
  long long Val;
  unsigned Size;
  char Flip;
  inline void Prt();
  inline void Udt() {
    Size = (LS ? LS->Size : 0) + (RS ? RS->Size : 0);
    Val = (LS ? LS->Val : 0) + (RS ? RS->Val : 0);
  }
  inline void PsDw();
  inline Node *Rotate();
  inline Node *Insert(unsigned x);
  inline Node *Delete(unsigned x);
  inline Node *Merge(Node* x);
  inline void Split(Node*& x, Node*& y, unsigned z); 
}N[40000005], *Ver[200005], *CntN(N);
inline void Node::Prt(){
  printf("Node%u: Size %u Val %lld Flg %u LS %u(%u) RS %u(%u)\n", this - N, Size, Val, Flip, LS - N, LS ? LS->Size : 0, RS - N, RS ? RS->Size : 0);
}
inline void Node::PsDw() {
  if(Flip) swap(LS, RS);
  if(LS) *(++CntN) = *LS, LS = CntN, LS->Flip ^= Flip;
  if(RS) *(++CntN) = *RS, RS = CntN, RS->Flip ^= Flip;
  Flip = 0;
}
inline Node *Node::Rotate() {
  if(!LS) return RS;
  if(!RS) return LS;
  if(Size <= 5) return this;
  if((LS->Size << 1) < RS->Size) {
    Node* Cur(RS);
//    if((!(Cur->LS)) || (!(Cur->RS))) fprintf(stderr, "Caonima\n"); 
    Cur->PsDw(), RS = Cur->RS, Cur->RS = Cur->LS;
    Cur->LS = LS, LS = Cur, Cur->Udt();
    return this;
  }
  if((RS->Size << 1) < LS->Size) {
    Node* Cur(LS);
//    if((!(Cur->LS)) || (!(Cur->RS))) fprintf(stderr, "Caonima\n");
    Cur->PsDw(), LS = Cur->LS, Cur->LS = Cur->RS;
    Cur->RS = RS, RS = Cur, Cur->Udt(); 
    return this;
  }
  return this;
}
inline Node *Node::Insert(unsigned x) {
//  printf("Insert (%u in %u) LS %u RS %u\n", x, Size, LS - N, RS - N);
  if(Size == 1) {
    *(LS = ++CntN) = {NULL, NULL, x ? Val : OV, 1, 0};
    *(RS = ++CntN) = {NULL, NULL, x ? OV : Val, 1, 0};
    Flip = 0, Val = Val + OV, Size = 2; 
    return this;
  }
//  printf("Size %u LS %u RS %u\n", Size, LS->Size, RS->Size);
  PsDw();
  if(x <= LS->Size) LS = LS->Insert(x);
  else RS = RS->Insert(x - LS->Size);
  Udt();
  return Rotate();
}
inline Node *Node::Delete(unsigned x) {
//  printf("Del"), Prt();
  if(Size == 1) return NULL;
  PsDw();
  if(x <= LS->Size) LS = LS->Delete(x);
  else RS = RS->Delete(x - LS->Size);
  Udt();
  return Rotate();
}
inline Node *Node::Merge(Node* x) {
  if(Size + x->Size <= 5) {
    *(++CntN) = {this, x, Val + x->Val, Size + x->Size, 0};
    return CntN;
  }
  if(Size > (x->Size << 1)) {PsDw(), RS = RS->Merge(x), Udt(); return this;}
  if(x->Size > (Size << 1)) {x->PsDw(), x->LS = Merge(x->LS), x->Udt(); return x;}
  *(++CntN) = {this, x, Val + x->Val, Size + x->Size, 0};
  return CntN;
}
inline void Node::Split(Node*& x, Node*& y, unsigned z) {
//  printf("Split %u (%u in %u) LS %u RS %u\n", this - N, z, Size, LS - N, RS - N);
  PsDw();
  if(LS->Size == z) {x = LS, y = RS;return;}
  Node *Cur;
  if(LS->Size > z) LS->Split(x, Cur, z), y = Cur->Merge(RS);
  else RS->Split(Cur, y, z - LS->Size), x = LS->Merge(Cur);
}
//  inline void Clr() {}
signed main() {
//  freopen("P5055.in", "r", stdin);
//  freopen("P5055.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD(), C = RD() ^ Ans;
//    fprintf(stderr, "Doing %u FromVer %u Type %u ", i, A, B);
    switch(B) {
      case (1) :{
        OV = RD() ^ Ans;
//        fprintf(stderr, "Add %lld Behind %u\n", OV, C);
        if(!Ver[A]) *(Ver[i] = ++CntN) = {NULL, NULL, OV, 1, 0};
        else *(Ver[i] = ++CntN) = *Ver[A], Ver[i]->Insert(C);
        break;
      }
      case (2) :{
//        fprintf(stderr, "Delete %u\n", C);
        *(Ver[i] = ++CntN) = *Ver[A], Ver[i]->Delete(C);
        break;
      }
      default :{
//        fprintf(stderr, "Range %u %u\n", C, D);
        D = RD() ^ Ans;
//        fprintf(stderr, "LAns %lld %u Range[%u, %u]\n", Ans, i, C, D);
        Node* Part1, *Part2, *Part3;
        *(Ver[i] = ++CntN) = *Ver[A];
        if(C > 1) Ver[i]->Split(Part1, Part2, C - 1);
        else Part2 = Ver[i], Part1 = NULL;
        if(D ^ Ver[i]->Size) Part2->Split(Part2, Part3, D - C + 1);
        else Part3 = NULL;
//        printf("Done\n"); 
        if(B & 1) Part2->Flip ^= 1;
        else printf("%lld\n", Ans = Part2->Val);
        if(Part3) Part2 = Part2->Merge(Part3);
        if(Part1) Ver[i] = Part1->Merge(Part2);
        else Ver[i] = Part2;
        break;
      }
    }
//    fprintf(stderr, "%u Cnt Node %u\n", i, CntN - N);
  }
//  }
  return Wild_Donkey;
}
/*
26
0 1 0 -14
1 2 1
1 3 1 1
1 1 0 -17
2 1 0 -6
1 2 1
1 3 1 1
2 1 0 15
3 1 1 -15
8 4 1 1
5 2 14
4 2 14
10 3 14 14
11 1 15 10
5 2 14
5 2 14
9 1 13 -6
7 1 15 27
9 2 13
2 1 15 7
17 3 13 12
19 4 14 14
10 2 -13
4 1 -13 12
10 4 -13 -13
4 4 14 14
*/
