#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> cash;
int m, n, p;

bool timeChecker(ll time) {
    ll sum = 0, j = 0, t;
    vector<ll> arr(p + 1, 0LL);

	for (int i = 0; i < m; i++) {
        if (time < cash[i].F) continue;
		if (cash[i].S == 0LL) {
            arr[p]++;
        } else {
            t = (time - cash[i].F)/cash[i].S;
            if (t > p) t = p;
            arr[(int) t]++;
        }
	}

	for (int i = p; i > 0 && n > j; i--) {
		t = min(arr[i], n - j);
		sum += t * i;
		j += t;
	}
	return (sum >= p);
}


signed main() {
    fast;
    cin >> m;
    cash = vector<pair<ll, ll>> (m);

    ll a, b, t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        cash[i].F = b + t;
        cash[i].S = a;
    }

    cin >> n >> p;

    ll L = 0, R = 1e11;
    while (L < R) {
        ll M = L + (R - L) / 2LL;
        if (timeChecker(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }

    cout << L << endl;

    return 0;
}
