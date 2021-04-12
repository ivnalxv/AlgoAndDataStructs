#include <bits/stdc++.h>
#define file freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

int n, m, k;

vector<vector<pair<int, int>>> cmp(16, vector<pair<int, int>> (16));
vector<int> cnt(16);

int bit(int x, int pos) {
    return ((x >> pos)&1);
}

void out(int a) {
    for (int i = n - 1; i >= 0; i--) {
        cout << ((a >> i) & 1);
    }
}


signed main() {
    fast;
    cin >> n;

    for (int i = 1; i <= 4; i++) {
        int mx = k;
        for (int j = 0; j < 16; j += (1 << i)) {
            int layer = k;
            int flag = 0;

            for (int pos = j; pos < j + (1 << (i - 1)); pos++) {
                int up = pos, dn = j + (1 << i) - pos + j - 1;

                if (up < n && dn < n) {
                    cmp[layer][cnt[layer]].F = up;
                    cmp[layer][cnt[layer]++].S = dn;
                    flag = 1;
                    m += flag;
                }
            }

            layer += flag;

            for (int s = i - 1; s > 0; s--) {
                flag = 0;

                for (int cur = j; cur < j + (1 << i); cur += (1 << s)) {
                    for (int pos = cur; pos < cur + (1 << (s - 1)); pos++) {
                        int up = pos, dn = pos + (1 << (s - 1));

                        if (up < n && dn < n) {
                            cmp[layer][cnt[layer]].F = up;
                            cmp[layer][cnt[layer]++].S = dn;
                            flag = 1;
                            m += flag;
                        }
                    }
                }

                layer += flag;
            }

            mx = max(layer, mx);
        }
        k = mx;
    }

    cout << n << " " << m << " " << k << endl;

    for (int i = 0; i < k; i++) {
        cout << cnt[i];
        for (int j = 0; j < cnt[i]; j++) {
            cout << " " << cmp[i][j].F + 1 << " " << cmp[i][j].S + 1;
        }
        cout << endl;
    }

    return 0;
}
