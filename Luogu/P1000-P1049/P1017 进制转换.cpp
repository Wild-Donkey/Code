#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
int m,n,a[10005],ans=0;
bool flg;
char ch;
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>m>>n;
	cout<<m<<"="; 
	int i=1;
	while(abs(m)>=abs(n)){
		a[i]+=m%n;
		if(a[i]<0){
			a[i]-=n;
			a[i+1]++;
		}
		if(a[i]>=abs(n)){
			a[i]+=n;
			a[i+1]--;
		}
		m/=n;
		i++;
	}
	if(m!=0){
		a[i]+=m;
	}
	while((a[i]>=abs(n))||(a[i]<0)){
		if(a[i]>=abs(n)){
			a[i]+=n;
			a[++i]--;
		}
		else{
			a[i]-=n;
			a[++i]++;
		}
	}
	for(int j=i;j>=1;j--){
		if(n>=-9){
			cout<<a[j];
		}
		else{
			if(a[j]<=9){
				cout<<a[j];
			}
			else{
				cout<<char('A'+a[j]-10);
			}
		}
	}
	cout<<"(base"<<n<<")"<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
