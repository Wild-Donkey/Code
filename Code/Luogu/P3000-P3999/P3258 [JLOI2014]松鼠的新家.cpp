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
int n, m, a[300005], A, B;
bool flg;
char ch;
string s;
struct Node;
struct Edge {
	Edge *Nxt;
	Node *To;
}E[600005], *cnte = E;
struct Node {
	Edge *Fst;
	Node *fa[21];
	bool vsd;
	int Dep, Tag;
	long long Sum;
}N[300005], *lca;
void Add (Node *x, Node *y) {
	cnte->To = y;
	cnte->Nxt = x->Fst;
	x->Fst = cnte;
	++cnte;
	return;
}
void DFS1 (Node *x) {
	//printf("here %d\n", x - N);
	int i = 0;
	if (x->fa[0]) {
		while ((x->fa[i]->fa[i]) && (i < 19)) {
			x->fa[i + 1] = x->fa[i]->fa[i];
			i++;
		}
	}
	Edge *sid(x->Fst);
	Node *now;
	while (sid) {
		now = sid->To;
		sid = sid->Nxt;
		if (!now->vsd) {
			now->vsd = 1;
			now->fa[0] = x;
			now->Dep = x->Dep + 1;
			DFS1(now);
		}
	}
	return;
}
void DFS2 (Node *x) {
	//printf("here %d val %d\n", x - N, x->Tag);
	Edge *sid(x->Fst);
	Node *now;
	x->Sum = x->Tag;
	while (sid) {
		now = sid->To;
		sid = sid->Nxt;
		if (now->vsd) {
			now->vsd = 0;
			DFS2(now);
			x->Sum += now->Sum;
		}
	}
	return;
}
Node *LCA (Node *x, Node *y) {
	if (x->Dep < y->Dep) {
		swap(x, y);
	}
	int i(20);
	while (i + 1)  {
		if (x->fa[i]) {
			if (x->fa[i]->Dep >= y->Dep) {
				x = x->fa[i];
			}
		}
		--i;
	}
	if (x == y) {
		return x;
	}
	i = 20;
	while (i + 1) {
		if (x->fa[i] && y->fa[i]) {
			if (x->fa[i] != y->fa[i]) {
				x = x->fa[i];
				y = y->fa[i];
			}
		}
		--i;
	}
	if (x == y) {
		return x;
	}
	else {
		return x->fa[0];
	}
}
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
void Change (Node *x, Node *y) {
	//printf("Change %d to %d\n", x - N, y - N);
	++x->Tag;
	++y->Tag;
	lca = LCA(x, y);
	--lca->Tag;
	if (lca->fa[0]) {
		//printf("Change %d\n", lca - N);
		--lca->fa[0]->Tag;
	}
	return;
}
int main() {
  // freopen("P3258_1.in","r",stdin);
  // freopen(".out","w",stdout);
	n = In();
	memset(N, 0, sizeof(N));
	for (register int i(1); i <= n; ++i) {
		a[i] = In();
	}
	for (register int i(2); i <= n; ++i) {
		A = In();
		B = In();
		Add(N + A, N + B);
		Add(N + B, N + A);
	}
	N[1].vsd = 1;
	DFS1 (N + 1);
	for (register int i(1); i < n; ++i) {
		Change (N + a[i], N + a[i + 1]);
	}
	N[1].vsd = 0;
	DFS2 (N + 1);
	++N[a[1]].Sum;
	for (register int i(1); i <= n; ++i) {
		printf("%lld\n", --N[i].Sum);
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
/*
5
1 4 5 3 2
1 2
2 4
2 3
4 5
*/
