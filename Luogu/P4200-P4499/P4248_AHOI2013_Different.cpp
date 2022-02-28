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
unsigned long long Ans(0);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0), STop(0);
char S[500005];
struct Node {
  vector<Node*> Son;
  Node* To[26], * Fa;
  unsigned Len, Siz;
}N[1000005], * Stack[500005], * Last(N), * CntN(N);
inline void Add(char c) {
  // printf("Add %c\n", c + 'a');
  Node* Back(Last), * Cur(Last = Back->To[c] = ++CntN);
  Cur->Len = Back->Len + 1, Back = Back->Fa, Stack[++STop] = CntN;
  while (Back) {
    // printf("Back %u\n", Back - N);
    if (Back->To[c]) {
      Node* BcTo(Back->To[c]);
      // printf("BcTo %u\n", BcTo - N);
      if (BcTo->Len == Back->Len + 1) { Cur->Fa = BcTo; return; }
      else {
        // printf("Copy\n");
        Node* Copy(++CntN);
        (*Copy) = *(BcTo), Copy->Len = Back->Len + 1, BcTo->Fa = Cur->Fa = Copy;
        while (Back && (Back->To[c] == BcTo)) Back->To[c] = Copy, Back = Back->Fa;
        return;
      }
    }
    Back->To[c] = Cur, Back = Back->Fa;
  }
  if (!(Cur->Fa)) Cur->Fa = N;
}
inline void DFS(Node* x, unsigned len) {
  for (auto i : x->Son) DFS(i, x->Len), x->Siz += i->Siz;
  unsigned long long Ct(x->Siz);
  // printf("DFS %u Len [%u, %u] Size %llu\n", x - N, len + 1, x->Len, Ct);
  Ans -= (x->Len - len) * Ct * (Ct - 1);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  fread(S + 1, 1, 500002, stdin), n = strlen(S + 1), Ans = 0;
  while (S[n] < 'a') --n;
  // printf("Len %u\n", n);
  for (unsigned long long i(2); i <= n; ++i) Ans += i * (i - 1);
  Ans >>= 1, Ans *= 3;
  // printf("Ans %llu\n", Ans);
  for (unsigned i(n); i; --i) Add(S[i] - 'a');
  while (STop) Stack[STop--]->Siz = 1;
  // printf("Done\n");
  // for (Node* i(CntN); i > N; --i) printf("%u Fa %u\n", i - N, i->Fa - N);
  for (Node* i(CntN); i > N; --i) i->Fa->Son.push_back(i);
  DFS(N, 0);
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}