# include <iostream>
# include <cstring>
# include <cstdio>
using namespace std;
int ans, tomo, toda;
struct Date {
	int year, mot, day;
	bool can; 
	Date (string st) {
		year = 1000 * (st[0] - '0') + 100 * (st[1] - '0') + 10 * (st[2] - '0') + st[3] - '0';
		mot = 10 * (st[4] - '0') + st[5] - '0';
		day = 10 * (st[6] - '0') + st[7] - '0';
		can = 0;
	}
};
string st;
int main () {
	cin >> st;
	Date s(st);
	cin >> st;
	Date t(st);
	for (int i(s.year); i <= t.year; ++i) {
		tomo = ((i % 10) * 10) + ((i % 100) / 10);
		toda = (i / 1000) + (((i % 1000) / 100) * 10);
		if (tomo > 12 || tomo <= 0) {
			continue;
		}
		if (toda <= 0) {
			continue;
		}
		if (tomo == 2) {//二月 
			if (i % 4) {//不闰 
				if (toda > 28) {
					continue;
				}
			}
			else {//i % 4 == 0
				if (i % 100) {
					if (toda > 29) {
						continue;
					} 
				}
				else {//i % 100 = 0
					if (i % 400) {//不闰 
						if (toda > 28) {
							continue;
						}
					}
					else {//i % 400 = 0
						if (toda > 29) {
							continue;
						}
					}
				}
			}
			ans++;
			if (i == s.year) {
				s.can = 1;
			}
			if (i == t.year) {
				t.can = 1;
			}
			continue;
		}
		if (tomo <= 7) {//1, 3, 4, 5, 6, 7
			if (tomo % 2) {//1, 3, 5, 7
				if (toda <= 31) {
					ans++;
					if (i == s.year) {
						s.can = 1;
					}
					if (i == t.year) {
						t.can = 1;
					}
				}
				continue;
			}
			else {//4, 6
				if (toda <= 30) {
					ans++; 
					if (i == s.year) {
						s.can = 1;
					}
					if (i == t.year) {
						t.can = 1;
					}
				}
				continue;
			}
		}
		else {//8, 9, 10, 11, 12
			if (tomo % 2) {//9, 11
				if (toda <= 30) {
					ans++; 
					if (i == s.year) {
						s.can = 1;
					}
					if (i == t.year) {
						t.can = 1;
					}
				}
				continue;
			}
			else {//8, 10, 12
				if (toda <= 31) {
					ans++; 
					if (i == s.year) {
						s.can = 1;
					}
					if (i == t.year) {
						t.can = 1;
					}
				}
				continue;
			}
		}
	}
	if(s.can){
		tomo = ((s.year % 10) * 10) + ((s.year % 100) / 10);
		toda = (s.year / 1000) + (((s.year % 1000) / 100) * 10);
		if (tomo < s.mot) {
			ans--;
		}
		else {//起始之后
			if (tomo == s.mot) {
				if (toda < s.day) {
					ans--;
				}
			}
		}
	}
	if(t.can){
		tomo = ((t.year % 10) * 10) + ((t.year % 100) / 10);
		toda = (t.year / 1000) + (((t.year % 1000) / 100) * 10);
		if (tomo > t.mot) {//结束之前 
			ans--;
		}
		else {
			if (tomo == t.mot) {
				if (toda > t.day) {
					ans--;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
