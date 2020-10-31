#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define int long long
#define pb push_back
#define F first
#define S second

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e11;
const int mod = 1e9 + 7;

struct vect {
    size_t sz, cap;
    int *v;


    vect() {
        sz = 0;
        cap = 1;
        v = new int[cap];
    }

    vect(size_t len) {
        assert(len > 0);
        sz = 0;
        cap = len;
        v = new int[cap];
    }

    void rsz() {
        int *V = new int[2*cap];
        for (unsigned int i = 0; i < sz; i++) {
            V[i] = v[i];
        }
        delete[] v;
        v = V;
        cap = 2*cap;
    }

    void pb(int x) {
        if (sz == cap) {
            rsz();
        }

        *(v + sz) = x;
        ++sz;
    }

    int get(int i) {
        assert(i < sz);
        return v[i];
    }
};

struct stck {
    size_t sz, cap;
    int *v;


    stck() {
        sz = 0;
        cap = 1;
        v = new int[cap];
    }

    stck(size_t len) {
        assert(len > 0);
        sz = 0;
        cap = len;
        v = new int[cap];
    }

    void rsz() {
        int *V = new int[2*cap];
        for (unsigned int i = 0; i < sz; i++) {
            V[i] = v[i];
        }
        delete[] v;
        v = V;
        cap = 2*cap;
    }

    void pb(int x) {
        if (sz == cap) {
            rsz();
        }

        *(v + sz) = x;
        ++sz;
    }

    int get(int i) {
        assert(i < sz && i >= 0);
        return v[i];
    }

    void pop() {
        if (sz == 0) return;
        --sz;
    }

    int last() {
        return get(sz - 1);
    }
};


struct lst {
    lst* next = nullptr;
    lst* prev = nullptr;
    int data;
};


signed main() {
    fast;
    int m;
    cin >> m;
    lst *node = new lst();

    node->next = new lst();
    node = node->next;

    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            if (node == nullptr) {
                node = new lst();
                node->data = x;
            } else {
                node->next = new lst();;
                node->next->data = x;
                node->next->prev = node;
                node = node->next;
            }
        } else {
            cout << node->data << endl;
            node = node->prev;
            delete node->next;
        }
    }

    return 0;
}
