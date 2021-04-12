#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second
#define LOVE true

using namespace std;

typedef long long ll;

vector<pair<int, ll>> g[100000 + 7];
ll dp[100000 + 7][2];

void dfs(int v, int p = -1) {
    for (auto u : g[v]) {
        if (u.F != p && g[u.F].size() > 1) {
            dfs(u.F, v);
        }
    }

    ll mx = LLONG_MIN;
    for (auto u : g[v]) {
        if (u.F != p) {
            ll temp = max(dp[u.F][0], dp[u.F][1]);
            dp[v][0] += temp;
            mx = max(mx, u.S + dp[u.F][0] - temp);
        }
    }
    dp[v][1] = dp[v][0] + mx;
}

signed main() {
    fast;
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        g[x - 1].push_back({y - 1, w});
        g[y - 1].push_back({x - 1, w});
    }

    dfs(0);

    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}
