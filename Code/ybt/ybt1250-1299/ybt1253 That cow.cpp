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
inline unsigned int RD() {
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
unsigned int q[1000005], k, m, n, Cnt(0), A, B, C, D, hd(0), tl(0), f[1000005];
bool b[10005];
char s[10005];
inline void Clr() {
  n = RD();
//  memset(a, 0, sizeof(a));
}
void BFS() {
  memset(f, 0x3f, sizeof(f));
  q[tl++] = n;
  f[n] = 0;
  unsigned int x;
  while (hd < tl) {
    if(f[k] < 1000000000) {
      return;
    }
    x = q[hd++];
    if(x - 1) {
      if(f[x - 1] > f[x] + 1) {
        f[x - 1] = f[x] + 1;
        q[tl++] = x - 1;
      }
    }
    if(x + 1 <= k) {
      if(f[x + 1] > f[x] + 1) {
        f[x + 1] = f[x] + 1;
        q[tl++] = x + 1;
      }
    }
    if(x << 1 < 2 * k) {
      if(f[x << 1] > f[x] + 1) {
        f[x << 1] = f[x] + 1;
        q[tl++] = x << 1;
      }
    }
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  k = RD();
  if(n >= k) {
    printf("%u\n", n - k);
    return Wild_Donkey; 
  }
  BFS();
  printf("%u\n", f[k]);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
