#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1200;
char s1[maxn],s2[maxn];
int dp[maxn][30];
int MIN(int x,int y){
	if(s1[x]<=s1[y]) return x;
	return y;
}
int query(int l,int r){
	int k = log2(r-l+1);
	return MIN(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(void)
{
  freopen("HDU3183.in", "r", stdin);
  freopen("HDU3183.ans", "w", stdout);
	int n,i,j,len,fg;
	while(~scanf("%s %d",s1+1,&n)){
		len = strlen(s1+1);
		for(i=1;i<=len;i++) dp[i][0] = i;
		for(j=1;(1<<j)<=len;j++){
			for(i=1;i+(1<<j)-1<=len;i++){
				dp[i][j] = MIN(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
			}
		}
		int pos = 1;
		j =0;n = len-n;
		for(i=n-1;i>=0;i--){
			pos = query(pos,len-i);
			s2[j++] = s1[pos++];
		}
		for(i=0;i<j&&s2[i]=='0';i++) ;
		if(i>=j){
			printf("0\n");continue;
		}
		for(;i<j;i++) printf("%c",s2[i]);
		printf("\n");
	}
	return 0;
}
