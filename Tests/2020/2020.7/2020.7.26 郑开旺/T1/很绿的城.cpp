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
int t, n, m, A, B, dre;
bool flg, vsd[100005];
char ch;
string s;
struct Edge {
	int to;
	Edge *nxt;
}E[100005], *Fst[100005];
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
void Add (const int &cn, const int &x, const int &y) {
	E[cn].to = y;
	E[cn].nxt = Fst[x];
	Fst[x] = &E[cn];
	return;
}
void DFS(int x) {
	//printf("arv %d\n", x);
	//vsd[x] = 1;
	Edge *sid(Fst[x]);
	int now;
	while (sid != 0) {
		now = sid->to;
		if (vsd[now]) {
			flg = 1;
			return;
		}
		if (!vsd[now]) {
			vsd[now] = 1;
			DFS(now);
			vsd[now] = 0;
			if(flg) {
				return;
			}
		}
		sid = sid->nxt;
	}
	return;
}
int main() {
  freopen("city3.in","r",stdin);
  //freopen("city.out","w",stdout);
  t = In();
  for (register int T(1); T <= t; ++T) {
  	flg = 0;
    n = In();
    m = In();
    memset(vsd, 0, sizeof(vsd));
    memset(E, 0, sizeof(E));
    memset(Fst, 0, sizeof(Fst));
    for (register int i(1); i <= m; ++i) {
    	A = In();
    	B = In();
			Add(i, A, B);
		}
		for (register int i(1); i <= n; ++i) {
			//if (!vsd[i]) {
				vsd[1] = 1;
  			DFS(1);
  			vsd[1] = 0;
  		//}
		}
		if (flg) {
			printf("2\n");
		}
		else {
			printf("1\n");
		}
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
2
4 3
1 3
2 3
2 4
4 5
1 2
1 3
2 4
4 3
3 2
*/
