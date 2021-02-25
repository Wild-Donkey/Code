#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int l;
void f(int x);
int main() {
    cin>>a;
    l=a.length();
    f(0);
    return 0;
}
void f(int x) {//x是当前数组b的长度，由于b是从0开始命名的，所以x也可以做本次操作的b的当前位的指针
    if(x==l) {//递归边界，本次结束了，输出结果
        for(int i=0; i<l; ++i)
            cout<<b[i];
        cout<<endl;
    }
    else {//没有结束，将b[x]的位置确定下来
        bool bj=0;//判断a[i]是否在b中出现过将要使用的标记
        char t;
        for(int i=0; i<l; ++i) {//枚举第x位是a[i]
            t=a[i];//提取a[i]并暂存
            bj=0;
            for(int j = 0; j < x; ++j) {//扫一遍b数组，判断a[i]是否在已排列的数组中出现
                if(b[j]==t) {//已排列的数组中有a[i]
                    bj=1;//打标记
                    break;//跳出(已经找到了，再找下去也不会找到a[i]了，因为字符串不重复)
                }
            }
            if(bj)//b[j]就是之前出现过的a[i]，所以再找下一个a[i]放入b
                continue;
            else {
            b[x] = a[i];//这是a[i]没有出现的情况，就把a[i]放到b[j+1]中。
            f(x+1);//在确定前x位的基础上，全排列x+1位以及后面的元素
            }
        }
    }
}
