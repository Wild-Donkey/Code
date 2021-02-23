#include<iostream>
using namespace std;
int n,a,tmp,ans[1005],cnt,po,ten[15];
int main(){
	ten[0]=1;
	for(int i=1;i<=10;i++){
		ten[i]=ten[i-1]*10;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cnt=0;
		po=0;
		while(a>0){
			tmp=a%10;
			if(tmp>0){
				cnt++;
				ans[cnt]=ten[po]*tmp;
			}
			po++;
			a/=10;
		}
		cout<<cnt<<endl;
		for(int j=1;j<=cnt;j++){
			cout<<ans[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
