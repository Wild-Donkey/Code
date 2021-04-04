#include<cmath>
#include<ctime>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){

	freopen("gluten3.in","w",stdout);
	cout << 10000 << " " << 41205 << endl;
	for(int i = 1; i <= 10000; i++){
		cout << rand() % 49 + 1 << " " << 1 << endl;
//		cout << (rand() % 99 + 1) << " " << (rand() % 499 + 1) << endl;
	}
	return 0;
}


