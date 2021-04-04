#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	long long a[25];
    a[1]=1,a[2]=2,a[3]=5,a[4]=14,a[5]=42;
	a[6]=132,a[7]=429,a[8]=1430,a[9]=4862,a[10]=16796;
	a[11]=58786,a[12]=208012,a[13]=742900,a[14]=2674440,a[15]=9694845;
	a[16]=16096853,a[17]=14079888,a[18]=15379092,a[19]=14528843,a[20]=15442640;
	int n;
	cin>>n;
	cout<<a[n];
	return 0;
}
