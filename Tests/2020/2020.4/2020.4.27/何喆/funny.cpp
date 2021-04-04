#include<cstdio>
#include<iostream>
using namespace std;
int read(char pos=' ')
{
	short mul=1; long long ans=0; char c=getchar();
	if (c=='-') mul=-1; else ans=c-'0';
	while (c!=pos&&c!='\n')
	{
		c=getchar();
		if (!(c!=pos&&c!='\n')) break;
		ans=ans*10+c-'0';
	}
	return ans*mul;
}
typedef long long ll;
ll k,m,number,n;
int main()
{
	freopen("funny.in","r",stdin);
	freopen("funny.out","w",stdout);
	ll I;
	cin>>k>>m;
	for (I=1;I<=k;I*=10) number+=k/I-I+1;
	--number;
	if (number>=m||k-(I/10)==0&&number<m-1){cout<<0;return 0;}
	for (I=k-(I/10),n=k;number<m-1;number+=I,n*=10)I*=10;
	cout<<max(n-number+m-2,k);
	fclose(stdin);
	fclose(stdout);
	return int('\0');
}
