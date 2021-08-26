#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int t,n,a[10005],ans=0;
bool flg;
char ch;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); 
		}
		sort(a+1,a+n+1);
		ans=0x3f3f3f3f;
		for(int i=2;i<=n;i++){
			ans=min(abs(a[i]-a[i-1]),ans);
		}
		cout<<ans<<endl;		
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
