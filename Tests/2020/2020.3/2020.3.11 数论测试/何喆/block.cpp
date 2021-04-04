#include<iostream>
using namespace std;
const int MOD=19260817;
int n;
/*a[25]={0,1,2,5,14,42,126,378,1134,3402,10206,30618,91854,275562,826686,2480058,7440174,3059705,9179115,8276528,5568767};*/
int lpow(int a,int b){int ans=1;for (int i=0;i<b;i++) ans=ans*a%MOD;return ans;}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n;
	if (n==1) cout<<1;
	else if (n==2) cout<<2;
	else if (n==3) cout<<5;
	else cout<<14*lpow(3,n-4)%MOD;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
