#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

vector< int > a;
int n, k, A, B, C, a0, a1;

int partition(int L, int R) {
    int i = L, j = R;
    while (true) {
        while (a[i] < a[R]) {
            i++;
        }
        while (a[j] > a[R]) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(a[i], a[j]);
        i++;
        j--;
    }

    swap(a[i], a[R]);
    return i;
}

int kth_element(int k) {
    int L = 0, R = n - 1;
    int M = k - 1;

    while (true) {
        int part = partition(L, R);

        if (M == part) {
            return (a[part]);
        }
        if (M < part) {
            R = part - 1;
        } else {
            L = part + 1;
        }
    }
}


signed main() {
    fast;
    cin >> n >> k >> A >> B >> C >> a0 >> a1;
    a = vector<int> (n);

    a[0] = a0;
    a[1] = a1;

    for (int i = 2; i < n; i++) {
        a[i] = (A * a[i - 2] + B * a[i - 1] + C);
    }

    cout << kth_element(k) << endl;

    return 0;
}
