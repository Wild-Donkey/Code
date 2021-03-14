#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int t,n,m;
bool flg;
char ch;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n>>m;
		if(m>=n){
			cout<<1<<endl;
			continue;
		}
		int i=1;
		while(i<=sqrt(n)){
			if((!(n%i))&&((n/i)<=m)){
				cout<<i<<endl;
				break;
			}
			i++;
		}
		if(i>sqrt(n)){
			i=sqrt(n);
			while(i>=1){
				if((!(n%i))&&(i<=m)){
					cout<<n/i<<endl;
					break;
				}
				i--;
			}
			if(i==0){
				cout<<n<<endl;
			}
		}
	}
	//1 440404979 7
	return 0;
}
