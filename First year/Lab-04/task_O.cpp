#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
#define all(x) (x).begin(), (x).mid()
#define F first
#define S second
#define LOVE true

using namespace std;

typedef long long ll;

int x, a, y, b, l;

int dp[200][200];

int isPossible(int w) {
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            dp[i][j] = -1;
        }
    }

    dp[x][y] = 0;

    for (int i = x; i >= 0; i--) {
        for (int j = y; j >= 0; j--) {
            if (dp[i][j] == -1) continue;
            if (dp[i][j] >= l) return 1;

            int temp = dp[i][j] + 1;
            int cntA = 0, cntB = (w + b - 1) / b;

            while (cntA <= i && w + a > cntA * a) {
                if (cntB <= j) {
                    dp[i - cntA][j - cntB] = max(dp[i - cntA][j - cntB], temp);
                }
                cntA++;
                while (cntB && w + b <= cntA * a + cntB * b) {
                    cntB--;
                }
            }
        }
    }

    return 0;
}


signed main() {
    fast;
    cin >> x >> a >> y >> b >> l;

    if (a < b) {
        swap(a, b);
        swap(x, y);
    }

    int L = 0, R = (a*x + b*y)/l + 1;

    while (R - L > 1) {
        int M = (L + R)/2;
        if (isPossible(M)) {
            L = M;
        } else {
            R = M;
        }
    }

    cout << L << endl;

    return 0;
}
