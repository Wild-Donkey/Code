#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node
{
    int x;
    int y;
    node() {}
    node(int x1, int y1) :x(x1), y(y1) {}
} s, t;
char ch;
bool flg = 0;
int n, m, vis[1005][1005], u[4][2] = { {0,-1},{-1,0},{0,1},{1,0} }, ans[1005][1005];
void bfs(int x, int y)
{
    vis[x][y] = 1;
    queue<node> q;
    q.push(node(x, y));
    while (!q.empty()) {
        node a = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = a.x + u[i][0];
            int yy = a.y + u[i][1];
            if ((xx >= 1) && (xx <= n) && (yy >= 1) && (yy <= m) && (!(vis[xx][yy]))) {//能搜到这个点
                vis[xx][yy] = 1;
                ans[xx][yy] = ans[a.x][a.y] + 1;
                if ((xx == t.x) && (yy == t.y)) {
                    printf("%d\n", ans[xx][yy]);
                    flg = 1;
                }
                q.push(node(xx, yy));
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    s.x = 1;
    s.y = 1;
    t.x = n;
    t.y = m;
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == '#') {
                vis[i][j] = 1;
            }
        }
    }
    ans[1][1] = 1;
    bfs(1, 1);
    if (!flg) {
        printf("-1\n");
    }
    return 0;
}