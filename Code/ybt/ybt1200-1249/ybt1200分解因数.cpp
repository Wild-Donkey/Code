#include<iostream>
using namespace std;
int ans,n,t;
void f(int a,int b);
int main() {
    cin>>t;
    for(int k=1;k<=t;k++) {
        ans=1;//��Ҫ����n������ΪΨһ���������
        cin>>n;
        f(2,n);//ǰ���Ѿ�������1*n�����������Ҫ��������2��ʼ�ݹ�
        cout<<ans<<endl;
    }
    return 0;
}
void f(int a,int b) {//a��b�ֱ��ǵ�ǰ��n�Ľ�С�����ͽϴ�����(�������ۼƽ�b�ֳ���С�������ڵ���a�����з�����)
    for(int i=a;i<=b;i++) {//�ֽ�b��ʵ����i��󲻻�ﵽb���ڴ�Լ����bʱ�ͻ���������
		if((!(b%i))&&(b/i>=i)) {//����b���Ա�i����������iС�ڵ��ڸ���b
			ans++;//�Ƚ�b�ֽ�Ϊֻ��Ψһ����(������)�����
			f(i,b/i);//Ȼ�������۰�b�ֳ�i��b/i�����
		}
		if(b/i<i)//i���ڸ���b,�����ݹ�
         	return;
    }
    return;//���ᱻִ�е�������ڶ���ע�ͣ����ǻ�ʹǿ��֢���
}
