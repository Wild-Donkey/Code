#include<cstdio>
int n,m,number[100001],color[100001],ans,a[100001][2],sum[100001][2]; 
int main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; i++) 
        scanf("%d", &number[i]);
	for(int i = 1;i <= n; i++){
		scanf("%d", &color[i]);
		a[color[i]][i%2]++;
		sum[color[i]][i%2] = (sum[color[i]][i % 2] + number[i]) % 10007;
	}
	for(int i = 1;i <= n; i++)
	ans = (ans + i * ((a[color[i]][i % 2] - 2) * number[i] % 10007 + sum[color[i]][i % 2])) % 10007;
	printf("%d", ans);
	return 0;
}
