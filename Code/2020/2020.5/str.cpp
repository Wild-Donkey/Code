#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string a,b;
int la,lb,ans=0x3fffffff,t=0,at;
int main() {
	cin>>a>>b;
	la=a.length();
	lb=b.length();
	for(int i=0; i<la; i++) { //枚举a的起点
		at=i;
		for(int j=0; j<lb; j++) {//枚举比较的点 
			if(at>=la) {
				t++;
			} else {
				if(a[at]!=b[j]) {
					if(a[at+1]==b[j+1]) { //修改
						t++;
					} else {
						if(a[at+1]==b[j]) { //删除
							at++;
							t++;
						} else {
							if(a[at]==b[j+1]) { //添加
								j++;
								t++;
							}
						}
					}
				}
			}
			at++;
		}
		ans=min(t,ans);
		t=0;
	}
	cout<<ans<<endl;
	return 0;
}
