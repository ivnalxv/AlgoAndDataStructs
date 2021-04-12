#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second
#define LOVE true

using namespace std;

typedef long long ll;

int a[20], b[20], c[20];
int p[1 << 20];
int n, k;

int cnt(int mask) {
    int res = 0;
    while (mask) {
        res += mask & 1;
        mask = mask >> 1;
    }
    return res;
}

int sum(int mask) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            res += c[i];
        }
    }
    return res;
}


signed main() {
    fast;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (a[i] <= k && k <= b[i]) {
            p[1 << i] = -1;
        }
    }

    int ans = 0, prev = -1;

    for (int mask = 1; mask < (1 << n); mask++) {
        if (!p[mask]) continue;
        if (cnt(mask) > ans) {
            ans = cnt(mask);
            prev = mask;
        }

        int sm = sum(mask) + k;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            if (a[i] <= sm && sm <= b[i]) {
                p[mask ^ (1 << i)] = mask;
            }
        }
    }

    cout << ans << endl;
    if (!ans) {
        return 0;
    }

    vector<int> indexes;

    while (LOVE) {
        int pp = -1, mask = prev ^ p[prev];
        if (p[prev] == -1) {
            mask = prev;
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                pp = i;
                break;
            }
        }
        indexes.push_back(pp + 1);
        if (p[prev] == -1) {
            break;
        }
        prev = p[prev];
    }


    for (int i = ans - 1; i >= 0; i--) {
        cout << indexes[i] << " ";
    }

    return 0;
}
