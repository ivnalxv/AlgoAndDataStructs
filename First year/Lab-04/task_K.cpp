#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second
#define LOVE true

using namespace std;

typedef long long ll;

const ll mod = 1000000000LL;

ll dp[2000 + 10][2000 + 10];

signed main() {
    fast;
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = 1LL;
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = 2LL + (a[i] == a[i + 1]);
    }

    for (int len = 2; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            dp[l][l + len] = (dp[l][l + len - 1] + dp[l + 1][l + len]) % mod;
            if (a[l] == a[l + len]) {
                dp[l][l + len]++;
            } else {
                dp[l][l + len] -= dp[l + 1][l + len - 1];
            }
            dp[l][l + len] = (dp[l][l + len] + mod) % mod;
        }
    }

    cout << dp[0][n - 1] << endl;


    return 0;
}
