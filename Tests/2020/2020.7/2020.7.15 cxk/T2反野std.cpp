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
int t,n,sum;//sum记录B中元素的个数 
int a[110],b[110];//最差的情况也是m=n，所以数组开到110即可 
bool f[25010];//f数组记录这个数能不能由B中的数加和得到，由于它相当于背包中的体积，所以数组开到数组a中元素的最大值 
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
		memset(f,0,sizeof(f));//不要忘记每组数据都要清空数组 
		n=read();
		//scanf("%d",&n);
		for(int i=1;i<=n;i++){
            a[i]=read();
			//scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		b[1]=a[1];//将第一个数加入B 
		sum=1;
		f[0]=1;//首先要将f[0]初始化，因为如果两个数相等肯定要由f[0]转移而来，显然这是合法的，所以f[0]=1 
		for(register int i=2;i<=n;i++){
			for(register int k=1;k<=sum;k++){
				for(register int j=b[k];j<=a[i];j++){//完全背包的板子 
					if(f[j-b[k]]==1){
						f[j]=1;
					}
				}
			}
			if(f[a[i]]!=1){//如果B中的元素不能加和得到A中的第i个元素，那么长度加1并将这个数加入B中 
				sum++;
				b[sum]=a[i];
			}
		} 
		write(sum);
		printf("\n");
	}
	return 0;
}
