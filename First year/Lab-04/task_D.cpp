#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) x.size()
#define F first
#define S second

using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

int dp[1000 + 7][10000 + 7];

signed main() {
    fast;
    int n, m;
    cin >> n >> m;

    vector<int> w(n + 7), c(n + 7);

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + w[i] <= m) {
                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + c[i]);
            }
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> sack;

    int first = 0;
    for (int i = m; i > 0; i--) {
        if (dp[n + 1][i] != dp[n + 1][i - 1]) {
            first = i;
            break;
        }
    }
    for (int i = n + 1; i > 1; i--) {
        if (dp[i - 1][first] != dp[i][first]) {
            sack.push_back(i - 1);
            first -= w[i - 1];
        }
    }

    cout << sack.size() << endl;
    reverse(all(sack));

    for (auto item : sack) {
        cout << item << " ";
    }

    return 0;
}
