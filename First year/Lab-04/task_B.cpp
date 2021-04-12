#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second

using namespace std;

typedef long long ll;

signed main() {
    fast;
    int n;
    cin >> n;

    vector<int> a(n), d(n + 10), pos(n + 10), prev(n + 10);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i + 1] = INT_MAX;
    }

    int ans = 1;
    d[0] = INT_MIN;
    pos[0] = -1;

    for (int i = 0; i < n; i++) {
        int L = 0, R = n;
        while (R - L > 1) {
            int M = (L + R)/2;
            if (a[i] < d[M]) {
                R = M;
            } else {
                L = M;
            }
        }

        if (d[L] < a[i]) {
            d[R] = a[i];
            pos[R] = i;
            prev[i] = pos[L];
            ans = max(ans, R);
        }
    }

    cout << ans << endl;

    vector<int> original;
    int p = pos[ans];
    while (p != -1) {
        original.push_back(a[p]);
        p = prev[p];
    }

    for (int i = ans - 1; i >= 0; i--) {
        cout << original[i] << " ";
    }

    return 0;
}
