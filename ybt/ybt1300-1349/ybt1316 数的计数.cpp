#include<iostream>
using namespace std;
long long n,f[1005];
/*long long f(int x) {//x���Ǹ�����������ֵĴ����ҵ���λ
	if(x==1)//��λΪ1�������ټ���
		return 1;
	long long ans=1;//ɶҲ����
	for(int i=1; i<=x/2; i++)
		ans+=f(i);//����һ����
	return ans;
}*/
int main() {
	cin>>n;
	f[1]=1;
	f[0]=1;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=i/2; j++) {
			f[i]+=f[j];
		}
	}
	cout<<f[n]<<endl;
	return 0;
}
