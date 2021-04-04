#include<iostream>
using namespace std;
int a[21];
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n;
	cin>>n;
	a[1]=1;
	a[2]=2;
	a[3]=5;
	a[4]=14;
	a[5]=42;
	a[6]=132;
	a[7]=429;
	a[8]=1430;
	a[9]=4862;
	a[10]=16796;
	a[11]=58786;
	a[12]=208012;
	a[13]=742900;
	a[14]=2674440;
	a[15]=9694845;
	a[16]=35357670;
	a[17]=129644790;
	a[18]=477638700;
	a[19]=1767263190;
	a[20]=6564120420;
	
	cout<<a[n]; 
	return 0;
}


