#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
    int x, y;
};
int n, m;
int u[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
char s[300][300];
void BFS(int a, int b)
{
    queue<node>Q;
    s[a][b] = '0';
    node c;
    c.x = a;
    c.y = b;
    Q.push(c);
    while (!Q.empty()) {
        node d = Q.front();
        for (int i = 0; i < 4; i++) {
            int xx = d.x + u[i][0];
            int yy = d.y + u[i][1];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && (s[xx][yy] != '0')) {
                s[xx][yy] = '0';
                node e;
                e.x = xx;
                e.y = yy;
                Q.push(e);
            }
        }
        Q.pop();
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> s[i][j];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '0') {
                sum++;
                BFS(i, j);
            }
        }
    }
    cout << sum << endl;
    return 0;
}