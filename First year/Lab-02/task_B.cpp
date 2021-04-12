#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

vector<int> a;

pair<int, int> bins(int x, int n) {
    int L = 0, R = n;
    int res1 = -1, res2 = -1;

    while (L + 1 != R) {
        int M = (L + R)/2;
        if (x <= a[M - 1]) {
            R = M;
        } else {
            L = M;
        }
    }
    res1 = L + 1;
    L = 0;
    R = n;

    while (L + 1 != R) {
        int M = (L + R)/2;
        if (x < a[M]) {
            R = M;
        } else {
            L = M;
        }
    }
    res2 = L + 1;

    if (a[res1 - 1] != x || a[res2 - 1] != x) {
        return {-1, -1};
    }
    return {res1, res2};
}

signed main() {
    fast;
    int n, m;
    cin >> n;
    a = vector<int> (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;

    while (m--) {
        int x;
        cin >> x;
        auto p = bins(x, n);
        cout << p.F << " " << p.S << endl;
    }


    return 0;
}
