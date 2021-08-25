#include<bits/stdc++.h> 
#define inf 1000000
using namespace std;
typedef long long ll;
int rd() {
	int res = 0, fl = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') fl = -1; c = getchar(); }
	while (isdigit(c)) { res = (res << 3) + (res << 1) + c - '0'; c = getchar(); }
	return res * fl;
}
const int maxn = 30010;
struct Edge {
	unsigned to, nxt;
}ed[maxn << 1];
char op[10];
unsigned A, B, n, q, en, l, r, fst[maxn], son[maxn], top[maxn], sze[maxn], dep[maxn], seg[maxn], father[maxn];
int w[maxn], AnsMax;
ll AnsSum;
void add(int u, int v) {
	ed[++en].to = v;
	ed[en].nxt = fst[u];
	fst[u] = en;
}
void dfs1(int u) {
	sze[u] = 1;
	register unsigned maxsze(0);
	for (register int e = fst[u]; e; e = ed[e].nxt) {
		int v = ed[e].to;
		if (v ^ father[u]) {
			father[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			if (sze[v] > maxsze) maxsze = sze[v], son[u] = v;
			sze[u] += sze[v];
		}
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	seg[u] = ++seg[0];
	if (son[u]) {
		dfs2(son[u], tp);
	}
	for (register int e = fst[u]; e; e = ed[e].nxt) {
		int v = ed[e].to;
		if (v == son[u] || v == father[u]) continue;
		dfs2(v, v);
	}
}
struct Node {
	int maxval, sum;
	Node* ls, * rs;
	void upd(const int Pos, const int x, unsigned l, unsigned r) {
		if (l == r) { maxval = sum = x;return; }
		register unsigned Mid((l + r) >> 1);
		if (Pos <= Mid) ls->upd(Pos, x, l, Mid);
		else rs->upd(Pos, x, Mid + 1, r);
		maxval = max(ls->maxval, rs->maxval);
		sum = ls->sum + rs->sum;
	}
	int querymax(const int L, const int R, unsigned l, unsigned r) {
		if (L <= l && r <= R) return maxval;
		register int TmpM(0xafafafaf);
		register unsigned Mid((l + r) >> 1);
		if (L <= Mid) TmpM = max(TmpM, ls->querymax(L, R, l, Mid));
		if (R > Mid) TmpM = max(TmpM, rs->querymax(L, R, Mid + 1, r));
		return TmpM;
	}
	ll querysum(const int L, const int R, unsigned l, unsigned r) {
		if (L <= l && r <= R) return sum;
		register long long TmpS(0);
		register unsigned Mid((l + r) >> 1);
		if (L <= Mid) TmpS += ls->querysum(L, R, l, Mid);
		if (R > Mid) TmpS += rs->querysum(L, R, Mid + 1, r);
		return TmpS;
	}
}Mem[maxn << 1], * pool(Mem);
void build(Node* x, const int L, const int R) {
	if (L == R) {
		x->maxval = x->sum = w[L];
		x->ls = x->rs = NULL;
	}
	else {
		int M = (L + R) >> 1;
		build(x->ls = ++pool, L, M);
		build(x->rs = ++pool, M + 1, R);
		x->maxval = max(x->ls->maxval, x->rs->maxval);
		x->sum = x->ls->sum + x->rs->sum;
	}
}
void Query(int x, int y, int tpy) {
	while (top[x] ^ top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		if (tpy == 1) AnsMax = max(AnsMax, Mem->querymax(seg[top[x]], seg[x], 1, seg[0]));
		else AnsSum += Mem->querysum(seg[top[x]], seg[x], 1, seg[0]);
		x = father[top[x]];
	}
	if (dep[x] < dep[y]) swap(x, y);
	if (tpy == 1) AnsMax = max(AnsMax, Mem->querymax(seg[y], seg[x], 1, seg[0]));
	else AnsSum += Mem->querysum(seg[y], seg[x], 1, seg[0]);
	return;
}
int main() {
	n = rd();
	for (register int i = 1; i < n; ++i) {
		A = rd(), B = rd(), add(A, B), add(B, A);
	}
	dfs1(1), dfs2(1, 1);
	for (register int i = 1; i <= n; ++i) w[seg[i]] = rd();
	build(Mem, 1, n);
	q = rd();
	for (register int i = 1; i <= q; ++i) {
		scanf("%s", &op);
		// cin >> op;
		if (op[1] == 'H') {
			l = rd();
			Mem->upd(seg[l], rd(), 1, seg[0]);
		}
		else if (op[1] == 'M') {
			AnsMax = 0xafafafaf;
			A = rd(); B = rd();
			Query(A, B, 1);
			printf("%d\n", AnsMax, 1, seg[0]);
		}
		else {
			AnsSum = 0;
			A = rd(); B = rd();
			Query(A, B, 0);
			printf("%lld\n", AnsSum, 1, seg[0]);
		}
	}
	return 0;
}