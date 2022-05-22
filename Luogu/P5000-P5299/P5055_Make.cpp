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
inline long long RD() {
  long long rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
int a[1005][1005];
long long Ans[100005], OV;
unsigned m(0), n(30), A, B, C, D;
inline int Rand(int L, int R) {
  return L + (rand() % (R - L + 1));
}
signed main() {
  freopen("P5055.in", "w", stdout);
  srand(time(0));
  printf("%u\n", n);
  printf("0 1 0 %d\n", a[1][1] = Rand(-20, 20)), a[1][0] = 1;
  for (unsigned i(2); i <= n; ++i) {
    A = Rand(1, i - 1), B = Rand(1, 4);
    if(!a[A][0]) B = 1;
//    fprintf(stderr, "Size %u LAns %lld\n", a[A][0], Ans[m]);
    memcpy(a[i], a[A], (a[A][0] + 1) << 2);
    printf("%u %u ", A, B);
    switch(B) {
      case (1) :{
        printf("%lld %lld\n", Ans[m] ^ (long long)(C = Rand(0, a[i][0])), Ans[m] ^ (OV = Rand(-20, 20)));
        for(unsigned j(a[i][0]); j > C; --j) a[i][j + 1] = a[i][j]; a[i][C + 1] = OV;
        ++a[i][0];
        break;
      }
      case (2) :{
        printf("%lld\n", Ans[m] ^ (long long)(C = Rand(1, a[i][0])));
        for(unsigned j(C); j < a[i][0]; ++j) a[i][j] = a[i][j + 1]; --a[i][0];
        break;
      }
      default :{
        C = Rand(1, a[i][0]), D = Rand(1, a[i][0]);
        if(D < C) swap(C, D);
        printf("%lld %lld\n", Ans[m] ^ (long long)C, Ans[m] ^ (long long)D);
        if(B & 1) for (unsigned j(C), k(D); j <= k; ++j, --k) swap(a[i][j], a[i][k]);
        else {
          Ans[++m] = 0;
          for (unsigned j(C); j <= D; ++j) Ans[m] += a[i][j];
        }
        break;
      }
    }
  }
  freopen("P5055.ans", "w", stdout);
  for (unsigned i(1); i <= m; ++i) printf("%lld\n", Ans[i]);
  return Wild_Donkey;
}
