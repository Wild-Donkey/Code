#include<iostream>
using namespace std;
int ans=0;//n:ʣ��ɷ�����,m:ʣ��ɷ���λ�� 
void xjj(int nx,int mx,int nn,int &ans)
{
	int a=nx/mx;//��ǰλ������ٽ�
	if(mx<=2)//����߽�
	{
		int c=a+1-nn;
		ans+=c;
	}
	mx--;//ö�ٵ���һλ 
	for(int i=1;i<=a;i++)//ö�ٵ�ǰλ���������� 
		xjj(nx-i,mx,i,ans);//�������� 
	return;
}
int main()
{
	int n,m;
	cin>>n>>m;
	xjj(n,m,0,ans);
	cout<<ans;
	return 0;
}
