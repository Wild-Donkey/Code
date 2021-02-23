    #include <iostream>
    #include <cstdio>
    using namespace std;
    //Mystery_Sky
    //
    #define M 1000
    int f[M][M], a[M][M];
    int n, ans, maxn;
    int main() {
      freopen("1282.in", "r", stdin);
      freopen("std.out", "w", stdout);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
                f[i][j] = f[i][j-1] + a[i][j];          
            }
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                maxn = 0;
                for(int k = 1; k <= n; k++) {
                    maxn += f[k][j] - f[k][i-1];
                    ans = max(maxn, ans);
                    if(maxn < 0) maxn = 0;
                }
            }
        }
        printf("%d\n", ans);
        return 0;
    }
