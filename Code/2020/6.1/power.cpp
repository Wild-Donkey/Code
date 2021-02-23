#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int n,m,two[10005],a[10005],ans=1;
bool flg;
char ch;
string s;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n>>m;
	two[0]=1;
	a[0]=n;
	for(int i=1;i<=30;i++){
		two[i]=two[i-1]<<1;
		//cout<<i<<" "<<two[i]<<endl;
		a[i]=a[i-1]*a[i-1];
		//cout<<a[i]<<endl;
	}
	int i=30;
	while((m>=0)&&(i>=0)){
		if(m>=two[i]){
			//cout<<two[i]<<endl;
			ans*=a[i];
			m-=two[i];
		}
		i--;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
