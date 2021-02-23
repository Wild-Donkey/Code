#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[1000005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int l=1,r=n,mid=(l+r)/2,ask;
		scanf("%d",&ask);
		while(l<r){
			//cout<<l<<" "<<r<<endl;
			if(a[mid]>=ask){
				r=mid;
			}
			else{
				l=mid+1;
			}
			mid=l+(r-l)/2;
		}
		if(a[l]==ask){
			printf("%d ",l);
		}
		else{
			printf("-1 ");
		}
	}
	cout<<endl;
	return 0;
}
