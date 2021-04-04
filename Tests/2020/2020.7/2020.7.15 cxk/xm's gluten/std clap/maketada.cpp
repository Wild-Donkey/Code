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

	freopen("gluten6.in","w",stdout);
	cout << 100000 << " " << 100000 << endl;
	for(int i = 1; i <= 100000; i++){
		cout << rand() % 1233 + 1 << " " << rand() % 566 + 1 << endl;
//		cout << (rand() % 99 + 1) << " " << (rand() % 499 + 1) << endl;
	}
	return 0;
}


