#include <bits/stdc++.h>
using namespace std;

const int N = 256, P = 998244353;
int p[N];

struct trie
{
    int ch[N][10], f[N], val[N];
    int siz, rt;
    int nnew()
    {
        memset(ch[siz], 0xff, sizeof ch[siz]), val[siz] = 0;
        return siz++;
    }
    int idx(char c)
    {
        return c - '0';
    }
    void insert(const char *s, int id)
    {
        int u = 0;
        for (int i = 0; s[i]; i++)
        {
            int c = idx(s[i]);
            if (!~ch[u][c])
                ch[u][c] = nnew();
            u = ch[u][c];
        }
        val[u] |= (1 << id);
    }
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 10; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] |= val[f[u]];
            for (int c = 0; c < 10; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
    }
    vector<int> l, r;
    int all;
    pair<int, int> dp[N][N][1 << 5];
    bool vis[N][N][1 << 5];

    void set(vector<int> &x)
    {
        static char buf[N];
        scanf("%s", buf);
        int n = strlen(buf);
        x.resize(n);
        for (int i = 0, j = n - 1; ~j; i++, j--)
            x[i] = buf[j] - '0';
    }
    void init(int n)
    {
        all = (1 << n) - 1;
        siz = 0, rt = nnew();
        set(l), set(r);
        l.resize(r.size());
    }
    pair<int, int> dfs(int pos, int u, int state = 0, bool lead = 1, bool lil = 1, bool lir = 1)
    {
        if (!~pos)
            return make_pair(state == all, 0);
        if (!lil && !lir && !lead && vis[pos][u][state])
            return dp[pos][u][state];
        pair<int, int> ans = {0, 0};
        for (int c = 0; c < 10; c++)
        {
            if (lil && c < l[pos])
                continue;
            if (lir && c > r[pos])
                continue;
            int v = u;
            if (!lead || c)
                v = ch[u][c];
            auto tmp = dfs(pos - 1, v, state | val[v], lead && c == 0, lil && c == l[pos], lir && c == r[pos]);
            ans.first += tmp.first;
            if (ans.first >= P)
                ans.first -= P;
            int o = 1ll * c * p[pos] % P;
            ans.second += (1ll * o * tmp.first % P + tmp.second) % P;
            if (ans.second >= P)
                ans.second -= P;
        }
        if (!lil && !lir && !lead)
        {
            vis[pos][u][state] = true;
            dp[pos][u][state] = ans;
        }
        return ans;
    }
    int solve()
    {
        pair<int, int> ans = dfs(r.size() - 1, rt);
        return ans.second;
    }
} tr;

int n;
int main()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = 10ll * p[i - 1] % P;
    scanf("%d", &n);
    tr.init(n);
    for (int i = 0; i < n; i++)
    {
        char buf[1024];
        scanf("%s", buf);
        tr.insert(buf, i);
    }
    tr.build();
    printf("%d\n", tr.solve());
    return 0;
}
