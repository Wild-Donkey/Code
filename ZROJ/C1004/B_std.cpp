#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
const int N = 1e5 + 5;
int n, T, a[N], b[N], l[N], c[N]; 

namespace io {
	const int SIZE = 1 << 22 | 1;
	char iBuf[SIZE], *iS, *iT, c;
	char oBuf[SIZE], *oS = oBuf, *oT = oBuf + SIZE;
	#define gc() (iS == iT ? iT = iBuf + fread(iS = iBuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++) : *iS++)
	template<class I> void read(I &x) {
		int f = 1;
		for(c = gc(); c < '0' || c > '9'; c = gc())
			if(c == '-') f = -1;
		for(x = 0; c >= '0' && c <= '9'; c = gc())
			x = (x << 3) + (x << 1) + (c & 15);
		x *= f;
	}
	inline void flush () {
		fwrite(oBuf, 1, oS - oBuf, stdout);
		oS = oBuf;
	}
	inline void putc(char x) {
		*oS++ = x;
		if(oS == oT) flush();
	}
	template<class I> void print(I x) {
		if(x < 0) putc('-'), x = -x;
		static char qu[55];
		char *tmp = qu;
		do *tmp++ = (x % 10) ^ '0'; while(x /= 10);
		while(tmp-- != qu) putc(*tmp);
		putc('\n');
	}
	struct flusher{ ~flusher() { flush(); } }_;
}

inline int Gcd (int a, int b) {
	return !b ? a : Gcd(b, a % b);
}
bool solve (int L, int R) {
	int d = 0, equal = 1;
	rep(i, L + 1, R) if(a[i] != a[i - 1]) equal = 0;
	if(equal) return true;  
	rep(i, L, R) {
		if(b[a[i]]) {
			if(l[a[i]] && i - b[a[i]] != l[a[i]]) return false; 
			l[a[i]] = i - b[a[i]]; 
		}
		b[a[i]] = i; 
	}
	rep(i, L, R) d = Gcd(d, l[a[i]]); 
	rep(i, L, R) b[a[i]] = l[a[i]] = 0;
	if(!d) return true;
	if(d == 1) return false;  
	int cnt = 0; 
	rep(i, L, L + d - 1) for (int j = i; j <= R; j += d) c[++cnt] = a[j]; 
	rep(i, L, R) a[i] = c[i - L + 1]; 
	cnt = 0; 
	rep(i, L, L + d - 1) {
		int num = 0; for (int j = i; j <= R; j += d) ++num; 
		if(!solve(L + cnt, L + cnt + num - 1)) return false; 
		cnt += num; 
	}
	return true; 
}

int main () {
  freopen("B.in", "r", stdin);
  freopen("B.ans", "w", stdout);
	io :: read(T); 
	while (T--) {
		io :: read(n); 
		rep(i, 1, n) io :: read(a[i]); 
		puts(solve(1, n) ? "Yes" : "No"); 
		rep(i, 1, n) b[a[i]] = l[a[i]] = 0; 
	}
	return 0; 
}
