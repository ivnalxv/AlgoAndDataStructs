#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

void print(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
}

signed main() {
    fast;
    int n, m;
    cin >> n >> m;

    if (m > 3) {
        print(1, 3, 1);
        print(1, 3, 2);
        m -= 2;

        for (int i = 3; m > 0; i++) {
            print(1, i + 1, i);
            m--;
            for (int j = 2 - (i & 1); j + 1 < i && m; j += 2, m--) {
                print(0, j, j + 1);
            }
        }
    } else if (m == 2) {
        print(0, 1, 2);
        print(1, 1, 2);
    } else {
        print(0, 1, 2);
    }


    return 0;
}
