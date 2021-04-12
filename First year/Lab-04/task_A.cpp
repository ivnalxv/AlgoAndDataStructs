#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second

using namespace std;

typedef long long ll;

const ll INF = LLONG_MAX;

vector<vector<ll>> dp(500 + 7, vector<ll> (500 + 7, -1));
vector<vector<int>> mid(500 + 7, vector<int> (500 + 7));
vector<pair<ll, ll>> a(500 + 7);


ll precalc(int l, int r) {
    if (r == l + 1) {
        dp[l][r] = 0LL;
    }
    if (dp[l][r] != -1LL) {
        return dp[l][r];
    }

    dp[l][r] = INF;

    for (int i = l + 1; i < r; i++) {
        ll temp = precalc(l, i) + precalc(i, r) + a[l].F * a[i].F * a[r - 1].S;
        if (dp[l][r] > temp) {
            dp[l][r] = temp;
            mid[l][r] = i;
        }
    }
    return dp[l][r];
}

string calc(int l, int r) {
    if (r != l + 1) {
        return "(" + calc(l, mid[l][r]) + calc(mid[l][r], r) + ")";
    }
    return "A";
}


signed main() {
    fast;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].F >> a[i].S;
    }

    precalc(0, n);

    cout << calc(0, n) << endl;

    return 0;
}
