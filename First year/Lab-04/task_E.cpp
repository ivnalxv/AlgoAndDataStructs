#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) x.size()
#define F first
#define S second

using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

int dp[5000 + 7][5000 + 7];
int n, m;



signed main() {
    fast;
    string s1, s2;
    cin >> s1 >> s2;

    n = sz(s1);
    m = sz(s2);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }

    for (int i = 1; i <= m; i++) {
        dp[0][i] = dp[0][i - 1] + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min({
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1])
            });
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
