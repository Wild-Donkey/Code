#include<iostream>
using namespace std;
long long a,b,n,m,k,x; 
int main()
{
	cin>>n>>m>>k>>x;
	a=m;
	//k%=n;
	for(int i=1;i<=k;i++)
	{
		b=(a*10)%n;
		a=b;
		cout<<a<<"	"<<i<<endl;
	}
	x=(x+a)%n;
	cout<<x;
	return 0;
}
