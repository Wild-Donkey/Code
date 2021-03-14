#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int m,n,a,ans=0,mm=1;
bool flg;
char ch;
string s;
long long power(int x){
	if(x==0){
		return 1;
	}
	if(x==1){
		return a;
	}
	long long tmp=power(x>>1);
	tmp*=tmp;
	tmp%=n;
	if(x%2){
		tmp*=a;
		tmp%=n;
	}
	return tmp;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>a>>m>>n;
	if(a==0){
		cout<<a<<"^"<<m<<" mod "<<n<<"="<<0<<endl;
	}
	else{
		cout<<a<<"^"<<m<<" mod "<<n<<"="<<power(m)%n<<endl;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
