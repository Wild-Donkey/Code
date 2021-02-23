#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int m,n,a[10005],ans=0,tmp=0,mm=1;
bool flg;
char ch;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>m>>s>>n;
	int i=s.length()-1;
	while(i>=0){
		if(s[i]<='9'){
			tmp+=mm*(s[i]-'0');
		}
		else{
			tmp+=mm*(s[i]-'A'+10);
			//cout<<tmp<<" "<<mm<<" "<<s[i]-'A'+10<<endl; 
		}
		i--;
		mm*=m;
	}
	//cout<<tmp;
	i=1;
	while(tmp>0){
		a[i]=tmp%n;
		tmp/=n;
		i++;
	}
	for(int j=i-1;j>=1;j--){
		if(a[j]<10){
			cout<<a[j];
		}
		else{
			cout<<char(a[j]-10+'A');
		}
	}
	cout<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
