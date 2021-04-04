#include<cstdio>
#include<iostream>
#define maxn 100010
using namespace std;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int m,n,number[maxn],color[maxn],sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>number[i]; 
	for(int i=1;i<=n;i++)
	cin>>color[i];
	for(int i=1;i<=n;i++){
		int k=1;
		while(i-k>=1&&i+k<=n){
			if(color[i-k]==color[i+k])
			sum+=2*i*(number[i-k]+number[i+k]);
			sum%=10007;
			k++;
		}
	}
	cout<<sum;
	return 0;
}

