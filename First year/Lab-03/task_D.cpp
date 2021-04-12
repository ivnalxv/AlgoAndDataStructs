#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

const int SIZE = 300000 + 7;

int sz[SIZE];
int r[SIZE];
int p[SIZE];
int us[SIZE];


void make(int v) {
	p[v] = v;
	r[v] = v;
	sz[v] = 1;
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
	if (a != b) {
        p[a] = b;
        sz[b] += sz[a];
	}
}


signed main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        make(i);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;

        if (us[x]) {
            while (us[(r[find(x)] + 1) % n]) {
                unite(x, (r[find(x)] + 1) % n);
            }

            us[(r[find(x)] + 1) % n] = 1;
            cout << (r[find(x)] + 1) % n + 1 << " ";
            unite(x, (r[find(x)] + 1) % n);
        } else {
            us[x] = 1;
            cout << x + 1 << " ";
        }
    }



    return 0;
}
