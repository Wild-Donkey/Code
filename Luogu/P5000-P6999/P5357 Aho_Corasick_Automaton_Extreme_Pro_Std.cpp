#include <iostream>
#include <cstdio>
#include <cstring>
#define R register

using namespace std;
const int MAXN = 2e6 + 6;

int n, slen, len[MAXN], sum[MAXN];
char S[MAXN], T[MAXN], str[MAXN];

struct SuffixArray{
	int n, m;
	int sa[MAXN], rk[MAXN], tx[MAXN], tp[MAXN];	
	
	void Init(int a, int b, char *s) {
		n = a;
		m = b;
		for (R int i = 1; i <= n; i++) {
			rk[i] = s[i];
			tp[i] = i;
		}
	}
	
	void RSort() {
		for (R int i = 0; i <= m; i++) tx[i] = 0;
		for (R int i = 1; i <= n; i++) tx[rk[i]]++;
		for (R int i = 1; i <= m; i++) tx[i] += tx[i - 1];
		for (R int i = n; i >= 1; i--) sa[tx[rk[tp[i]]]--] = tp[i];
	}
	
	void Build() {
		RSort();
		for (R int w = 1, p = 1; p < n; w <<= 1, m = p) {
			p = 0;
			for (int i = 1; i <= w; i++)
				tp[++p] = n - w + i;
			for (int i = 1; i <= n; i++)
				if (sa[i] > w)
					tp[++p] = sa[i] - w;
			RSort();
			swap(rk, tp);
			rk[sa[1]] = p = 1;
			for (int i = 2; i <= n; i++)
				rk[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w]) ? p : ++p;
		}
	}
}SA;

int Comp(int p) {//str > S
	for (int i = 1, j = p; str[i] && S[j]; i++, j++) {
		if (str[i] < S[j]) return 0;
		if (str[i] > S[j]) return 1;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	int p = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%s", T + p);
		len[i] = strlen(T + p);
		sum[i] = sum[i - 1] + len[i];
		p = sum[i] + 1;
	}
	scanf("%s", S + 1);
	slen = strlen(S + 1);
	memcpy(str + 1, S + 1, slen);
	for (int i = 1; i <= slen; i++) str[i] -= 'a' - 1;
	SA.Init(slen, 30, str);
	SA.Build();
	for (R int i = 1; i <= n; i++) {
		memcpy(str + 1, T + sum[i - 1] + 1, len[i]);
		str[len[i] + 1] = 127;
		str[len[i] + 2] = '\0';
		int ans1 = 0;
		for (R int j = 21; j >= 0; j--) {
			if (ans1 + (1 << j) > slen) continue;
			if (Comp(SA.sa[ans1 + (1 << j)]))
				ans1 += (1 << j);
		}
		str[len[i]]--;
		int ans2 = 0;
		for (R int j = 21; j >= 0; j--) {
			if (ans2 + (1 << j) > slen) continue;
			if (Comp(SA.sa[ans2 + (1 << j)]))
				ans2 += (1 << j);
		}
		printf("%d\n", ans1 - ans2);
	}
	return 0;
}
