//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx")
//#pragma GCC target("avx2") 
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
unsigned m, n, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[100005];
struct Node {
  vector<Node*> Son;
  Node* To[26], *Fa;
  unsigned Len, Size, Str, Idg;
}N[200005], *List[200005], **LTop(List), *CntN(N), *Last(N);
inline void Clr() {
//  printf("%u\n", CntN - N);
  memset(N, 0, sizeof(Node) * (CntN - N + 1));
  n = RD(), Ans = 0, CntN = N, LTop = List; 
}
inline void Add(char x) {
  if (Last->To[x]) {
    if (Last->To[x]->Len == Last->Len + 1) { Last = Last->To[x]; return; }
    Node* Bfr(Last->To[x]), * Cur(++CntN);
    *Cur = *Bfr;
    Cur->Fa = Bfr->Fa, Bfr->Fa = Cur, Cur->Len = Last->Len + 1, Last = Last;
    while (Last && (Last->To[x] == Bfr)) Last->To[x] = Cur, Last = Last->Fa;
    Last = Cur; return;
  }
  Node* Cur(++CntN);
  Cur->Len = Last->Len + 1;
  while (Last && (!Last->To[x])) Last->To[x] = Cur, Last = Last->Fa;
  if (Last) {
    if (Last->To[x]->Len == Last->Len + 1) { Cur->Fa = Last->To[x], Last = Cur; return; }
    Node* Bfr(Last->To[x]), *Copy(++CntN);
    *Copy = *Bfr;
    Copy->Len = Last->Len + 1, Copy->Fa = Bfr->Fa, Bfr->Fa = Cur->Fa = Copy;
    while (Last && (Last->To[x] == Bfr)) Last->To[x] = Copy, Last = Last->Fa;
  }
  else Cur->Fa = N;
  Last = Cur;
}
signed main() {
//  freopen("garble6.in", "r", stdin);
//  freopen("my.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      memset(a, 0, m + 1), scanf("%s", a), m = strlen(a), Last = N;
      for (unsigned j(0); j < m; ++j) Add(a[j] - 'a'), *(++LTop) = Last;
    }
    while (LTop > List) /*printf("%u ", *LTop - N), */++((*(LTop--))->Size); //putchar(0x0A);
    for (Node* j(N); j <= CntN; ++j)
      for (unsigned k(0); k < 26; ++k) if(j->To[k]) ++(j->To[k]->Idg);
//    printf("Fa:"); for (Node* j(N + 1); j <= CntN; ++j) printf("%u ", j->Fa - N); putchar(0x0A);
    for (Node* j(N + 1); j <= CntN; ++j) ++(j->Idg), j->Fa->Son.push_back(j);
    Node **LBut(List); 
    *(++LTop) = N;
//    printf("Size:"); for (Node* j(N); j <= CntN; ++j) printf("%u ", j->Size); putchar(0x0A);
    while (LBut < LTop) {
      Node* Cur(*(++LBut));
      for (unsigned i(0); i < 26; ++i)
        if((Cur->To[i]) && (!(--(Cur->To[i]->Idg)))) *(++LTop) = Cur->To[i];
      for (auto i:Cur->Son) if(!(--(i->Idg))) *(++LTop) = i;
    }
    while (LTop > List + 1) {
      Node*Cur(*(LTop--));
      unsigned Mx(0);
      for (auto i:Cur->Son) Cur->Size += i->Size, Mx = max(Mx, i->Str + i->Size * (i->Len - Cur->Len));
      for (unsigned i(0); i < 26; ++i) if(Cur->To[i]) Mx = max(Mx, Cur->To[i]->Str + Cur->To[i]->Size * (Cur->To[i]->Len - Cur->Len));
//      Cur->Tot = Cur->Size;
      Cur->Str = Mx;
//      printf("Cur %u\n", Cur - N);
    }
//    printf("Done\n");
//    printf("Size:"); for (Node* j(N); j <= CntN; ++j) printf("%u ", j->Size); putchar(0x0A);
//    printf("Str:"); for (Node* j(N); j <= CntN; ++j) printf("%u ", j->Str); putchar(0x0A);
    for (unsigned i(0); i < 26; ++i) if(N->To[i]) Ans = max(Ans, N->To[i]->Str + N->To[i]->Size * N->To[i]->Len);
    printf("%llu\n", Ans);
  }
  return Wild_Donkey;
}
