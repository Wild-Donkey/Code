#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int rd(){
	int res = 0, fl = 1; char c = getchar();
    while(!isdigit(c)){if(c == '-') fl = -1; c = getchar();}
    while(isdigit(c)){res = (res << 3) + (res << 1) + c - '0'; c = getchar();}
    return res * fl;
}
const int maxn = 1000010;
unsigned n;
int main(){
  freopen("B.in", "w", stdout);
	srand(time(0));
	n = rand() % 10 + 1;
	printf("1\n%u\n", n);
	for (unsigned i(1); i <= n; ++i) printf("%u ", rand() % 3 + 1);
	putchar(0x0A);
	return 0;
}

