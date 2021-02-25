#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n;
int main() {
	cin >> n;
	long long i = 1;
	while (i * i <= n) {
		printf("%lld ", i * i);
		i++;
	}
	return 0;
}