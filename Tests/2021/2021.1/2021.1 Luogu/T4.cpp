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
inline unsigned int RD() {  // without "-"
  unsigned int intmp = 0;
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
const unsigned long long Mod(998244353);
unsigned int m, n, Cnta(0), Stk[1005], C[200005];
bool b[1005];
unsigned long long ans(0), Fc[100005];
struct Edge;
struct Node {
  Edge *Fst;
  unsigned int Col, Val;
  bool vst;
} N[200005];
struct Edge {
  Edge *Nxt;
  Node *To;
} E[400005];
void Factorio() {
  Fc[0] = Fc[1] = 1;
  for (register int i(2); i <= n; ++i) {
    Fc[i] = Fc[i - 1] * i;
    Fc[i] %= Mod;
  }
  return;
}
void DFS(unsigned int Dep) {
  if(Dep >= n){
    
  }
  for (register int i(1); N[i].Col != x->Col; ++i) {
    if (!N[i].vst) {
      N[i].vst = 1;
      flg = 0;
      DFS(N + i);
      N[i].vst = 0;
    }
  }
  for (register int i(n); N[i].Col != x->Col; --i) {
    if (!N[i].vst) {
      N[i].vst = 1;
      flg = 0;
      DFS(N + i);
      N[i].vst = 0;
    }
  }
  if (flg) {
    ans++;
    ans %= Mod;
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen("P3834_3.in", "r", stdin);
  // freopen("P3834.out", "w", stdout);
  n = RD();
  m = RD();
  for (register int i(1); i <= m; ++i) {
    C[i] = RD();
  }
  sort(C + 1, C + m + 1);
  DFS(N + 1);
  printf("%llu\n", ans % Mod);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}