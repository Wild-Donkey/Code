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
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned long long a[100005], Sum[100005], Now(0);
unsigned Ava[100005], Hd, m, n, Max(0), Cnt(0), Ans(0);
struct Bldi {
  unsigned long long b, p;
  inline const char operator < (const Bldi &x) const{
    return this->p > x.p; 
  } 
}B[100005];
inline char cmp (const Bldi &x, const Bldi &y) {
  return x.b < y.b;
}
priority_queue <Bldi> Q;
priority_queue <unsigned> BQ;
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) a[i] = RD(), Sum[i] = Sum[i - 1] + a[i]; 
  for (register unsigned i(1); i <= m; ++i) B[i].b = RD();
  for (register unsigned i(1); i <= m; ++i) B[i].p = RD();
  sort(B + 1, B + m + 1, cmp);
  for (register unsigned i(n); i; --i) {
    if(a[i] > Max) {
      Ava[++Cnt] = i;
      Max = a[i];
    }
  }
  Ava[Cnt + 1] = 0;
  B[m + 1].p = 0x3f3f3f3f3f3f3f3f, Hd = m, Q.push(B[m + 1]);
  BQ.push(0);
  for (register unsigned i(Cnt); i; --i) {
    while (Hd && (B[Hd].b > a[Ava[i - 1]])) {
      Q.push(B[Hd--]);
    }
    Now += Sum[Ava[i]] - Sum[Ava[i + 1]];
    while ((Q.top().p <= Now) || (Q.top().p < BQ.top())) {
      if(Q.top().b > a[Ava[i]]) {
        Q.pop();
        continue;
      }
      if(Q.top().p > Now) {
        Now += BQ.top(), BQ.pop(), --Ans; 
      }
      ++Ans;
      Now -= Q.top().p;
      BQ.push(Q.top().p);
      Q.pop(); 
    }
  }
  printf("%u\n", Ans);
  //  }
  return Wild_Donkey;
}
