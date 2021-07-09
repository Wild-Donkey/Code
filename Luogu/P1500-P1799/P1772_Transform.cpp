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
unsigned E[25][25], f[265005], m, n, Cnt(0), ChgVal, A, B, t, Ans(0), Com, Now(0);
unsigned long long g[265005], Delta, Min(0), LastMin, Tmp(0);
bool b[10005];
struct Node {
  unsigned Dis, Num;
  char Outofqueue;
  inline const char operator< (const Node &x) const{
    return this->Dis > x.Dis;
  }
}Ins, N[25];
struct Close {
  unsigned Time, Num;
  char Type;
  inline const char operator< (const Close &x) const{
    return this->Time < x.Time;
  }
}C[105];
priority_queue<Node> Q;
unsigned Dij() {
  for (register unsigned i(0); i < n; ++i)
    N[i].Dis = 0x3f3f3f3f, N[i].Outofqueue = 0;
  N[n - 1].Dis = 0;
  Q.push(N[n - 1]);
  while (Q.size()) {
    register unsigned NowNum(Q.top().Num), NowDis(Q.top().Dis);
    Q.pop();
    if(N[NowNum].Outofqueue) continue;
    N[NowNum].Outofqueue = 1;
    if(NowNum == n - 2) {while (Q.size()) Q.pop(); return NowDis;}
    for (register unsigned i(0); i < n; ++i) {
      if((N[i].Dis > NowDis + E[NowNum][i]) && ((1 << i) & A) && (E[NowNum][i] < 0x3f3f3f3f) && (!(N[i].Outofqueue))) {
        N[i].Dis = NowDis + E[NowNum][i];
        Q.push(N[i]);
      }
    }
  }
  return 0x3f3f3f3f;
}
int main() {
  t = RD(), n = RD(), ChgVal = RD(), m = RD();
  Com = 1 << (n - 2);
  memset(E, 0x3f, sizeof(E));
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    if(A == 1) A = n + 1; 
    A -= 2;
    if(B == 1) B = n + 1; 
    B -= 2;
    E[A][B] = E[B][A] = min(E[B][A], RD());
  }
  Cnt = RD();
  for (register unsigned i(1); i <= Cnt; ++i) {
    A = RD(), A -= 2;
    C[(i << 1) - 1].Num = C[i << 1].Num = A;
    C[(i << 1) - 1].Time = RD(); 
    C[i << 1].Time = RD() + 1;
  }
  Cnt <<= 1;
  sort(C + 1, C + Cnt + 1);
  for (register unsigned i(0); i < n; ++i) N[i].Num = i;
  for (A = (3 << (n - 2)); A < (1 << n); ++A) f[A ^ (3 << (n - 2))] = Dij();
  C[0].Time = 1;
  C[++Cnt].Time = t + 1;
  for (register unsigned i(1); i <= Cnt; ++i) {
    if(C[i].Time ^ C[i - 1].Time) {
      LastMin = Min, Min = 0x3f3f3f3f;
      Delta = C[i].Time - C[i - 1].Time;
      for (register unsigned j(0); j < Com; ++j) {
        if(j & Now) g[j] = 0x3f3f3f3f;
        else {
          Tmp = f[j] * Delta;
          g[j] = min(g[j] + Tmp, LastMin + Tmp + ChgVal);
          Min = min(g[j], Min);
        }
      }
    }
    Now ^= (1 << C[i].Num);
  }
  printf("%llu\n", Min);
  return Wild_Donkey;
}



