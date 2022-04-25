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
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
char a[3000005];
unsigned n, m, A, Ans, t;
struct Node {
  unordered_map<char, Node*> Son;
  unsigned Cnt;
}N[3000005], *CntN(N);
inline void Clr () {
  for (Node* i(N); i <= CntN; ++i) i->Cnt = 0, i->Son.clear();
  CntN = N;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr(), n = RD(), m = RD();
    for (unsigned i(1); i <= n; ++i) {
      memset(a, 0, A + 2);
      scanf("%s", a + 1);
      A = strlen(a + 1);
      Node* Cur(N); 
      for (unsigned k(1); k <= A; ++k) {
        ++(Cur->Cnt);
//        printf("Insert %u\n", a[k]);
        if(!(Cur->Son[a[k]])) Cur->Son[a[k]] = ++CntN;
        Cur = Cur->Son[a[k]];
      }
      ++(Cur->Cnt);
    }
    for (unsigned i(1); i <= m; ++i) {
      memset(a, 0, A + 2);
      scanf("%s", a + 1);
      A = strlen(a + 1), Ans = 0;
      Node* Cur(N);
      for (unsigned j(1); (j <= A) && Cur; ++j) {
        Cur = Cur->Son[a[j]];
      }
      if(Cur) Ans = Cur->Cnt;
      printf("%u\n", Ans);
    }
  }
  return Wild_Donkey;
}
/*
*/
