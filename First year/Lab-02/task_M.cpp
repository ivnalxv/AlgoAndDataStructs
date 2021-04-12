#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

int n, m, k;

vector<pair<int, int>> layer[150 + 7];

int bit(int x, int pos) {
    return ((x >> pos)&1);
}

void out(int a) {
    for (int i = n - 1; i >= 0; i--) {
        cout << ((a >> i) & 1);
    }
}


void swap(int &a, int pos1, int pos2) {
    if (bit(a, pos1) != bit(a, pos2)) {
        a = ((1 << pos1) ^ (1 << pos2) ^ a);
    }
}

int check(int a) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (int) layer[i].size(); j++) {
            if (bit(a, layer[i][j].first) > bit(a, layer[i][j].second)) {
                swap(a, layer[i][j].first, layer[i][j].second);
            }
        }
    }


    for (int i = 0; i < n - 1; i++) {
        if (bit(a, i) > bit(a, i + 1)) return 0;
    }

    return 1;
}


signed main() {
    fast;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < t; ++j) {
            pair<int, int> p = {1, 1};
            cin >> p.first >> p.second;
            --p.first;
            --p.second;

            if (p.first > p.second) {
                swap(p.first, p.second);
            }
            layer[i].push_back(p);
        }
    }

    for (int i = 0; i < (1 << n); ++i) {
        if (!check(i)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
