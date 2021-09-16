#include<bits/stdc++.h>

using namespace std;

//#define int long long

template<typename _T>
inline void read(_T& x)
{
	x = 0;char s = getchar();int f = 1;
	while (s < '0' || s>'9') { f = 1;if (s == '-')f = -1;s = getchar(); }
	while ('0' <= s && s <= '9') { x = (x << 3) + (x << 1) + s - '0';s = getchar(); }
	x *= f;
}
const int np = 3e6 + 5;
const int cp = 1e5 + 5;
#define lowbit(x) (x&-x)
int Trie[29][np];
unsigned BIT[cp];
unsigned ans[cp];
int siz[np];
int dfn[np], cnt = 1;
int id[np], id_[np], lim;
int n, m, reg[np], l_[cp], r_[cp];
char s[np];
vector<char> vec[np];
vector<char> pre[np], nxt[np];
vector<int> query[np], endd[np];

inline void add(unsigned x) { while (x <= n) ++BIT[x], x += lowbit(x); }
inline unsigned Query(unsigned x) { unsigned TmpQ(0);while (x) TmpQ += BIT[x], x -= lowbit(x);return TmpQ; }

inline void insert(int c) {
}

inline void insert_(int c)
{
	int now = 1;
	for (auto pch : vec[c])
	{
		int ch = pch - 'a' + 1;
		if (Trie[ch][now]) now = Trie[ch][now];
		else Trie[ch][now] = ++cnt, now = cnt;
	}
	endd[now].emplace_back(c);
}

inline void dfs(int x)
{
	for (auto i : endd[x]) dfn[i] = ++lim, reg[lim] = i;
	//	if(endd[x]) dfn[x] = ++lim,reg[lim] = x;
	for (int i = 1;i <= 26;i++)
	{
		if (!Trie[i][x]) continue;
		dfs(Trie[i][x]);
	}
	//	if(!siz) dfn[id[x]] = ++lim,reg[lim] = id[x];
}

inline void query_pre(int c)
{
	int now = 1;
	int size = 0;
	for (auto px : pre[c])
	{
		int x = px - 'a' + 1;
		for (int ch = 1;ch < x;ch++)
			size += siz[Trie[ch][now]];
		if (Trie[x][now]) now = Trie[x][now];
		else {
			ans[c] = 0;
			l_[c] = r_[c] = 0;
			return;
		}
	}
	l_[c] = size + 1;
	r_[c] = size + siz[now];
}

inline void query_nxt(int c)
{
	int now = 1;
	for (auto px : nxt[c])
	{
		int ch = px - 'a' + 1;
		if (Trie[ch][now]) now = Trie[ch][now];
		else { ans[c] = 0;	return; }
	}
	query[now].emplace_back(c);
}

inline void dfs_(int now)
{
	for (auto x : query[now]) ans[x] -= Query(r_[x]) - Query(l_[x] - 1);
	int son(0);
	for (int ch = 1;ch <= 26;ch++) if (Trie[ch][now]) son++, dfs_(Trie[ch][now]);
	for (auto i : endd[now]) add(dfn[i]);
	for (auto x : query[now]) ans[x] += Query(r_[x]) - Query(l_[x] - 1);
}

signed  main() {
	read(n), read(m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for (unsigned q(1); q <= len; q++) vec[i].emplace_back(s[q]);
		int now = 1; siz[now]++;
		for (auto pch : vec[i]) {
			int ch = pch - 'a' + 1;
			if (Trie[ch][now]) now = Trie[ch][now];
			else Trie[ch][now] = ++cnt, now = cnt;
			siz[now]++;
		}
		endd[now].emplace_back(i);
		id[i] = now;
	}
	dfs(1);

	for (int i = 1;i <= m;i++)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int flag = 0;
		for (int q = 1;q <= len;q++)
		{
			if (s[q] == '*') {
				flag = q;
				break;
			}
			pre[i].emplace_back(s[q]);
		}

		for (int q = len;q >= flag + 1;q--)
			nxt[i].emplace_back(s[q]);
	}

	for (int i = 1;i <= m; i++)
		query_pre(i);
	for (int i = 1;i <= cnt;i++)
	{
		for (int q = 1;q <= 26;q++) Trie[q][i] = 0;
		siz[i] = id[i] = id_[i] = 0;
		endd[i].clear();
	}

	cnt = 1;
	for (int i = 1;i <= n;i++)
		reverse(vec[i].begin(), vec[i].end());

	for (int i = 1;i <= n;i++) insert_(i);

	for (int i = 1;i <= m; i++)
	{
		if (l_[i] && r_[i]) query_nxt(i);
	}

	//	cout<<"*";
	dfs_(1);

	for (int i = 1;i <= m; i++)
		printf("%d\n", ans[i]);

}


