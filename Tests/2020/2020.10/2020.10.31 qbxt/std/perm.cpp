#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int MAXN = 205;
const int MOD = 998244353;

int d[MAXN][MAXN][MAXN];
int p[MAXN], l[MAXN], r[MAXN];
int n, K;

int solve(){
    memset(d, 0, sizeof(d));
    forn(i, n) {
        l[i] = i;
        while (l[i] >= 0 && p[l[i]] <= p[i]) l[i]--;
        r[i] = i;
        while (r[i] < n && p[r[i]] <= p[i]) r[i]++;
        l[i]++;
        r[i]--;
    }
    d[0][0][0] = 1;
    forn(i, n) {
        forn(j, n + 1) {
            forn(k, K + 1) {
                if (d[i][j][k] == 0) continue;
                d[i + 1][j][k] += d[i][j][k];
                if (d[i + 1][j][k] >= MOD) d[i + 1][j][k] -= MOD;
                if (j < l[i]) {
                    continue;
                }
                int start = max(l[i], j);
                for (int pos = start; pos <= r[i]; pos++) {
                    int nk = k + 1;
                    if (start == i && pos == i) nk--;
                    d[i + 1][pos + 1][nk] += d[i][j][k];
                    if (d[i + 1][pos + 1][nk] >= MOD) d[i + 1][pos + 1][nk] -= MOD;         
                }            
            }
        }
    }

    int ans = 0;
    forn(k, K + 1) ans = (ans + d[n][n][k]) % MOD;
    return ans;
   }

int main(){
    scanf("%d%d", &n, &K);
    forn(i, n) {
        scanf("%d", &p[i]);
    }
    int ans = solve();
    printf("%d", ans);
    return 0;
}
