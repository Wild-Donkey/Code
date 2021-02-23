#include<iostream>
#include<cstring>
using namespace std;
int a[105][105],n;
int main() {
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1; i<=n; i++)
		a[i][1]=1;
	for(int i=1; i<=n; i++)
		for(int j=2; j<=i; j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=4*(n-i); j++)
			cout<<" ";
		for(int j=1; j<=i; j++)
			printf("%8d",a[i][j]);//¿í500£¬¸ß300 
		cout<<endl;
	}
	return 0;
}
