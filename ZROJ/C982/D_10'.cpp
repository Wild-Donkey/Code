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
const unsigned long long Base(29), Mod(998244353);
const unsigned ModforTable(5000011);
unsigned Hash[100005], HashToHash[5000020], m, n;
unsigned A, C, D, t, Hd, Tl;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Tot(0), TmpHash, QLen(0);
char IChr, Flg(0), Que[1000005];
struct BST {
  BST* LS, * RS;
  unsigned ValL, ValR, Size;
}B[20000005], * HashTable[5000020], * CntB(B), * ToFind;
BST* Add(unsigned x) {
  unsigned long long TmpF(x % ModforTable);
  while (HashToHash[TmpF] && (HashToHash[TmpF] ^ x)) TmpF = TmpF * 1000000007 % ModforTable;
  HashToHash[TmpF] = x;
  return HashTable[TmpF] = ++CntB;
}
void Find(unsigned x) {
  unsigned long long TmpF(x % ModforTable);
  while (HashToHash[TmpF] && (HashToHash[TmpF] ^ x)) TmpF = TmpF * 1000000007 % ModforTable;
  ToFind = HashTable[TmpF];
}
void Insert(BST* x) {
  // printf("Insert %u\n", x - B);
  ++(x->Size);
  if (!(x->ValR)) { x->ValL = x->ValR = A;return; }
  if (x->Size == 2) {
    (x->LS = ++CntB)->Size = (x->RS = ++CntB)->Size = 1;
    x->LS->ValL = x->LS->ValR = min(x->ValL, A);
    x->RS->ValL = x->RS->ValR = max(x->ValL, A);
    x->ValL = x->LS->ValL, x->ValR = x->RS->ValR;
    return;
  }
  if ((x->LS) && (x->LS->ValR >= A)) Insert(x->LS), x->ValL = x->LS->ValL;
  else Insert(x->RS), x->ValR = x->RS->ValR;

}
void Query(BST* x) {
  // printf("Query %u Size %u [%u, %u]\n", x - B, x->Size, x->ValL, x->ValR);
  // if (x->ValL + 100 >= x->ValR) printf("%u[%u %u]\n", x->Size, x->ValL, x->ValR);
  // printf("Sons %u %u\n", x->LS - B, x->RS - B);
  // if (x->LS) printf("LS [%u %u]", x->LS->ValL, x->LS->ValR);
  // if (x->RS) printf("RS [%u %u]", x->RS->ValL, x->RS->ValR);
  if ((C <= x->ValL) && (x->ValR <= D)) { A += x->Size; return; }
  if ((x->LS) && (x->LS->ValR >= C)) Query(x->LS);
  if ((x->RS) && (x->RS->ValL <= D)) Query(x->RS);
}
struct Node {
  Node* To[26];
  unsigned Fst, DFSr, NodeSize, Num;
}N[1000005], * CntN(N), * Last;
void DFS(Node* x) {
  // printf("DFS %u\n", x - N);
  x->DFSr = ++Cnt, x->NodeSize = 1, x->Fst = Tot + 1, Tot += x->Num, A = x->DFSr;
  for (unsigned i(x->Fst); i <= Tot; ++i) Insert(B);
  for (char i(0); i < 26; ++i) if (x->To[i]) {
    DFS(x->To[i]), x->NodeSize += x->To[i]->NodeSize;
    for (unsigned j(x->To[i]->Fst); j <= Tot; ++j) {
      A = x->DFSr, Hash[j] = (Hash[j] * Base + (i + 1)) % Mod, Find(Hash[j]);
      // printf("Add %u to %u\n", A, Hash[j]);
      if (ToFind) Insert(ToFind);
      else Insert(Add(Hash[j]));
    }
  }
  // printf("Done DFS %u\n", x - N);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
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
    // printf("Que %u\n", i);
    Last = N, IChr = getchar();
    if (IChr ^ '*') {
      // printf("No *\n");
      while (IChr < 'a') IChr = getchar();
      while (IChr >= 'a') {
        // printf("%c", IChr);
        if (!(Last->To[IChr - 'a'])) {
          Flg = 1; while (IChr >= 'a') IChr = getchar(); break;
        }
        Last = Last->To[IChr - 'a'], IChr = getchar();
      }
    }
    // printf("Flg %u Last %u\n", Flg, Last - N);
    if (Flg) printf("0\n");
    else {
      QLen = 0, IChr = getchar(), A = 0, TmpHash = 0;
      while (IChr >= 'a') Que[++QLen] = IChr - '`', IChr = getchar();
      // printf("Len %u\n", QLen);
      for (unsigned i(QLen); i; --i) TmpHash = (TmpHash * Base + Que[i]) % Mod;// printf("%c", Que[i] + '`');
      C = Last->DFSr, D = Last->DFSr + Last->NodeSize - 1;
      // printf("[%u, %u] THash %u\n", C, D, TmpHash);
      if (!TmpHash) Query(B);
      else {
        Find(TmpHash);
        if (ToFind) Query(ToFind);
      }
      printf("%u\n", A);
    }
  }
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
1 4
jjk
jj*jk
jjk*j
jjk*
jj*k
jkj

3
1
kjgearkjghkdajdhfigjkhdfasdfakluyeoaifnjk
kjgearkjghkajdhfigjkhdfasdfakluyeoaifnjk
kjgearkjghkdalosidhglfaejkhflkdjajdhfigjkhdfasdfakluyeoaifnjk
kjgearkjghk*

3 1
aaaaaa
aaaaab
aaaaac
a*

8 6
bbbababaabba
bbbabbababbba
bbbabbbbbbba
bbbabbbbbba
bbbabbabbba
bbbabbbbbba
ababa
abbbaaa
ab*ba
bbbab*bba
bb*ba
bbbab*a
bbbabb*a
*abbbbbba

12 3
aaaccbb
acaaabb
accbb
cbbccbb
abb
cbaaaba
cbbccc
cbccbbc
cbcabcc
cba
cbacabb
bcbcbcbccbba
*bb
c*
a*b
*/