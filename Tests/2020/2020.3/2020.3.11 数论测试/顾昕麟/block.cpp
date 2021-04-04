//AJHµÄ»ıÄ¾
#include<iostream>
using namespace std;
int Catalan[21];
int main()
{
//	freopen("block.in","r",stdin);
//	freopen("block.out","w",stdout);
	Catalan[0]=1;
	Catalan[1]=1;
	int n;
	cin>>n;
	for (int i=2;i<=n;i++)
	{
		Catalan[i]=Catalan[i-1]%19260817*(4*n-2)/(n+1);
		cout<<Catalan[i]<<endl;
	}
	cout<<Catalan[n];
	return 0;
} 
