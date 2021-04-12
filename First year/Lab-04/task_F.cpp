#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) x.size()
#define F first
#define S second

using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

int dp[10000 + 7][10000 + 7];
int n, m;

signed main() {
    fast;
    string s1, s2;
    getline(cin, s2);
    getline(cin, s1);

    n = sz(s1);
    m = sz(s2);

    if (m == 0 && n > 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (n == 0) {
        for (int i = 0; i < m; i++) {
            if (s2[i] != '*') {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= m && s2[i - 1] == '*'; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s2[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (s2[j - 1] == '*') {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1]);
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    cout << (dp[n][m] ? "YES" : "NO") << endl;

    return 0;
}
