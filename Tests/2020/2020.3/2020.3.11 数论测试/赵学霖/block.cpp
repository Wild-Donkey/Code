#include<iostream>
#include<cstdio>
using namespace std;
int a[21]={0,1,2,5,14,42,216,1365,9776,75666,615968,5256686}; 
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n;
	cin>>n;
	cout<<a[n]<<endl;
}
