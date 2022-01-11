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
#include <windows.h>
using namespace std;
int t, n, a[10005], ans = 0;
bool flg;
char ch;
string s;
struct Node {
	char val;
	Node *fa, *fst, *bro;
}N[10005];
inline int In() {
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
void Add (int x, int y) {
	N[y].bro = N[x].fst;
	N[x].fst = &N[y];
	N[y].fa = &N[x];
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
    n = In();
    cin >> s;
    for (register int i = 0; i < n; i++) {
    	N[i + 1].val = ;
	}
    for (register int i = 1; i < n; i++) {
    	Add(In(), i);
    }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
5
(()()
1 1 2 2
*/
