//���Ի�ģ���⣺��n�����������Ӽ����������
#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],b[64];
void work(){
	int i,j,k;
	for(i = 1;i <= n;++i){
		for(j = 60;j >= 0;--j){
			if((a[i] >> j) & 1){
				if(b[j]) a[i] ^= b[j];
				else{
					b[j] = a[i];
					for(k = j - 1;k >= 0;--k) if(b[k] && ((b[j] >> k) & 1) ) b[j] ^= b[k];
					for(k = j + 1;k <= 60;++k) if((b[k] >> j) & 1) b[k] ^= b[j];
					break;
				}
			}
			
		}
	}
}
//��һ��д���� 
void work2(){
	int i,j;
	for(i = 1;i <= n;++i){
		for(j = 60;j >= 0;--j){
			if(!(a[i] >> j & 1)) continue;
			if(!b[j]){
				b[j] = a[i];
				break;
			}
			a[i] ^= b[j];
		}
	}
}//��ôдû���������Խ�������Ķ�����λ�������Խ��ߴ��ڵ�����£� 
int main(){
	int i;
	scanf("%lld",&n);
	for(i = 1;i <= n;++i) scanf("%lld",&a[i]);
	work(); 
	long long ans = 0;
	for(i = 0;i <= 60;++i) ans ^= b[i];
	printf("%lld",ans);
	return 0;
}
