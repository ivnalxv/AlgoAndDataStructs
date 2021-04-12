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

struct myList {
    myList *next = nullptr;
    myList *prev = nullptr;
    int data;
};

struct myQueue {
    myList *head = new myList();
    myList *tail = new myList();

    myQueue() {
        head = new myList();
        head->next = tail;
        tail->prev = head;
    }

    void push(int elem) {
        myList *node = new myList();
        node->data = elem;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    int pop() {
        myList *p = head->next;
        int x = p->data;
        p->next->prev = head;
        head->next = p->next;
        delete p;
        return x;
    }

    void print() {
        myList *p = head->next;
        while (p != tail) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
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
        } else if (c == '-') {
            cout << q->pop() << endl;
        } else {
            q->print();
        }
    }

    return 0;
}
