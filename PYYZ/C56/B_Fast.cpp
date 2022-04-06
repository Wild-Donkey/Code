//#pragma GCC optimize("Ofast")
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
unsigned m, n, t, nn;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[100005];
struct Node {
  vector<Node*> Son;
  Node* To[26], *Fa;
  unsigned Len;
}N[200005], *CntN(N), *Last(N);
vector<unsigned> M[200005];
unsigned Size[200005], Str[200005], List[200005], *LTop(List);
inline void Clr() {
  memset(N, 0, sizeof(Node) * (CntN - N + 1));
  memset(Size, 0, (nn + 1) << 2);
  memset(Str, 0, (nn + 1) << 2);
  memset(List, 0, (nn + 1) << 2);
  for (unsigned i(0); i <= nn; ++i) M[i].clear();
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
      for (unsigned j(0); j < m; ++j) Add(a[j] - 'a'), ++Size[Last - N];
    }
    nn = CntN - N;
    for (Node* j(N); j <= CntN; ++j) for (unsigned k(0); k < 26; ++k) if(j->To[k])
      ++Str[j->To[k] - N], M[j - N].push_back(j->To[k] - N);
    for (Node* j(N + 1); j <= CntN; ++j) ++Str[j - N], M[j->Fa - N].push_back(j - N);
    unsigned *LBut(List);
    *(++LTop) = 0;
    while (LBut < LTop) {
      unsigned Cur(*(++LBut));
      for (auto i:M[Cur]) if(!(--(Str[i]))) *(++LTop) = i;
    }
    for (unsigned *i(LTop); i > List + 1; --i) Size[N[*i].Fa - N] += Size[*i];
    while (LTop > List + 1) {
      unsigned Cur(*(LTop--));
      unsigned &Mx(Str[Cur]);
      for (auto i:M[Cur]) Mx = max(Mx, Str[i] + Size[i] * (N[i].Len - N[Cur].Len));
    }
    for (unsigned i(0); i < 26; ++i) if(N->To[i]) Ans = max(Ans, Str[N->To[i] - N] + Size[N->To[i] - N] * N->To[i]->Len);
    printf("%llu\n", Ans);
  }
  return Wild_Donkey;
}
