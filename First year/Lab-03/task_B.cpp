#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

const int SIZE = 300000 + 7;

pair<int, int> DATA[SIZE];
int sz[SIZE];
int r[SIZE];
int p[SIZE];


void make(int v) {
	p[v] = v;
	r[v] = 0;
	sz[v] = 1;
	DATA[v] = {v, v};
}

int find(int v) {
	if (v == p[v]) {
        return v;
	}
	return p[v] = find(p[v]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;

    if (r[a] < r[b]) {
        swap(a, b);
    }

    p[b] = a;
    sz[a] += sz[b];
    DATA[a] = {min(DATA[a].F, DATA[b].F), max(DATA[a].S, DATA[b].S)};

    if (r[a] == r[b]) {
        ++r[a];
    }
}


signed main() {
    fast;
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        make(i);
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "union") {
            int x, y;
            cin >> x >> y;
            unite(x, y);
        } else {
            int x;
            cin >> x;
            x = find(x);
            cout << DATA[x].F << " " << DATA[x].S << " " << sz[x] << endl;
        }
    }

    return 0;
}
