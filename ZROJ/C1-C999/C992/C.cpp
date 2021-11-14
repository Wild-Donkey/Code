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
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline int RD() {
  int intmp(0);
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
int m, n, Tl(0), Hd(0); 
int A, B, D, t, P(42);
int Cnt(0), Ans(0), Tmp(0);
int Seed(200410223), Last(1), Mod(998244353);
int Stack[50005][2], Can[5], Choice[5], Top;
char C[3] = {'R', 'G', 'B'};
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char Col;
}E[400005];
struct Node {
  Edge* Fst;
  int Deg, f[3];
}N[50005], * Q[50005], * List[50005];
void Udt(Node* x, Node *y, Edge* z) {
  if(x->f[0] + 1 <= y->f[0]) {z->Col = 'R';return;}
  if(x->f[1] + 1 <= y->f[1]) {z->Col = 'G';return;}
  if(x->f[2] + 1 <= y->f[2]) {z->Col = 'B';return;}
  if((x->f[0] == x->f[1]) && (x->f[0] == x->f[2])) {
    Can[4] = max(Can[4], x->f[0] + 1);
    Stack[++Top][0] = z - E, Stack[Top][1] = 4; return;
  }
  if(x->f[0] == x->f[1]) {
    if(x->f[0] < x->f[2]) {
      Can[1] = max(Can[1], x->f[0] + 1);
      Stack[++Top][0] = z - E, Stack[Top][1] = 1;
    }
    else y->f[2] = x->f[2] + 1, z->Col = 'B';
    return;
  }
  if(x->f[1] == x->f[2]) {
    if(x->f[1] < x->f[0]) {
      Can[3] = max(Can[3], x->f[1] + 1);
      Stack[++Top][0] = z - E, Stack[Top][1] = 3;
    }
    else y->f[0] = x->f[0] + 1, z->Col = 'R';
    return;
  }
  if(x->f[0] == x->f[2]) {
    if(x->f[0] < x->f[1]) {
      Can[2] = max(Can[2], x->f[0] + 1);
      Stack[++Top][0] = z - E, Stack[Top][1] = 2;
    }
    else y->f[1] = x->f[1] + 1, z->Col = 'G';
    return;
  }
  if(x->f[0] < x->f[1]) {
    if(x->f[0] < x->f[2]) y->f[0] = x->f[0] + 1, z->Col = 'R';
    else y->f[2] = x->f[2] + 1, z->Col = 'B';
  } else {
    if(x->f[1] < x->f[2]) y->f[1] = x->f[1] + 1, z->Col = 'G';
    else y->f[2] = x->f[2] + 1, z->Col = 'B';
  }
}
void DP () {
  for (int i(n); i; --i) {
    Can[1] = Can[2] = Can[3] = Can[4] = 0;
    Top = 0; 
    Edge* Sid(List[i]->Fst);
    while (Sid) {
      printf("Udt %u -> %u\n", Sid->To - N, List[i] - N);
      printf("f %u (%u, %u, %u)\n", Sid->To - N, Sid->To->f[0], Sid->To->f[1], Sid->To->f[2]);
      printf("f %u (%u, %u, %u)\n", List[i] - N, List[i]->f[0], List[i]->f[1], List[i]->f[2]);
      Udt(Sid->To, List[i], Sid);
      printf("f %u (%u, %u, %u)\n", List[i] - N, List[i]->f[0], List[i]->f[1], List[i]->f[2]);
      Sid = Sid->Nxt;
    }
    printf("Can %u %u %u %u\n", Can[1], Can[2], Can[3], Can[4]);
    if(Can[1] <= List[i]->f[0]) Choice[1] = 0;
    if(Can[1] <= List[i]->f[1]) Choice[1] = 1;
    if((Can[4] > Can[2]) && (Can[4] > Can[3]) && (Can[4] > Can[1])) {
        Choice[1] = Choice[2] = Choice[3] = Choice[4] = 0;
        Can[1] = Can[2] = Can[3] = Can[4];
    } else {
      if((Can[1] == Can[2]) && (Can[3] == Can[1])) {
        printf("FFFAAQAA\n");
        Choice[4] = Choice[1] = Choice[3] = 1, Choice[2] = 0;
        Can[4] = Can[1] = Can[3];
      } else {
        if((Can[2] < Can[3]) && (Can[2] < Can[1])) {
          Choice[4] = Choice[2] = Choice[3] = Choice[1] = 1;
          Can[1] = Can[2] = Can[4] = Can[3];
        }else {
          if((Can[3] < Can[2]) && (Can[3] < Can[1])) {
            Choice[1] = Choice[2] = Choice[3] = Choice[4] = 0;
            Can[4] = Can[2] = Can[3] = Can[1];
          }else {
            Choice[1] = Choice[2] = Choice[3] = Choice[4] = 2;
            Can[4] = Can[2] = Can[3] = Can[3];
          }
        }
      }
    }
    printf("Can %u %u %u %u\n", Can[1], Can[2], Can[3], Can[4]);
    for (int j(1); j <= Top; ++j) {
      printf("Stack %u: %u %u C %u\n", j, Stack[j][0], Stack[j][1], Choice[Stack[j][1]]);
      E[Stack[j][0]].Col = C[Choice[Stack[j][1]]];
      List[i]->f[Choice[Stack[j][1]]] = max(List[i]->f[Choice[Stack[j][1]]], Can[Stack[j][1]]);
    }
    printf("f %u (%u, %u, %u)\n", List[i] - N, List[i]->f[0], List[i]->f[1], List[i]->f[2]);  
  }
}
int Rand() {
  return Last = (int long long)Last * Seed % Mod;
}
void Random() {
  for (int i(1); i <= m; ++i) E[i].Col = C[Rand() % 3];
}
void Judge () {
  Ans = 0;
  for (int i(1); i <= n; ++i) N[i].f[0] = N[i].f[1] = N[i].f[2] = 0;
  for (int i(1); i <= n; ++i) {
    Ans = max(Ans, List[i]->f[0]);
    Ans = max(Ans, List[i]->f[1]);
    Ans = max(Ans, List[i]->f[2]);
    Edge* Sid(List[i]->Fst);
    while (Sid) {
      if(Sid->Col == 'R') Sid->To->f[0] = max(Sid->To->f[0], List[i]->f[0] + 1);
      if(Sid->Col == 'G') Sid->To->f[1] = max(Sid->To->f[1], List[i]->f[1] + 1);
      if(Sid->Col == 'B') Sid->To->f[2] = max(Sid->To->f[2], List[i]->f[2] + 1);
      Sid = Sid->Nxt;
    }
  }
}
signed main() {
  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
//  t = RD();
//  for (int T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (int i(1); i <= m; ++i) {
    B = RD(), A = RD();
    ++N[B].Deg, E[i].Nxt = N[A].Fst, N[A].Fst = E + i, E[i].To = N + B;
  }
  for (int i(1); i <= n; ++i) if(!(N[i].Deg)) Q[++Tl] = N + i;
  while (Tl ^ Hd) {
    Node* Cur(Q[++Hd]);
    Edge* Sid(Cur->Fst);
    List[++Cnt] = Cur;
    while (Sid) {
      if(!(--(Sid->To->Deg))) Q[++Tl] = Sid->To;
      Sid = Sid->Nxt;
    }
  }
  DP(), Judge();
  for (int i(1); i <= n; ++i)
    printf("f %u (%u, %u, %u)\n", i, N[i].f[0], N[i].f[1], N[i].f[2]);
  printf("Ans %u\n", Ans);
  while (Ans > P) {
    Random(), Judge();
    printf("Ans %u\n", Ans);
  }
  for (int i(1); i <= m; ++i) putchar(E[i].Col), putchar('\n');
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

