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
const unsigned long long Base(131);
const unsigned ModforTable(2000003);
unsigned TmpHash, Hash[100005], HashToHash[2000010];
unsigned m, n;
unsigned A, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Tot(0), QLen(0);
char IChr, Flg(0), Que[1000005];
struct BST {
  BST* LS, * RS;
  unsigned ValL, ValR, Size;
}B[5000005], * HashTable[2000010], * CntB(B), * ToFind;
BST* Add(unsigned x) {
  unsigned long long TmpF(x % ModforTable);
  while (HashToHash[TmpF] && (HashToHash[TmpF] ^ x)) TmpF = (TmpF * 1000000007 % ModforTable) + 1;
  HashToHash[TmpF] = x;
  return HashTable[TmpF] = ++CntB;
}
void Find(unsigned x) {
  unsigned long long TmpF(x % ModforTable);
  while (HashToHash[TmpF] && (HashToHash[TmpF] ^ x)) TmpF = (TmpF * 1000000007 % ModforTable) + 1;
  ToFind = HashTable[TmpF];
}
void Insert(BST* x) {
  ++(x->Size);
  if (!(x->ValR)) { x->ValL = x->ValR = A;return; }
  if (x->ValL == x->ValR) {
    if ((x->ValL) ^ A) {
      if (x->ValL < A) (x->LS = ++CntB)->Size = x->Size - 1, (x->RS = ++CntB)->Size = 1;
      else (x->LS = ++CntB)->Size = 1, (x->RS = ++CntB)->Size = x->Size - 1;
      x->ValL = x->LS->ValL = x->LS->ValR = min(x->ValL, A);
      x->ValR = x->RS->ValL = x->RS->ValR = max(x->ValR, A);
    }
    return;
  }
  if ((x->LS) && (x->LS->ValR >= A)) Insert(x->LS), x->ValL = x->LS->ValL;
  else Insert(x->RS), x->ValR = x->RS->ValR;
  if ((x->RS->Size > (x->LS->Size << 2)) && (x->RS->RS)) {
    BST* Move(x->RS);
    x->RS = Move->RS, Move->RS = Move->LS, Move->LS = x->LS, x->LS = Move;
    Move->ValL = Move->LS->ValL, Move->ValR = Move->RS->ValR;
    Move->Size = Move->LS->Size + Move->RS->Size;
  }
  if ((x->LS->Size > (x->RS->Size << 2)) && (x->LS->LS)) {
    BST* Move(x->LS);
    x->LS = Move->LS, Move->LS = Move->RS, Move->RS = x->RS, x->RS = Move;
    Move->ValL = Move->LS->ValL, Move->ValR = Move->RS->ValR;
    Move->Size = Move->LS->Size + Move->RS->Size;
  }
}
void Query(BST* x) {
  if ((C <= x->ValL) && (x->ValR <= D)) { A += x->Size; return; }
  if ((x->LS) && (x->LS->ValR >= C)) Query(x->LS);
  if ((x->RS) && (x->RS->ValL <= D)) Query(x->RS);
}
struct Node {
  Node* To[26];
  unsigned Fst, DFSr, NodeSize, Num;
}N[1500005], * CntN(N), * Last;
void DFS(Node* x) {
  x->DFSr = ++Cnt, x->NodeSize = 1, x->Fst = Tot + 1, Tot += x->Num, A = x->DFSr;
  for (unsigned i(x->Fst); i <= Tot; ++i) Insert(B);
  for (char i(0); i < 26; ++i) if (x->To[i]) {
    DFS(x->To[i]), x->NodeSize += x->To[i]->NodeSize;
    for (unsigned j(x->To[i]->Fst); j <= Tot; ++j) {
      A = x->DFSr, Hash[j] = Hash[j] * Base + (i + 1), Find(Hash[j]);
      if (ToFind) Insert(ToFind);
      else Insert(Add(Hash[j]));
    }
  }
}
signed main() {
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    IChr = getchar(), Last = N;
    while (IChr < 'a') IChr = getchar();
    while (IChr >= 'a') {
      if (!(Last->To[IChr -= 'a'])) Last->To[IChr] = ++CntN;
      Last = Last->To[IChr], IChr = getchar();
    }
    ++(Last->Num);
  }
  DFS(N);
  for (unsigned i(1); i <= m; ++i, Flg = 0) {
    Last = N, IChr = getchar();
    if (IChr ^ '*') {
      while (IChr < 'a') IChr = getchar();
      while (IChr >= 'a') {
        if (!(Last->To[IChr - 'a'])) { Flg = 1; while (IChr >= 'a') IChr = getchar(); break; }
        Last = Last->To[IChr - 'a'], IChr = getchar();
      }
    }
    if (Flg) { IChr = getchar();while (IChr >= 'a') IChr = getchar(); printf("0\n"); }
    else {
      QLen = 0, IChr = getchar(), A = 0, TmpHash = 0;
      while (IChr >= 'a') Que[++QLen] = IChr - '`', IChr = getchar();
      for (unsigned j(QLen); j; --j) TmpHash = TmpHash * Base + Que[j];
      C = Last->DFSr, D = Last->DFSr + Last->NodeSize - 1;
      if (!TmpHash) Query(B);
      else { Find(TmpHash); if (ToFind) Query(ToFind); }
      printf("%u\n", A);
    }
  }
  return Wild_Donkey;
}