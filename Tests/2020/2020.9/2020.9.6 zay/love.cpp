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
int n, m, T, A;
bool flg;
long long L[200005] = {0}, R[200005] = {0}, ans(0);
char ch;
string s;
struct Story {
	int val;
	Story *son, *bro;
}S[200005];
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
int main() {
  freopen("love.in","r",stdin);
  freopen("love.out","w",stdout);
	T = In();
  n = In();
  for (register int i(1); i <= n; ++i) {
    S[i].val = In();
  }
  for (register int i(2); i <= n; ++i) {
  	A = In();
  	S[i].bro = S[A].son;
  	S[A].son = &S[i];
	}
	if (T >= 10 && T <= 12) {
		ans += S[1].val;
		Story *now(S[1].son);
		while (now) {
			L[++L[0]] = -now->val;
			now = now->son;
		}
		now = S[1].son->bro;
		while (now) {
			R[++R[0]] = -now->val;
			now = now->son;
		}
		sort(L + 1, L + L[0] + 1);
		sort(R + 1, R + R[0] + 1);
		/*for (register int i(0); i <= max (L[0], R[0]); ++i) {
			printf("%d %lld %lld\n", i, L[i], R[i]);
		}*/
		for (register int i(1); i <= max (L[0], R[0]); ++i) {
			ans -= min (L[i], R[i]);
		}
		printf("%lld\n", ans);
		return 0;
	}
	printf("WDNMD\n");
  return 0;
}
/*
10
6
1 1 4 5 1 4
1 1 2 3 5
*/
