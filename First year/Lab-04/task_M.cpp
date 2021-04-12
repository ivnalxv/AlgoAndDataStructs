#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second
#define LOVE true

using namespace std;

typedef long long ll;

const ll INF = (ll) 8e9;

vector<pair<int, ll>> g[20];
ll dp[20][1 << 18];

signed main() {
    fast;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        g[x - 1].push_back({y - 1, w});
        g[y - 1].push_back({x - 1, w});
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[i][mask] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 0LL;
    }

    ll res = INF;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int v = 0; v < n; v++) {
            for (auto u : g[v]) {
                if (!(mask & (1 << u.F))) {
                    dp[u.F][mask ^ (1 << u.F)] = min(dp[u.F][mask ^ (1 << u.F)], dp[v][mask] + u.S);
                }
            }
            if (mask + 1 == (1 << n)) {
                res = min(res, dp[v][mask]);
            }
        }
    }

    cout << (res == INF ? -1 : res) << endl;
    return 0;
}
