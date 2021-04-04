#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define fi first
#define se second

const int maxn = 5005;
const int maxm = 5100;

int n,H;
PII a[maxn];
int dp[maxm];


bool cmp(const PII &a, const PII &b)
{
    return a.se != b.se ? a.se > b.se : a.fi - a.se > b.fi - b.se;
}

int solve()
{
    int ans = 0;
    sort(a, a + n, cmp);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i ++)
    {
        for (int j = H - a[i].fi; j >= 0; j --)
        {
            if (dp[j] != -1)
            {
                dp[j + a[i].fi - a[i].se] = max(dp[j + a[i].fi - a[i].se], dp[j] + 1);
                ans = max(ans, dp[j + a[i].fi - a[i].se]);
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d%d", &n, &H);
    for (int i = 0; i < n; i ++)
        scanf("%d", &a[i].first);
    for (int i = 0; i < n; i ++)
        scanf("%d", &a[i].second);
    int ans = solve();
    printf("%d", ans);
    return 0;
}
