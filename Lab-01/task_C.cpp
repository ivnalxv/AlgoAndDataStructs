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


struct myQueue {
    int head, tail, capacity, size;
    int *Array;

    myQueue() {
        Array = new int[1];
        head = 0;
        tail = 0;
        capacity = 1;
        size = 0;
    }

    void push(int x) {
        if (size == capacity) {
            resizeUp();
        }
        ++size;
        Array[tail] = x;
        tail = (tail + 1) % capacity;
    }

    int pop() {
        --size;
        int x = Array[head];
        head = (head + 1) % capacity;
        if (size == capacity/4 && capacity/4 > 0) {
            resizeDown();
        }
        return x;
    }

    void resizeUp() {
        int *Brray = new int[capacity*2];
        for (int i = 0; i < size; ++i) {
            Brray[i] = Array[(head + i) % capacity];
        }
        head = 0;
        tail = size;
        delete[] Array;
        Array = Brray;
        capacity *= 2;
    }

    void resizeDown() {
        int *Brray = new int[capacity/2];
        for (int i = 0; i < size; ++i) {
            Brray[i] = Array[(head + i) % capacity];
        }
        head = 0;
        tail = size;
        delete[] Array;
        Array = Brray;
        capacity /= 2;
    }
};


signed main() {
    fast;
    int m;
    cin >> m;
    myQueue *q = new myQueue();

    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            q->push(x);
        } else {
            cout << q->pop() << endl;
        }
    }

    return 0;
}
