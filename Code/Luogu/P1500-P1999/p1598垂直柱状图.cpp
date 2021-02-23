#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstring> 
using namespace std;
const int Maxn=100001;
int l,ans[26],ma,h,k;
string s,a[4];
int main()
{
	freopen("1598.in","r",stdin);
	freopen("1598.out","w",stdout);
	for(int j=0;j<=3;j++)
		getline(cin,a[j]);
	s=a[0]+a[1]+a[2]+a[3];
	l=s.length();
	for(int j=1;j<=l;j++)	
		if((s[j]<='Z')&&(s[j]>='A'))
			ans[s[j]-'A']++;
	for(int i=0;i<=24;i++)
		ma=max(ma,ans[i]);
	for(int i=ma;i>=1;i--)
		{
			k=-1;
			for(int j=0;j<=24;j++)
				if(ans[j]>=i)
				{
					if(j==0)
					{
						k=0;
						cout<<"*";
					}
					else
					{
						if(k<0)
							for(int ij=1;ij<=2*(j-k)-2;ij++)
								cout<<"2";
						else
							for(int ij=1;ij<=2*(j-k)-1;ij++)
								cout<<"3";
						cout<<"*";
						k=j;
					}
				}
			cout<<endl; 
		}
	for(int i=1;i<=ans[25];i++)
		cout<<"*"<<endl;
	cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y"<<endl<<"Z";
	return 0;
}
