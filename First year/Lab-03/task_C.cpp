#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define sz(a) int(a.size())
#define pb push_back
#define F first
#define S second


using namespace std;

struct node {
    int key, num;
    node(int kk, int nn) {
        key = kk;
        num = nn;
    }
};

vector<node> heap;
vector<int> arr;


void swap_nodes(int i, int j) {
    swap(heap[i], heap[j]);
    arr[heap[i].num] = i;
    arr[heap[j].num] = j;
}

void siftUp(int i) {
    while (i && heap[i].key < heap[(i - 1)/2].key) {
        swap_nodes(i, (i - 1)/2);
        i = (i - 1)/2;
    }
}

void siftDown(int i) {
    while (i < sz(heap)) {
        int j = 2*i + 1;
        if (2*i + 2 < sz(heap) && heap[2*i + 2].key < heap[2*i + 1].key) {
            j++;
        }
        if (j >= sz(heap) || heap[i].key < heap[j].key) return;
        swap_nodes(i, j);
        i = j;
    }
}

void ins(int key) {
    heap.push_back(node(key, sz(arr)));
    arr.push_back(sz(heap) - 1);
    siftUp(sz(heap) - 1);
}

void decKey(int pos, int dec) {
    if (arr[pos] < sz(heap)) {
        heap[arr[pos]].key = dec;
        siftUp(arr[pos]);
    }
}


signed main() {
    string s;

    while (cin >> s) {
        if (s == "push") {
            int x;
            cin >> x;
            ins(x);
        } else if (s == "extract-min") {
            if (sz(heap) > 0) {
                swap_nodes(0, sz(heap) - 1);
                cout << heap[sz(heap) - 1].key << ' ' << heap[sz(heap) - 1].num + 1 << endl;
                heap.pop_back();
                siftDown(0);
            } else {
                cout << '*' << endl;
            }
            arr.push_back(-1);
        } else {
            int pos, dec;
            cin >> pos >> dec;
            decKey(pos - 1, dec);
            arr.push_back(-1);
        }
    }

    return 0;
}
