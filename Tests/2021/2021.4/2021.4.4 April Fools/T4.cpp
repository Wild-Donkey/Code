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
struct Node {
  short X, Y;
}nodeStack[1000005], *nSH(nodeStack);
short a[2005][2005], m, n;
unsigned t;
bool flg(0), flg2(0);
char intmp[2005];
inline void Clr() {
  n = RD();
  m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    scanf("%s", intmp);
    for (register unsigned j(0); j < m; ++j) {
      a[i][j + 1] = (intmp[j] == '.') ? 0 : 1;
    }
  }
  nSH = nodeStack;
  flg = 0;
  flg2 = 0;
  return;
}
inline void MT (const unsigned &x, const unsigned &y) {
  if(a[x][y] == 0) {
    a[x][y] = 2;
    (++nSH)->X = x;
    nSH->Y = y;
  }
}
bool DFS (const unsigned &x, const unsigned &y) {
  if(a[x][y] == 1 || a[x][y] == 3) {
    return 0;
  }
  bool HvZ(0);
  if(a[x][y] == 0) {
    HvZ = 1;
  }
  a[x][y] = 3;
  if(x > 1) {
    HvZ = HvZ | DFS(x - 1, y);
  }
  if(x < n) {
    HvZ = HvZ | DFS(x + 1, y);
  }
  if(y > 1) {
    HvZ = HvZ | DFS(x, y - 1);
  }
  if(y < m) {
    HvZ = HvZ | DFS(x, y + 1);
  }
  return HvZ;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      for (register unsigned j(1); j <= m; ++j) {
        if(a[i][j] == 1) {
          if(i < n) {
            MT(i + 1, j);
          }
          if(i > 1) {
            MT(i - 1, j);
          }
          if(j < m) {
            MT(i, j + 1);
          }
          if(j > 1) {
            MT(i, j - 1);
          }
        }
      }
    }
    for (register Node *i(nodeStack + 1); i <= nSH; ++i) {
      if(a[i->X][i->Y] == 2) {
        if(!DFS(i->X, i->Y)) {
          if(flg) {
            printf("YES\n");
            flg2 = 1;
            break;
          }
          else {
            flg = 1;
          }
        }
      }
    }
    if(! flg2) {  
      printf("NO\n");
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



