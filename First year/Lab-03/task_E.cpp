#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

const int SIZE = 200000 + 7;

int p[SIZE][2];


void make(int v) {
	p[v][0] = v;
	p[v][1] = v;
}

int get(int v, int c) {
	if (v == p[v][c]) {
        return v;
	}
	return p[v][c] = get(p[v][c], c);
}

void unite(int a, int b, int c) {
	a = get(a, c);
	b = get(b, c);
	p[a][c] = b;
}


signed main() {
    fast;
    int n, q;
    cin >> n >> q;

    for (int i = 0; i <= n; ++i) {
        make(i);
    }

    for (int i = 0; i < q; i++) {
        int cmd, x, y;
        cin >> cmd >> x >> y;

        if (x > y) {
            swap(x, y);
        }

        if (cmd == 1) {
            unite(x - 1, y - 1, 0);
        } else if (cmd == 2) {
            for (int j = x - 1; j < y - 1; j++) {
                j = get(j, 1);
                if (j >= y - 1)
                    break;
                unite(j, j + 1, 0);
                unite(j, j + 1, 1);
            }
        } else {
            cout << (get(x - 1, 0) == get(y - 1, 0) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
