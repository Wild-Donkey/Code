#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
struct job{
	int ti,val;
}a[10005];
struct Ti{
	int a,l,r;
}Time[100005];
int cnt=0;
bool Cmp(job x,job y){
	return x.val>y.val;
}
int t,n,ans=0;
bool flg;
char ch;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].ti,&a[i].val); 
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int j=1;
		while(){
			
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
