#include<bits/stdc++.h>
#define ri rsgister int
using namespace std;
typedef long long ll;
int rd() {
	int res = 0, fl = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') fl = -1; c = getchar(); }
	while (isdigit(c)) { res = (res << 3) + (res << 1) + c - '0'; c = getchar(); }
	return res * fl;
}
const int maxn = 500010;
int Rot, n, m, k, l, r, v, tot, ls[maxn], rs[maxn], tag[maxn], rnd[maxn], val[maxn], sze[maxn], mav[maxn];
char rev[maxn];
void Print(int Rt) {
	printf("Node %u sze=%d val=%d rnd=%u tag=%d rev=%d mav=%d sze[ls]=%d sze[rs]=%d\n", Rt, sze[Rt], val[Rt], rnd[Rt], tag[Rt], rev[Rt], mav[Rt], sze[ls[Rt]], sze[rs[Rt]]);
}
void MainTain(int Rt) {
	sze[Rt] = 1 + sze[ls[Rt]] + sze[rs[Rt]], mav[Rt] = val[Rt];
	if (ls[Rt]) mav[Rt] = max(mav[Rt], mav[ls[Rt]]);
	if (rs[Rt]) mav[Rt] = max(mav[Rt], mav[rs[Rt]]);
}
void MakeTag(int Rt, int x) { tag[Rt] += x, mav[Rt] += x, val[Rt] += x; }
void PushDown(int Rt) {
	if (tag[Rt]) {
		MakeTag(ls[Rt], tag[Rt]); MakeTag(rs[Rt], tag[Rt]);
		MainTain(Rt);
		tag[Rt] = 0;
	}
	if (rev[Rt]) {
		rev[Rt] ^= 1;
		swap(ls[Rt], rs[Rt]);
		rev[ls[Rt]] ^= 1; rev[rs[Rt]] ^= 1;
	}
}
void Split(int Rt, int& L, int& R, int x) {
	// printf("Split %u by %u\n", Rt, x);
	// Print(Rt);
	if (!Rt) { L = R = 0; return; }
	PushDown(Rt);
	int Another(0);
	if (sze[ls[Rt]] + 1 < x) {
		L = Rt;
		Split(rs[L], Another, R, x - sze[ls[Rt]] - 1);
		rs[L] = Another;
		MainTain(L);
		return;
	}
	R = Rt;
	Split(ls[R], L, Another, x);
	ls[R] = Another;
	MainTain(R);
	return;
}
int Merge(int L, int R) {
	// printf("Merge\n");
	// Print(L), Print(R);
	if ((!L) || (!R)) return L + R;
	if (rnd[L] > rnd[R]) {
		// printf("Yes %u\n", L);
		PushDown(L);
		rs[L] = Merge(rs[L], R);
		MainTain(L);
		// printf("YeShit %u\n", L);
		return L;
	}
	PushDown(R);
	ls[R] = Merge(L, ls[R]);
	MainTain(R);
	return R;
}
void Insert() {
	rnd[++tot] = rand() * rand();
	sze[tot] = 1;
	Rot = Merge(Rot, tot);
}
int main() {
	// freopen("queue2.in", "r", stdin);
	// freopen("queue2.out", "w", stdout);
	srand(20041205);
	int L, R, TmpL, TmpR;
	n = rd(); m = rd();
	for (int i = 1; i <= n; ++i) Insert();
	//	Print(Rot); 

	while (m--) {
		k = rd(); l = rd(); r = rd();
		if (k == 1) {
			v = rd();
			L = 0, R = 0, TmpL = 0, TmpR = 0;
			Split(Rot, L, R, r + 1);
			Split(L, TmpL, TmpR, l);
			MakeTag(TmpR, v);
			L = Merge(TmpL, TmpR);
			Rot = Merge(L, R);

			continue;
		}
		if (k == 2) {
			L = 0, R = 0, TmpL = 0, TmpR = 0;
			Split(Rot, L, R, r + 1);
			Split(L, TmpL, TmpR, l);
			rev[TmpR] ^= 1;
			L = Merge(TmpL, TmpR);
			Rot = Merge(L, R);

			continue;
		}
		Split(Rot, L, R, r + 1);
		Split(L, TmpL, TmpR, l);
		printf("%d\n", mav[TmpR]);
		L = Merge(TmpL, TmpR);
		Rot = Merge(L, R);

	}
	system("pause");
	return 0;
}
