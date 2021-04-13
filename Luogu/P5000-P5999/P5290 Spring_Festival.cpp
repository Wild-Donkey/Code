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
using namespace std;
inline int RD() {
  char ich = getchar();
  int intmp = 0, insign = 1;
  while (((ich < '0') || (ich > '9')) && ((ich != '-'))) {
    ich = getchar();
  }
  if (ich == '-') {
    insign = -1;
    ich = getchar();
  }
  while ((ich <= '9') && (ich >= '0')) {
    intmp *= 10;
    intmp += ich - '0';
    ich = getchar();
  }
  return intmp * insign;
}
int m, n, M[200005], F[200005];
bool a[105][105];
char ch, s[105];
struct Node {
  int Mem;
  Node *Fa, *Fst, *Nxt;
} N[200005];
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = RD();
  for (register int i(1); i <= n; ++i) {
    N[i].Mem = RD();
  }
  for (register int i(2); i <= n; ++i) {
    N[i].Fa = RD() + N;
    N[i].Nxt = N[i].Fa->Fst;
    N[i].Fa->Fst = N + i;
  }
  for (register int i(1); i <= n; ++i) {
    gets(s);
    for (register int j(1); j <= m; ++j) {
      printf("%d", int(a[i][j]));
    }
    putchar('\n');
  }
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}