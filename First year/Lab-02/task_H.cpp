#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

unsigned int A, B;

unsigned int cur = 0;
unsigned int nextRand24() {
    cur = A*cur + B;
    return (cur >> 8);
}

vector<unsigned int> a;
long long inv;

void merge(int L1, int R1, int L2, int R2) {
    int i = L1, j = L2, k = 0;
    long long cnt = 0;
    vector<unsigned int> b = vector<unsigned int> (R2 - L1 + 1);


    while (i < R1 && j < R2) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            ++i;

        } else {
            b[k] = a[j];
            ++j;
            cnt += R1 - i;
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

    inv += cnt;
    return;
}

void merge_sort(int L, int R) {
    if (L + 1 == R) return;

    int M = (L + R)/2;
    merge_sort(L, M);
    merge_sort(M, R);

    merge(L, M, M, R);
}


signed main() {
    fast;
    int n, m;
    cin >> n >> m >> A >> B;
    a = vector<unsigned int> (n);
    for (int i = 0; i < n; ++i) {
        a[i] = nextRand24()%m;
    }


    merge_sort(0, n);

    cout << inv << endl;


    return 0;
}
