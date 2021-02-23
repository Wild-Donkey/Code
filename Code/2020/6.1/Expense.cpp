#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
long long n,m,a[1000005],sum[1000005],l,r,mid=0x3fffffff,ma;
bool flg;
bool check(int x){
	//cout<<x<<endl; 
	int j=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(sum[i]-sum[j]>x){
			i--;
			j=i;
			cnt++;
		}
	}
	//cout<<cnt<<endl;
	if(cnt>=m){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
		sum[i]=sum[i-1]+a[i];
		ma=max(a[i],ma);
	}
	l=ma;
	r=sum[n];
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
		if(l==mid){
			if(r==l+1){
				mid++;
				break;
			}
		}
	}
	cout<<mid;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
