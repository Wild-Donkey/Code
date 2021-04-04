#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
int i,j,n,m,l,r,mid,ans;
int a[100005];
bool check(int x){
    int tot=0,num=0;
    for(j=1;j<=n;j++){
        if(tot+a[j]<=x){
        	tot+=a[j];
		}
        else if(tot+a[j]>x){
        	tot=a[j];
        	num++;
		} 
    }
    if(num>=m){
    	return true;
	}else if(num<m){
		return false;
	}
}
int main(){
	freopen("Expense.in","r",stdin);
	freopen("Expense.out","w",stdout);
	cin>>n>>m;
    for(i=1;i<=n;i++){
    	cin>>a[i];
		l=max(l,a[i]);
		r+=a[i];
	}
    while(l<=r){
    	mid=(l+r)/2;
        if(check(mid)==true){
        	l=mid+1;
		}
        else if(check(mid)==false){
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}
