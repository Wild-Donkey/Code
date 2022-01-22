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
unsigned m, n, Tl(0), Hd(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
int  Ans[500005], Insi(0);
pair<unsigned, int> QB[1000005], QF[1000005];
unsigned TB(0), HB(0), TF(0), HF(0);
struct Node;
struct Edge {
  Node* To;
}E[1000005];
struct Node {
  vector<Edge*> Ed;
  Edge* Nxt;
  Node* Fa;
  unsigned Deg, Dep, Lon;
}N[500005], * Q[1000005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(0); i < n; ++i) {
    A = RD(), B = RD();
    E[i << 1].To = N + B, N[B].Ed.push_back(E + ((i << 1) ^ 1));
    E[(i << 1) ^ 1].To = N + A, N[A].Ed.push_back(E + (i << 1));
    ++N[A].Deg, ++N[B].Deg;
  }
  for (unsigned i(1); i <= n; ++i) if(N[i].Deg == 1) Q[++Tl] = N + i;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
//    printf("BFS %u\n", Cur - N);
    for (auto i:Cur->Ed)
      if(i->To->Fa != Cur) {
        Cur->Fa = i->To;
        if((--(i->To->Deg)) == 1) Q[++Tl] = i->To;
      } else {
        Cur->Lon = max(Cur->Lon, Cur->Dep + i->To->Dep + 1);
        Cur->Lon = max(Cur->Lon, i->To->Lon);
        Cur->Dep = max(Cur->Dep, i->To->Dep + 1);
      }
  }
  Hd = Tl = 0;
  for (unsigned i(1); i <= n; ++i) Ans[i] = 0x3f3f3f3f;
  for (unsigned i(1); i <= n; ++i) {
    if(N[i].Deg > 1) {
      Node* Cur(N + i), * Beg(Cur);
      --(Cur->Deg);
      for(char Flg(0); ; Flg = 0) {
        Q[++Tl] = Cur;
//        printf("Cir %u\n", Cur - N);
        for (auto j:Cur->Ed) {
//          printf("To %u %u\n", j->To - N, j->To->Deg);
          if(j->To->Deg > 1) {
            Cur->Nxt = j, Cur = j->To, --(Cur->Deg), Flg = 1;
            break;
          }
        }
        if(!Flg)break;
      }
    }
  }
  Hd = Tl << 1;
  for (auto i:Q[Tl]->Ed) if(i->To == Q[1]) Q[Tl]->Nxt = i;
  for (unsigned j(1); j <= Tl; ++j) Q[Tl + j] = Q[j];
  for (unsigned j(1); j <= Tl; ++j) {
    for (auto k:Q[j]->Ed) if(k->To->Fa == Q[j]) {
      Q[j]->Lon = max(Q[j]->Lon, Q[j]->Dep + k->To->Dep + 1);
      Q[j]->Lon = max(Q[j]->Lon, k->To->Lon);
      Q[j]->Dep = max(Q[j]->Dep, k->To->Dep + 1);
    }
  }
  for (unsigned j(1); j <= Tl; ++j) Insi = max(Insi, (int)Q[j]->Lon);
  for (unsigned i(1); i <= Tl; ++i) {
    while ((TB > HB) && (QB[TB].second <= Q[i]->Dep + i)) --TB;
    QB[++TB] = make_pair(i, Q[i]->Dep + i);
  }
  for (unsigned i(1); i <= Tl; ++i) {
    while ((TF > HF) && (QF[TF].second <= (int)(Q[i]->Dep - i))) --TF;
    QF[++TF] = make_pair(i, (int)Q[i]->Dep - i);
//    printf("i %u QF %u = %d\n", i, TF, QF[TF].second);
  }
//  for (unsigned i(1); i <= Tl; ++i) printf("%u: %u (%u, %u)\n", i, Q[i] - N, Q[i]->Dep, Q[i]->Lon);
  for (unsigned i(Tl); i < Hd; ++i) {
    while ((TB > HB) && (QB[HB + 1].first <= i - Tl)) ++HB;
    while ((TF > HF) && (QF[HF + 1].first <= i - Tl)) ++HF;
//    printf("Calc %u Ans %u\n", i, (Q[i]->Nxt - E) >> 1);
//    for (unsigned i(HB + 1); i <= TB; ++i) printf("%d ", QB[i].second);
//    putchar(0x0A);
//    for (unsigned i(HF + 1); i <= TF; ++i) printf("%d ", QF[i].second);
//    putchar(0x0A);
    Ans[(Q[i]->Nxt - E) >> 1] = max(Insi, QB[HB + 1].second + QF[HF + 1].second);
    while ((TB > HB) && (QB[TB].second <= Q[i + 1]->Dep + i + 1)) --TB;
    QB[++TB] = make_pair(i + 1, Q[i + 1]->Dep + i + 1);
    while ((TF > HF) && (QF[TF].second <= Q[i + 1]->Dep - i - 1)) --TF;
    QF[++TF] = make_pair(i + 1, Q[i + 1]->Dep - i - 1);
  }
  for (unsigned i(0); i < n; ++i) printf("%d\n", (Ans[i] < 0x3f3f3f3f) ? Ans[i] : -1);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

