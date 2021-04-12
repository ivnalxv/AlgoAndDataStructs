#include <bits/stdc++.h>
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

const int INF = 1e9 + 9;
const int MAXN = 1e6 + 7;

int p[MAXN];
int rang[MAXN];


void make(int v) {
    p[v] = v;
    rang[v] = 1;
}

int find(int v) {
    if (p[v] == v) return v;
    return p[v] = find(p[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (rang[a] < rang[b]) {
            swap(a, b);
        }
        p[b] = a;
        rang[a] += rang[b];
    }
}


signed main() {
    fast;
    int n, m, k;
    cin >> n >> m >> k;

    vector< pair<bool, pair<int, int>> > a;
    vector<string> ans;

    for (int i = 1; i <= n; i++) {
        make(i);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        string s;
        cin >> s >> x >> y;
        a.push_back({(s == "ask"), {x, y}});
    }

    for (int i = k - 1; i >= 0; i--) {
        if (a[i].F) {
            ans.push_back(find(a[i].S.F) == find(a[i].S.S) ? "YES" : "NO");
        } else {
            unite(a[i].S.F, a[i].S.S);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }

    return 0;
}
