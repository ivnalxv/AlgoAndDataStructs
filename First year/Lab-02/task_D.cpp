#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back

using namespace std;

const double eps = 1e-6;

signed main() {
    fast;
    int n;
    double A, ans;
    cin >> n >> A;

    double F[3];
    F[0] = A;

    double L = 0, R = A;
    ans = A;

    while (R - L > eps) {
        F[0] = A;
        F[1] = (L + R)/2;
        int good = 1;

        for (int i = 2; i < n; ++i) {
            double temp = 2*F[1] - F[0] + 2.;
            if (temp <= 0) {
                good = 0;
                break;
            }
            F[0] = F[1];
            F[1] = temp;
            if (i + 1 == n) ans = F[1];
        }
        if (good) {
            R = (L + R)/2;
        } else {
            L = (L + R)/2;
        }
    }

    cout << fixed << setprecision(2) << ans << endl;


    return 0;
}
