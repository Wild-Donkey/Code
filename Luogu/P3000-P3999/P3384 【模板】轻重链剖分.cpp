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
int n, m, a[100005], ans = 0, cnt2 = 0, A, B;
bool flg;
char ch;
struct Node {
	Node *Fst, *Nxt, *fa[20], *Hvson, *Htop;
	bool vsd;
	int Dep, Siz, num2;
}N[100005], *line[100005], *lca;
struct SegTr {
	SegTr *ls, *rs;
	int Sum, lb, rb;
}S[100005], *cnts = S;
bool IN (int l, int r, SegTr *now) {
	return now->lb >= l && now->rb <= r;
}
bool OUT (int l, int r, SegTr *now) {
	return now->lb >= r || now->rb <= l;
}
void Add (Node *x, Node *y) {
	y->Nxt = x->Fst;
	x->Fst = y;
	return;
}
void DFS1 (Node *x) {
	printf("here %d\n", x - N);
	int i = 0;
	if (x->fa[0]) {
		while ((x->fa[i]->fa[i]) && (i < 19)) {
			x->fa[i + 1] = x->fa[i]->fa[i];
			i++;
		}
	}
	Node *now = x->Fst;
	x->Siz = 1;
	while (now) {
		printf("son %d\n", now - N);
		if (!now->vsd) {
			now->vsd = 1;
			now->fa[0] = x;
			now->Dep = x->Dep + 1;
			DFS1(now);
			x->Siz += now->Siz;
			if (!x->Hvson) {
				x->Hvson = now;
			}
			else {
				if (x->Hvson->Siz < now -> Siz) {
					x->Hvson = now;
				}
			}
		}
		now = now->Nxt;
	}
	return;
}
void DFS2 (Node *x) {
	//printf("DFS2 %d\n", x - N);
	x->num2 = ++cnt2;
	line[cnt2] = x;
	if (x->Hvson) {
		printf("Heavy %d\n", x->Hvson - N);
		x->Hvson->Htop = x->Htop;
		x->Hvson->vsd = 0;
		DFS2(x->Hvson);
	}
	Node *now(x->Fst);
	while (now) {
		if (now->vsd) {
			now->vsd = 0;
			now->Htop = now;
			DFS2(now);
		}
		now = now->Nxt;
	}
}
int LCA (Node *x, Node *y) {
	if (x->Dep < y->Dep) {
		swap(x, y);
	}
	int i(19);
	while (i + 1)  {
		if (x->fa[i]) {
			if (x->fa[i]->Dep >= y->Dep) {
				x = x->fa[i];
			}
		}
		--i;
	}
	if (x == y) {
		return x - N;
	}
	i = 19;
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
		return x - N;
	}
	else {
		return x->fa[0] - N;
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
SegTr *Build (int x, int y) {
	cnts->lb = x;
	cnts->rb = y;
	if (x == y) {
		cnts->Sum = a[x];
		return cnts++;
	}
	int Mid = (x + y) >> 1;
	SegTr *now(cnts++);
	now->ls = Build (x, Mid);
	now->rs = Build (Mid + 1, y);
	now->Sum = now->ls->Sum + now->rs->Sum;
	return now;
}
int Q (int x, int y, SegTr *now) {
	if (OUT(x, y, now)) {
		return 0;
	}
	if (IN(x, y, now)) {
		
	}
	return Q(x, y, now->);
}
void C (int x, int y, int val, SegTr *now) {
	return;
}
int Finds (Node *x) {
	return Q(x - N, x - N + x->Siz - 1, S + 0);
}
void Pluss (Node *x, int val) {
	return C(x - N, x - N + x->Siz - 1, val, S + 0);
}
int Findl (Node *x, Node *y) {
	while (x->Htop->Dep <= y->Dep && x->Htop->fa[0]) {
		++cha[x - N];
		--cha[x->Htop - N + 1];
		x = x->Htop->fa[0];
	}
	++cha[x - N];
	--cha[y - N + 1];
	return;
}
void Plusl (Node *x, Node *y, int val) {
	while (x->Htop->Dep <= y->Dep && x->Htop->fa[0]) {
		++cha[x - N];
		--cha[x->Htop - N + 1];
		x = x->Htop->fa[0];
	}
	++cha[x - N];
	--cha[y - N + 1];
	return;
}
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
	n = In();
	for (register int i(1); i <= n; ++i) {
		a[i] = In();
	}
	for (register int i(2); i <= n; ++i) {
		A = In();
		B = In();
		Add(N + A, N + B);
		Add(N + B, N + A);
	}
	N[1].Htop = &N[1];
	N[1].vsd = 1;
	DFS1(N + 1);
	DFS2(N + 1);
	for (register int i(1); i < m; ++i) {
		Do = In();
		A = In();
		if (Do == 4) {
			Finds (N + A);
		}
		else {
			B = In();
			if (Do == 3) {
				Pluss (N + A, B);
			}
			else {
				lca = N + LCA(N + A, N + B);
				if (Do == 2) {
					Findl (N + A, lca);
					Findl (N + B, lca);
				}
				else {
					C = In();
					Plusl (N + A, lca, C);
					Plusl (N + B, lca, C);
				}
			}
		}
		//--cha[lca - N];
		//++cha[lca - N + 1];
	}
	for (register int i(1); i <= n; ++i) {
		ans += cha[i];
		printf("%d\n", ans);
	}
	/*for (register int i(1); i <= cnt2; ++i) {
		printf("%d", line[i] - N);
	}*/
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
