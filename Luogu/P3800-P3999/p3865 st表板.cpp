#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,x,y,logn;
int main()
{
	cin>>n>>m;//n������,m��ѯ�� 
	int ans[m],log[n+5],f[n+5][17];	
	for(int i=1;i<=n;i++)
		cin>>f[i][0];//���� 
	log[0]=-1;
	for(int i=1;i<=n;i++)
	{
		log[i]=log[i>>1]+1;//Ԥ����log[n] 
	}
	logn=log[n];
	for(int i=1;i<=logn;i++)//Ԥ����f[n][logn],i�ǵ�ǰ���logֵ 
		for(int j=0;j+(1<<i)-1<=n;j++)//j+2^i-1<=n(��֤���䲻���) 
			f[j][i]=max(f[
			-);//�Ѹ������Ϊ����������
	for(int i=0;i<m;i++)//ѯ��m�� 
	{
		cin>>x>>y;
		int s=log[y-x+1];
		cout<<max(f[x][s],f[y-(1<<s)+1][s])<<endl;
	}
	return 0;
}
