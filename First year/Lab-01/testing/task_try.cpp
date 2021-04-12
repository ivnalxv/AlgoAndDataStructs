#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second

using namespace std;

const int MAXN = 1e5 + 7;
const long long INF = 1e11;
const int mod = 1e9 + 7;


struct myStack {
    int size, capacity;
    int *Array;
    int *Brray;

    myStack() {
        size = 0;
        capacity = 1;
        Array = new int[1];
        Brray = new int[1];
    }

    void resizeUp() {
        int *Crray = new int[capacity*2];
        int *Drray = new int[capacity*2];

        for (int i = 0; i < size; ++i) {
            Crray[i] = Array[i];
            Drray[i] = Brray[i];
        }
        delete[] Array;
        delete[] Brray;
        Array = Crray;
        Brray = Drray;
        capacity *= 2;
    }

    void resizeDown() {
        int *Crray = new int[capacity/2];
        int *Drray = new int[capacity/2];

        for (int i = 0; i < size; ++i) {
            Crray[i] = Array[i];
            Drray[i] = Brray[i];
        }
        delete[] Array;
        delete[] Brray;
        Array = Crray;
        Brray = Drray;
        capacity /= 2;
    }

    void push(int x) {
        if (size == capacity) {
            resizeUp();
        }
        if (size > 0) {
            Array[size] = x;
            Brray[size] = min(x, Brray[size - 1]);
        } else {
            Array[size] = x;
            Brray[size] = x;
        }
        ++size;
    }

    int pop() {
        --size;
        int x = Array[size];
        /**
        if (size == capacity/4 && capacity/4 > 0) {
            resizeDown();
        }
        **/
        return x;
    }

    int get_min() {
        if (size > 0) {
            return Brray[size - 1];
        }
        return INT_MAX;
    }
};


struct myQueue {
    myStack *st1 = new myStack();
    myStack *st2 = new myStack();

    myQueue() {
    }

    void push(int x) {
        st1->push(x);
    }

    int pop() {
        if (st2->size == 0) {
            while (st1->size > 0) {
                st2->push(st1->pop());
            }
        }
        return st2->pop();
    }

    int get_min() {
        return min(st1->get_min(), st2->get_min());
    }
};




signed main() {
    fast;
    myQueue *q = new myQueue();

    int n, m, k, a, b, c;
    cin >> n >> m >> k >> a >> b >> c;

    int *x = new int[k];
    long long sum = 0;

    for (int i = 0; i < k; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            sum += q->get_min();
            q->pop();
        }
        if (i < k) {
            q->push(x[i]);
        } else {
            x[i%k] = a*x[(i - 2)%k] + b*x[(i - 1)%k] + c;
            q->push(x[i%k]);
        }
    }
    sum += q->get_min();

    cout << sum << endl;

    return 0;
}
