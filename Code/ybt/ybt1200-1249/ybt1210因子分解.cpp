#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a,i=2,ans[105],n;
bool bj=0;
int main() {
	cin>>n;
	a=n;
	memset(ans,0,sizeof(ans));
	while(a>1&&a>=i) {
		if(!(a%i)) {
			ans[i]++;
			a/=i;
			//cout<<i<<" "<<ans[i]<<endl;
		}
		else
			i++;
	}
	for(int j=2;j<=n;j++){
		if(ans[j]) {
			if(bj)
				cout<<"*";
			if(ans[j]==1)
				cout<<j;
			else {
				cout<<j<<"^"<<ans[j];
			}
			bj=1;
		}
	}
	cout<<endl;
	return 0;
}
