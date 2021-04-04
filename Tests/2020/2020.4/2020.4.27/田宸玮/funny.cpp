#include<iostream> 
#include<cstdio> 
using namespace std;
int main ()
{
	freopen("funny.in","r",stdin);
	freopen("funny.out","w",stdout);
	long long a,b,i,s=0,n;
    cin>>a>>b;
    for (i=1;i<=a;i*=10)
    {
    	s=s+a/i-i+1;	
    }
    s--;
    if(s>=b||a-(i/10)==0&&s<b-1)
    { 
    	cout<<0;
    	return 0;
    } 
	n=a; 
    for(i=a-(i/10);s<b-1;)
    {
		i=i*10;
		s=s+i;
		n=n*10;
    }
    cout<<max(n-s+b-2,a);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
