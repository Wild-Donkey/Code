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
int T[1005], n, m, A, B, C, D;
long long ans = -0x3f3f3f3f3f3f3f3f;
bool flg;
char ch;
string s;
struct Edge;
struct Node {
	int C, dep, at;
	bool vsd;
	Edge *Fst;
}N[1005][1005];
struct Edge {
	Node *ed;
	Edge *nxt;
}E[1000005], *cnte = E;
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
void Add (Node *x, Node *y) {
	cnte->ed = y;
	cnte->nxt = x->Fst;
	x->Fst = cnte;
	cnte++;
}
void DFS (Node *x, long long sum) {
	if(!x) {
		return;
	}
	sum += x->C;
	//printf("%d,%d %lld\n", x->at, x->dep, sum);
	if (x->dep == T[x->at]) {
		if (sum > ans) {
			ans = sum;
		}
	}
	Edge *sid = x->Fst;
	Node *now;
	while (sid) {
		now = sid->ed;
		if(!now->vsd) {
			now->vsd = 1;
			DFS(now, sum);
			now->vsd = 0;
		}
		sid = sid->nxt;
	}
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = In();
  m = In();
  memset(N, 0, sizeof(N));
  for (register int i(1); i <= n; ++i) {
    T[i] = In();
  }
  for (register int i(1); i <= n; ++i) {
  	if(T[i]) {
 	 		N[i][1].C = In();
  		N[i][1].at = i;
  		N[i][1].dep = 1;
  		Add(&N[0][0], &N[i][1]);
 	 		for (register int j(2); j <= T[i]; ++j) {
  			N[i][j].C = In();
  			N[i][j].at = i;
  			N[i][j].dep = j;
  			Add(&N[i][j - 1], &N[i][j]);
			}
		}
	}
	for (register int i(1); i <= m; ++i) {
		A = In();
		B = In();
		C = In();
		D = In();
		if (B > D) {
			swap(B, D);
			swap(A, C);
		}
		if (B == 0) {
			if (D > 0) {
				Add(&N[0][0], &N[C][D + 1]);
			}
			continue;
		}
		Add(&N[A][B], &N[C][D + 1]);
		if (B == D) {
			Add(&N[C][D], &N[A][B + 1]);
		}
	}
	N[0][0].vsd = 1;
	DFS(&N[0][0], 0);
	printf("%lld\n",ans);
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
/*
4 3
3 2 4 1

4 2 3
2 5
3 3 4 1
8

1 2  3 3
3 0  2 1
3 1  4 1
*/
