#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;



signed main() {
    fast;
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }

    for (int i = 2; i < n; i++) {
        int x = a[i / 2];
        a[i / 2] = a[i];
        a[i] = x;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }


    return 0;
}
