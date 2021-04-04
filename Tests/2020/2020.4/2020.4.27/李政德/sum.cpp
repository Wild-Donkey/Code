#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MOD 10007
using namespace std;
const int MAXN = 100000 + 5;
struct Node 
{
    int color;
    int number;
    int ID;
} a[MAXN];
int n, m;
bool Rule(const Node &a, const Node &b) 
{
    return ((a.ID % 2 == b.ID % 2) && (a.color == b.color) && (a.ID < b.ID)) 
        || ((a.ID % 2 == b.ID % 2) && (a.color < b.color)) || (a.ID % 2 < b.ID % 2);
}
int result(int x, int z)
{
    return (a[x].ID + a[z].ID) * (a[x].number + a[z].number);
}

int main() 
{
	freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].number), a[i].ID = i;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].color);
    int ans = 0;
    sort(a + 1, a + 1 + n, Rule);
    for (int i = 1; i <= n; ++i)
            for (int k = i + 1; k <= n; ++k) {
                if ((a[i].ID + a[k].ID) & 1) break;
                if (a[i].color != a[k].color) break; 
                ans += result(i, k) % MOD;
            }
    printf("%d\n", ans % MOD);
    return 0;
}
