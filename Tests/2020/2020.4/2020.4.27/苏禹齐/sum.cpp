#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=200002;
struct cell{
	int cc;
	long long num;
	long long code;
}c[100001];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int i,n,m,ccc=0;
	long long t=0,t1[N],t2[N],t3[N],k[N];
	memset(t1,0,sizeof(t1));
	memset(t2,0,sizeof(t2));
	memset(t3,0,sizeof(t3));
	memset(k,0,sizeof(k));
	cin>>n>>m;
	for(i=1;i<=n;i++){
		c[i].code=i;
		scanf("%lld",&c[i].num);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&c[i].cc);
		c[i].cc*=2;
		c[i].cc+=c[i].code%2;
	}
	for(i=1;i<=n;i++){
		int f=c[i].cc;
		if(f>ccc)ccc=f;
		t1[f]+=c[i].code*c[i].num;
		t1[f]%=10007;
		t2[f]+=c[i].code;
		t3[f]+=c[i].num;
		k[f]++;
	}
	for(i=1;i<=ccc;i++){
		t2[i]%=10007;
		t3[i]%=10007;
		k[i]%=10007;
		t+=(k[i]-2)*t1[i]+t2[i]*t3[i];
		t%=10007;
	}
	printf("%lld",t);
	fclose(stdin);
    fclose(stdout);
	return 0;
}
