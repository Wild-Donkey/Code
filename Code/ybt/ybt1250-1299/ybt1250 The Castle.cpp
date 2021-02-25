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
};
int n, m;
const int N = 200;
int mapp[N][N];
int vis[N][N];
int u[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int s[4] = { 1,2,4,8 };
int sum = 0;
int maxn;
void bfs(int x, int y)
{

    vis[x][y] = 1;
    queue<node>Q;
    Q.push(node(x, y));
    int cnt = 1;
    while (!Q.empty()) {
        node a = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = a.x + u[i][0];
            int yy = a.y + u[i][1];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && (vis[xx][yy] == 0) && (mapp[a.x][a.y] & s[i]) == 0) {
                cnt++;
                vis[xx][yy] = 1;
                Q.push(node(xx, yy));
            }
        }
    }
    if (cnt > maxn) maxn = cnt;

}
int main()
{
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mapp[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] == 0) {
                sum++;
                bfs(i, j);
            }
        }
    }
    printf("%d\n%d\n", sum, maxn);
    return 0;
}