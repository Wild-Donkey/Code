#include <bits/stdc++.h>
using namespace std;

const int OutputBufferSize = 10000000;
namespace input {
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    bool IOerror = 0; 
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE; 
        if (p1 == pend) { 
            p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin); 
            if (pend == p1) { IOerror = 1; return -1; } 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    } 
    inline void read(char &ch) { 
        ch = nc();
        while (blank(ch)) ch = nc();
    }
    inline void read(int &x) {
        char ch = nc(); x = 0; 
        for (; blank(ch); ch = nc()); 
        if (IOerror) return; 
        for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
    } 
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
}; 

namespace output {
    char buffer[OutputBufferSize];
    char *s = buffer;
    inline void flush() {
        assert(stdout != NULL);
        fwrite(buffer, 1, s - buffer, stdout);
        s = buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if (s - buffer > OutputBufferSize - 2) flush();
        *s++ = ch;
    }
    inline void print(char* str) {
        while (*str != 0) print(char(*str++));
    }
    inline void print(int x) {
        char buf[25] = {0}, *p = buf;
        if (x == 0) print('0');
        while (x) *(++p) = x % 10, x /= 10;
        while (p != buf) print(char(*(p--) + '0'));
    }
}

const int maxn = 2005;
const int inf = 0x3f3f3f3f;
char s[maxn][maxn];
int n, m, a[maxn][maxn];
bool vis[maxn][maxn];
struct node {
    int x, y, z;
};
queue <node> q;

bool Update(int x, int y, int z) {
    if (a[x][y] >= z) a[x][y] = z;
    else return false;
    if (!vis[x][y]) {
        q.push({x, y, z});
        vis[x][y] = 1;
    }
    return true;
}
void Search(int x, int y, int z) {
    for (int i = y + 1; i <= m; i++) if (!Update(x, i, z)) break;
    for (int i = y - 1; i >= 1; i--) if (!Update(x, i, z)) break;
    for (int i = x + 1; i <= n; i++) if (!Update(i, y, z)) break;
    for (int i = x - 1; i >= 1; i--) if (!Update(i, y, z)) break;
}
void Solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '+') {
                a[i][j] = 0;
                q.push({i, j, 0});
            }
            if (s[i][j] == '#') a[i][j] = -1;
            if (s[i][j] == '.') a[i][j] = inf;
        }
    }
    while (q.size()) {
        node now = q.front(); q.pop();
        int x = now.x, y = now.y, z = now.z;
        Search(x, y, z + 1);
    }
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.ans", "w", stdout);
    input::read(n), input::read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            input::read(s[i][j]);
        }
    }

    Solve();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == -1) {
                output::print('#');
            } else if (a[i][j] == inf) {
                output::print('X');
            } else {
                output::print(a[i][j]);
            }
            output::print(" \n"[j == m]);
        }
    }
    output::flush();
    return 0;
}

