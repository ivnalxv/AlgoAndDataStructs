#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define int long long
#define F first
#define S second

using namespace std;

const int mod = (int) 1e18;

int n = 1e18, m, x, ans;
int subtraction = 0;

int stab_element(int elem, int stab) {
    while (elem < 1) {
        elem += stab;
    }
    while (elem > stab) {
        elem -= stab;
    }
    return elem;
}

int kth_element(int k) {
    int elem;
    cout << "? " << k << endl;
    cin >> elem;
    elem -= subtraction;
    return (elem < 1 ? elem + mod : elem);
}

signed main() {
    fast;
    cin >> x >> m;

    n -= m;
    subtraction = kth_element(1) - 1;
    x -= subtraction;
    x = stab_element(x, mod);

    int L = max(0LL, x - n), R = min(m, x - 1);

    while (L < R) {
        int M = L + (R - L) / 2LL;
        ans = kth_element(x - M);

        if (ans < x) {
            R = M - 1;
        } else if (ans > x) {
            L = M + 1;
        } else {
            cout << "! " << stab_element(x - M, n) << endl;
            return 0;
        }
    }

    if (kth_element(x - L) == x) {
        cout << "! " << stab_element(x - L, n) << endl;
    } else {
        cout << "! " << -1 << endl;
    }

    return 0;
}
