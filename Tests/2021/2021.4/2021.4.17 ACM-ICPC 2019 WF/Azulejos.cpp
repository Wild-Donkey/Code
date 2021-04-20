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
unsigned a[10005], m, n, Cnt(0), t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {}
struct Node{
  int h, p;
  bool operator <(const Node *x) const {
    return this->p < x.p;
  }
}A[100010], B[100010];
int main() {
  n = RD();
  for(int i = 1; i <= n; ++i){
    A[i].p = RD();
  }
  for(int i = 1; i <= n; ++i){
    A[i].h = RD();
  }
  for(int i = 1; i <= n; ++i){
    B[i].p = RD();
  }
  for(int i = 1; i <= n; ++i){
    B[i].h = RD();
  }
  sort(A + 1, A + 1 + n);
  sort(B + 1, B + 1 + n);
  
  return 0;
}



