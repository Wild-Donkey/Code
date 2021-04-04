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
int t, n, m, s, A, B, ans = 0;
bool flg;
priority_queue <pair<int, int> > q;
struct Node;
struct Edge {
	Edge *Nxt;
	Node *To;
}E[300005], *cnte = E;
struct Node {
	Edge *Fst;
	bool Vsd;
	int Val, MinMax;
}N[300005];
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
	cnte->To = y;
	cnte->Nxt = x->Fst;
	x->Fst = cnte;
	++cnte;
	return;
}
void Dijkstra () {
	q.push(make_pair(-N[s].MinMax, s));
	Node *now, *son;
	Edge *sid;
	while (q.size()) {
		now = N + q.top().second;
		q.pop();
		if (now->Vsd) {
			continue;
		}
		now->Vsd = 1;
		sid = now->Fst;
		while (sid) {
			//printf("now %d %d\n", now - N, sid->To - N);
			son = sid->To;
			if (son->MinMax > max(now->MinMax, son->Val)) {
				son->MinMax = max(now->MinMax, son->Val);
				q.push(make_pair(-son->MinMax, son - N));
			}
			sid = sid->Nxt;
		}
	}
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  t = In();
  for (register int T(1); T <= t; ++T) {
  	n = In();
  	m = In();
  	s = In();
  	memset(N, 0, sizeof(N));
  	memset(E, 0, sizeof(E));
  	cnte = E;
  	for (register int i(1); i <= n; ++i) {
  		N[i].Val = In();
  		N[i].MinMax = 0x7fffffff;
		}
  	for (register int i(1); i <= m; ++i) {
    	A = In();
    	B = In();
    	Add (N + A, N + B);
  	}
  	N[s].MinMax = N[s].Val;
  	Dijkstra();
  	for (register int i(1); i < n; ++i) {
  		printf("%d ", N[i].MinMax);
		}
		printf("%d\n", N[n].MinMax);
	}
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}

