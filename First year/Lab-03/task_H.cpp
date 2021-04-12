#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

const int SIZE = 300000 + 7;


int p[SIZE];
int r[SIZE];
int c[SIZE];

int n, m, shift;

void make(int v) {
	p[v] = v;
	r[v] = 0;
	c[v] = 0;
}

int find(int v) {
	if (v == p[v]) {
        return v;
	}
	return find(p[v]);
}

int color(int v) {
    if (p[v] == v) {
        return c[v];
    }
    return (c[v] ^ color(p[v]));
}

int relax(int a) {
    return ((a + shift) % n - 1 + n) % n + 1;
}

void unite(int a, int b) {
	int flag = (color(a) == color(b));
	a = find(a);
	b = find(b);

	if (a != b) {
        if (r[a] < r[b]) {
            swap(a, b);
        }
        c[b] ^= (flag);
        r[a] += (r[a] == r[b]);
        p[b] = a;
	}
}


signed main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        make(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b, cmd;
        cin >> cmd >> a >> b;

        a = relax(a);
        b = relax(b);

        if (cmd == 0) {
            unite(a, b);
        } else {
            if (color(a) == color(b)) {
                cout << "YES" << endl;
                shift = (shift + 1) % n;
            } else {
                cout << "NO" << endl;
            }
        }
    }



    return 0;
}
