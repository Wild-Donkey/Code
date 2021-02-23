#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int t,n,a,b[205],c[205],ans=0;
bool flg;
char ch;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			cin>>a; 
			if(a%2){
				c[0]++;
				c[c[0]]=a;
			} 
			else{
				b[0]++;
				b[b[0]]=a;
			}
		}
		if(n%2){
			cout<<"NO"<<endl;
			continue;
		}
		/*for(int i=0;i<=b[0];i++){
			cout<<b[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<=c[0];i++){
			cout<<c[i]<<" ";
		}
		cout<<endl;*/
		if(!(b[0]%2)){
			cout<<"YES"<<endl;
			continue;
		}
		if(!(c[0]%2)){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			sort(b+1,b+b[0]+1);
			sort(c+1,c+c[0]+1);
			int i=1,j=1;
			while((i<=b[0])&&(j<=c[0])){
				if(abs(b[i]-c[j])<=1){
					cout<<"YES"<<endl;
					break;
				}
				if(b[i]>c[j]){
					j++;
				}
				else{
					i++;
				}
			}
			if((i>b[0])||(j>c[0])){ 
				cout<<"NO"<<endl;
				continue;
			} 
		}
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
