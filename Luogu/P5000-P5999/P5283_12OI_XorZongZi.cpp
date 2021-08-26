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
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const char _31(31), _0(0), _1(1);
unsigned Sum[500005], Top[500005], m, n, Cnt(0), Now(0), A, B, C, D, t, Tmp(0);
unsigned long long Ans(0);
struct Node {
  Node* Son[2];
  unsigned Size;
}N[20000005], * Root[500005], * Last, * LastLast, * CntN(N);
void Add(char c) {
  // printf("Add %u to %u About %u\n", c, Last - N, LastLast - N);
  Last->Son[c] = ++CntN, Last->Size = 1;
  if (LastLast) Last->Son[c ^ 1] = LastLast->Son[c ^ 1], Last->Size += LastLast->Size, LastLast = LastLast->Son[c];
  Last = Last->Son[c];
}
unsigned Qry(Node* x, unsigned Dep) {
  // printf("Qry %u at %u Sz %u of %u\n", x - N, Dep, x->Size, A);
  if (Dep == 32) {
    // printf("Faq %u ^ %u = %u\n", B, Now, )
    return B ^ Now;
  }
  char Big(_1 & (B >> (31 - Dep)));
  // printf("Big %u\n", Big);
  Now <<= 1, Big ^= 1;
  if (x->Son[Big]) {
    if (x->Son[Big]->Size >= A) { Now |= Big;return Qry(x->Son[Big], Dep + 1); }
    else { A -= x->Son[Big]->Size, Now |= (Big ^ 1);return Qry(x->Son[Big ^ 1], Dep + 1); }
  }
  Now |= (Big ^ 1);
  return Qry(x->Son[Big ^ 1], Dep + 1);
}
priority_queue <pair<unsigned, unsigned> > Q;
signed main() {
  // freopen("P5283_21.in", "r", stdin);
  // freopen("P5283.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  Root[0] = Last = ++CntN, LastLast = NULL;
  for (register char i(_31); i >= _0; --i) Add(((1 << i) & Sum[0]) >> i);
  for (register unsigned i(1); i <= n; ++i) {
    Sum[i] = Sum[i - 1] ^ RD();
    Root[i] = Last = ++CntN, LastLast = Root[i - 1];
    for (register char j(_31); j >= _0; --j) Add(((1 << j) & Sum[i]) >> j);
    A = Top[i] = 1, B = Sum[i], Now = 0, Q.push(make_pair(Qry(Root[i - 1], 0), i));
  }
  for (register unsigned i(1); i <= m; ++i) {
    Ans += Q.top().first, D = Q.top().second,/* printf("%u %u\n", Q.top().first, Q.top().second), */Q.pop();
    if (Top[D] < D) {
      A = ++Top[D], B = Sum[D], Now = 0, Q.push(make_pair(Qry(Root[D - 1], 0), D));
    }
  }
  printf("%llu\n", Ans);
  for (register unsigned i(1); i <= n; ++i) {
    printf("Sum[%u] %u  ", i, Sum[i]);
    for (register unsigned j(1); j <= i; ++j) {
      A = j, B = Sum[i], Now = 0, printf("%u %u is %u    ", i, j, Qry(Root[i - 1], 0));
    }
    putchar('\n');
  }
  system("pause");
  return Wild_Donkey;
}
/*
5 5
6 7 8 4 5
*/