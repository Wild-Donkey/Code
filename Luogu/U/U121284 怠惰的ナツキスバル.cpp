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
int n, m, rest, reed, fa[10005], ans = 0;
bool flg;
char ch;
string s;
struct Edge {
  int st, ed, val;
} E[200050];
inline int IN() {
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
bool cmp(Edge x, Edge y) { return x.val < y.val; }
int Find(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = Find(fa[x]);
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = IN();
  m = IN();
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    E[i].st = IN();
    E[i].ed = IN();
    E[i].val = IN();
  }
  rest = IN();
  reed = IN();
  sort(E + 1, E + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    if (Find(E[i].st) == Find(E[i].ed)) {
      continue;
    }
    fa[Find(E[i].st)] = Find(fa[E[i].ed]);
    if (Find(rest) == Find(reed)) {
      printf("%d", E[i].val);
      return 0;
    }
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
