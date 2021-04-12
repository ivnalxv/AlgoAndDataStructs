#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second
#define LOVE true

using namespace std;

typedef long long ll;

const ll mod = (1LL << 30LL) + 1;

int n, m;
ll dp[302][1 << 18];

int bit(int a, int k) {
    return (a >> k) & 1;
}

int check(int a, int b) {
    for (int i = 0; i < n - 1; i++) {
        if (bit(a, i) == bit(a, i + 1) && bit(b, i) == bit(b, i + 1)) {
            if (bit(a, i) == bit(b, i)) {
                return 0;
            }
        }
    }
    return 1;
}


signed main() {
    fast;
    cin >> n >> m;

    if (n > m) {
        swap(n, m);
    }

    for (int i = 0; i < (1 << n); i++) {
        dp[0][i] = 1LL;
    }

    for (int i = 1; i <= m; i++) {
        for (int mask1 = 0; mask1 < (1 << n); mask1++) {
            for (int mask2 = 0; mask2 < (1 << n); mask2++) {
                if (check(mask2, mask1)) {
                    dp[i][mask1] = (dp[i - 1][mask2] + dp[i][mask1]) % mod;
                }
            }
        }
    }

    ll res = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        res = (res + dp[m - 1][mask]) % mod;
    }

    cout << (res + mod) % mod << endl;

    return 0;
}
