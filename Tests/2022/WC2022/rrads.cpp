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
unsigned long long Ans[500005], Tmp, Cur;
unsigned a[500005], m, n, B, NL, NR;
unsigned C, D;
char Flg(0), Ava[500005];
struct Qry {
  unsigned L, R, Nu;
  const inline char operator < (const Qry& x) const {
    unsigned BL(x.L / B);
    return ((L / B) ^ BL) ? ((L / B) < BL) : (R > x.R);
  }
}Q[500005];
struct Link {
  unsigned Pre, Aft, Pos;
}N[500005];
vector<pair<unsigned, unsigned*> > Stack;
inline void Init(unsigned Le, unsigned Ri) {
  // fprintf(stderr, "Init [%u, %u]\n", Le, Ri);
  for (unsigned i(Le); i <= Ri; ++i) Ava[a[i]] = 1;
  Link* Hd(NULL), * Tl(NULL);
  for (unsigned i(1); i <= n; ++i)
    if (Ava[i]) { N[i].Pre = Hd - N, Hd = N + i, Ava[i] = 0; if (!Tl) Tl = Hd; else N[Hd->Pre].Aft = Hd - N; }
  Tl->Pre = Hd->Aft = NULL, Cur = 0;
  while (Tl > N) {
    if (Tl->Pre) Cur += (Tl->Pos < N[Tl->Pre].Pos) ? (N[Tl->Pre].Pos - Tl->Pos) : (Tl->Pos - N[Tl->Pre].Pos);
    Tl = N + Tl->Aft;
  }
}
inline void Del(Link* x) {
  // printf("Del %u %u %u\n", x - N, x->Pre - N, x->Aft - N);
  unsigned TA(x->Pos), TB(0), TC(0);
  if (x->Pre) {
    if (Flg) Stack.push_back({N[x->Pre].Aft, &(N[x->Pre].Aft)});
    TB = N[x->Pre].Pos, N[x->Pre].Aft = x->Aft, Cur -= (TB < TA) ? (TA - TB) : (TB - TA);
  }
  if (x->Aft) {
    if (Flg) Stack.push_back({ N[x->Aft].Pre, &(N[x->Aft].Pre)});
    TC = N[x->Aft].Pos, N[x->Aft].Pre = x->Pre, Cur -= (TC < TA) ? (TA - TC) : (TC - TA);
  }
  if (TB && TC) Cur += (TB < TC) ? (TC - TB) : (TB - TC);
  // fprintf(stderr, "%llu\n", Cur);
  // printf("Del %llu\n", Cur);
}
//  inline void Clr() {}
signed main() {
//   freopen("rrads2.in", "r", stdin);
//   freopen("rrads.out", "w", stdout);
  // Beg = clock();
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), B = (n / sqrt(m)) + 1;
  for (unsigned i(0); i < n; ++i) N[a[i] = RD()].Pos = i + 1;
  for (unsigned i(1); i <= m; ++i) Q[i].L = RD() - 1, Q[i].R = RD() - 1, Q[i].Nu = i;
  sort(Q + 1, Q + m + 1);
  // for (unsigned i(1); i <= m; ++i) printf("%u ", Q[i].Nu); putchar(0x0A);
  // printf("Block %u\n", B);
  for (unsigned i(1); i <= n; ++i) N[i].Pre = i - 1, N[i].Aft = i + 1;
  N[1].Pre = N[n].Aft = NULL;
  for (unsigned i(1), j(0); i <= m; ++j) {
    if ((Q[i].L / B) ^ j) continue;
    // fprintf(stderr, "Ref %u [%u, %u]\n", i, Q[i].L, Q[i].R);
    unsigned Le(j * B);
    Init(NL = Le, NR = Q[i].R), Tmp = Cur, Stack.clear();
    while ((Q[i].L < (j + 1) * B) && (i <= m)) {
      while (Stack.size()) *(Stack.back().second) = Stack.back().first, Stack.pop_back();
      Cur = Tmp, Flg = 0, NL = Le;
      // printf("Now %llu\n", Tmp);
      while (NR > Q[i].R) Del(N + a[NR--]);
//      printf("i = %u %u at [%u, %u]\n", i, Cur, NL, NR);
      Flg = 1, Tmp = Cur;
      while (NL < Q[i].L) Del(N + a[NL++]);
      Ans[Q[i].Nu] = Cur, ++i;
    }
  }
  // printf("C %u D %u\n", C, D);
  // printf("Time %u\n", clock() - Beg);
  for (unsigned i(1); i <= m; ++i) printf("%llu\n", Ans[i]);
  //  }
  // system("pause");
  return Wild_Donkey;
}
