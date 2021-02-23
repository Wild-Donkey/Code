#include<iostream>
using namespace std;
int ans,n,t;
void f(int a,int b);
int main() {
    cin>>t;
    for(int k=1;k<=t;k++) {
        ans=1;//这要算上n本身作为唯一因数的情况
        cin>>n;
        f(2,n);//前面已经讨论了1*n的情况，这里要跳过，从2开始递归
        cout<<ans<<endl;
    }
    return 0;
}
void f(int a,int b) {//a，b分别是当前的n的较小因数和较大因数(操作将累计将b分成最小因数大于等于a的所有方案数)
    for(int i=a;i<=b;i++) {//分解b，实际上i最后不会达到b，在大约根号b时就会跳出函数
		if((!(b%i))&&(b/i>=i)) {//满足b可以被i整除，并且i小于等于根号b
			ans++;//先将b分解为只有唯一因数(它本身)的情况
			f(i,b/i);//然后再讨论把b分成i和b/i的情况
		}
		if(b/i<i)//i大于根号b,结束递归
         	return;
    }
    return;//不会被执行到，详见第二行注释，但是会使强迫症舒服
}
