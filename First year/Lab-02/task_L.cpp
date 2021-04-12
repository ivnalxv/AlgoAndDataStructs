#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;


const double eps = 1e-7;

int n, k;
double d;

vector< pair<pair<int, int>, int> > a;

int comp(int i, int j, int flag) {
    if (flag) return a[i].S <= a[j].S;
    double var_i = a[i].F.F*1.0 - d * a[i].F.S;
    double var_j = a[j].F.F*1.0 - d * a[j].F.S;
    return var_i <= var_j;
}



void merge(int L1, int R1, int L2, int R2, int flag) {
    int i = L1, j = L2, k = 0;
    vector< pair<pair<int, int>, int> > b(R2 - L1 + 1);
    while (i < R1 && j < R2) {
        if (comp(i, j, flag)) {
            b[k] = a[i];
            ++i;
        } else {
            b[k] = a[j];
            ++j;
        }
        ++k;
    }
    while (i < R1) {
        b[k] = a[i];
        ++i;
        ++k;
    }
    while (j < R2) {
        b[k] = a[j];
        ++j;
        ++k;
    }
    for (k = L1; k < R2; ++k) {
        a[k] = b[k - L1];
    }
    return;
}

void merge_sort(int L, int R, int flag) {
    if (L + 1 == R) return;

    int M = (L + R)/2;
    merge_sort(L, M, flag);
    merge_sort(M, R, flag);

    merge(L, M, M, R, flag);
}

int check() {
    merge_sort(0, n, 0);
    double sum = 0;

    for (int i = 0; i < k; i++) {
        sum += (double) a[n - i - 1].F.F - d * a[n - i - 1].F.S;
    }
    return (sum >= 0);
}


signed main() {
    fast;
    cin >> n >> k;

    a = vector< pair<pair<int, int>, int> > (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F.F >> a[i].F.S;
        a[i].S = i;
    }

    double L = 0, R = 1e7;
    while (R - L > eps) {
        d = L + (R - L) / 2;
        if (check()) {
            L = d;
        } else {
            R = d;
        }
    }
    d = L;
    if (!check()) {
        d = R;
        check();
    }

    merge_sort(n - k, n, 1);

    for (int i = n - k; i < n; ++i) {
        cout << a[i].S + 1 << " ";
    }


    return 0;
}
