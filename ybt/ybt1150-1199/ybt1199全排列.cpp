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
void f(int x) {//x�ǵ�ǰ����b�ĳ��ȣ�����b�Ǵ�0��ʼ�����ģ�����xҲ���������β�����b�ĵ�ǰλ��ָ��
    if(x==l) {//�ݹ�߽磬���ν����ˣ�������
        for(int i=0; i<l; ++i)
            cout<<b[i];
        cout<<endl;
    }
    else {//û�н�������b[x]��λ��ȷ������
        bool bj=0;//�ж�a[i]�Ƿ���b�г��ֹ���Ҫʹ�õı��
        char t;
        for(int i=0; i<l; ++i) {//ö�ٵ�xλ��a[i]
            t=a[i];//��ȡa[i]���ݴ�
            bj=0;
            for(int j = 0; j < x; ++j) {//ɨһ��b���飬�ж�a[i]�Ƿ��������е������г���
                if(b[j]==t) {//�����е���������a[i]
                    bj=1;//����
                    break;//����(�Ѿ��ҵ��ˣ�������ȥҲ�����ҵ�a[i]�ˣ���Ϊ�ַ������ظ�)
                }
            }
            if(bj)//b[j]����֮ǰ���ֹ���a[i]������������һ��a[i]����b
                continue;
            else {
            b[x] = a[i];//����a[i]û�г��ֵ�������Ͱ�a[i]�ŵ�b[j+1]�С�
            f(x+1);//��ȷ��ǰxλ�Ļ����ϣ�ȫ����x+1λ�Լ������Ԫ��
            }
        }
    }
}
