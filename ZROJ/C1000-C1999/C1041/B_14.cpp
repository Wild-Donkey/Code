#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
struct Node {
  vector <Node*> To;
  unsigned Len;
}N[100005], * De;
unsigned m, n, q;
unsigned A, B, C, D, t;
unsigned Ans(0), Cnt(0), Tmp(0);
char Flg(0);
//  inline void Clr() {}
signed main() {
//  freopen("B3.in", "r", stdin);
//  freopen("B3.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), q = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    N[B].To.push_back(N + A);
//    printf("Link %u -> %u\n", B, A);
  }
  for (unsigned i(1); i <= q; ++i) {
//    fprintf(stderr, "Qry %u", i);
    De = N + RD(), Flg = Ans = 0;
    for (Node* j(De); j > N; --j) j->Len = 0;
//    for (Node* j(De); j > N; --j) printf("%u Len %u\n", j - N, j->Len);
    for (Node* j(De); j > N; --j) if((j->Len) || (j == De))
      for (auto k:j->To) k->Len = max(k->Len, j->Len + 1);
//    for (Node* j(De); j > N; --j) printf("%u Len %u\n", j - N, j->Len);
    for (unsigned j(RD()); j; --j) N[RD()].Len = 0x3f3f3f3f;
    for (Node *j(De); j > N; --j) if((j->Len < 0x3f3f3f3f) && ((j->Len) || (j == De))) Flg = 1, Ans = max(Ans, j->Len);
    if(Flg) printf("%u\n", Ans);
    else printf("-1\n");
  }
  return Wild_Donkey;
}
/*
12 17 10
1 2
2 3
3 4
1 5
2 6
3 7
4 8
5 6
6 7
7 8
5 9
6 10
7 11
8 12
9 10
10 11
11 12
6 3 1 7 12
3 7 1 2 3 4 5 6 7
11 3 1 3 5
9 2 1 9
8 4 1 2 3 4
1 1 1
12 0
10 3 1 6 10
11 8 2 3 5 6 7 9 10 11
8 7 2 3 4 5 6 7 8

*/
