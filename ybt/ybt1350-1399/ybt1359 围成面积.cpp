#include<iostream>
#include<queue>
using namespace std;
const int n = 10;
int a[n + 5][n + 5];
int nex[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int ans = 0;
struct m {
    int x;
    int y;
}f, t;
void bfs(int xx, int yy) {
    queue<m> q;
    t.x = xx; t.y = yy;
    a[t.x][t.y] = 1;
    q.push(t);
    while (!q.empty())
    {
        f = q.front();
        for (int k = 0; k < 4; k++)
        {
            int nx = f.x + nex[k][0];
            int ny = f.y + nex[k][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0)
            {
                a[nx][ny] = 1;
                t.x = nx;  t.y = ny;
                q.push(t);
            }
        }
        q.pop();
    }
}
int main() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int j = 0; j <= 9; j++)//以上边缘开始bfs置1 
        if (a[0][j] == 0)bfs(0, j);
    for (int j = 0; j <= 9; j++)//以下边缘开始bfs置1 
        if (a[9][j] == 0)bfs(9, j);
    for (int i = 0; i <= 9; i++)//以左边缘开始bfs置1 
        if (a[0][i] == 0)bfs(0, i);
    for (int i = 0; i <= 9; i++)//以右边缘开始bfs置1 
        if (a[9][i] == 0)bfs(9, i);
    for (int i = 0; i < n; i++)//最后统计没有置1的所有的点，即面积点数 
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)++ans;
    cout << ans;
    return 0;
}