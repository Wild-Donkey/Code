#define fastcall __attribute__((optimize("-O3")))
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int t,n,sum;//sum��¼B��Ԫ�صĸ��� 
int a[110],b[110];//�������Ҳ��m=n���������鿪��110���� 
bool f[25010];//f�����¼������ܲ�����B�е����Ӻ͵õ����������൱�ڱ����е�������������鿪������a��Ԫ�ص����ֵ 
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
inline void write(int x){        
    if(x<0){        
        putchar('-');        
        x=-x;        
    }        
    if(x>9){
        write(x/10);
	}
    putchar(x%10+'0');     
    return;        
}        
int main()
{
	t=read();
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));//��Ҫ����ÿ�����ݶ�Ҫ������� 
		n=read();
		//scanf("%d",&n);
		for(int i=1;i<=n;i++){
            a[i]=read();
			//scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		b[1]=a[1];//����һ��������B 
		sum=1;
		f[0]=1;//����Ҫ��f[0]��ʼ������Ϊ�����������ȿ϶�Ҫ��f[0]ת�ƶ�������Ȼ���ǺϷ��ģ�����f[0]=1 
		for(register int i=2;i<=n;i++){
			for(register int k=1;k<=sum;k++){
				for(register int j=b[k];j<=a[i];j++){//��ȫ�����İ��� 
					if(f[j-b[k]]==1){
						f[j]=1;
					}
				}
			}
			if(f[a[i]]!=1){//���B�е�Ԫ�ز��ܼӺ͵õ�A�еĵ�i��Ԫ�أ���ô���ȼ�1�������������B�� 
				sum++;
				b[sum]=a[i];
			}
		} 
		write(sum);
		printf("\n");
	}
	return 0;
}
