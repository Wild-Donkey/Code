#include<iostream>
#include<cstdio>
using namespace std;
int n,r,ans[30];
void dfs(int at,int x) {//at��ʾ��ǰҪ�жϵ�λ��x��ʾ��һλ������(��һλ������Ҫ��x֮����)
	for(int i=x+1;i<=n;i++) {//ö��atλ���п��е�����
		ans[at]=i;//��ֵ
		if(at==r) {//λ���Ѿ��㹻���������
			for(int j=1;j<=r;j++){
				printf("%3d",ans[j]);//��ʽ
			}
			cout<<endl; 
		}
		else{
			dfs(at+1,i);//��ǰλ�������һλ������dfs����iΪ��ǰλ��Ҳ����at+1λ����һλ
		}
	}
	return;
}
int main() {
	cin>>n>>r;
	dfs(1,0);//��ͬ����㣺��0λ��Զ��0
	return 0;
}
