#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

vector<string> a;

void radix_sort(int n, int m, int k) {
    for (int i = 0; i < k; ++i) {
        int cnt[32 + 7], h[32 + 7];
        for (int j = 0; j <= 32; ++j) {
            cnt[j] = h[j] = 0;
        }

        for (int j = 0; j < n; ++j) {
            ++cnt[ (int) a[j][m - 1 - i] - 'a' ];
        }

        h[0] = 0;
        for (int j = 1; j <= 32; ++j) {
            h[j] = h[j - 1] + cnt[j - 1];
        }


        vector<string> b = vector<string> (n);


        for (int j = 0; j < n; ++j) {
            int digit =  (int) (a[j][m - 1 - i] - 'a');
            b[h[digit]] = a[j];
            ++h[digit];
        }

        a = b;
    }
}


signed main() {
    fast;
    int n, m, k;
    cin >> n >> m >> k;
    a = vector<string> (n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    radix_sort(n, m, k);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }


    return 0;
}
