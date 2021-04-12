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

struct myVector {
    size_t vectorSize, vectorCap;
    int *myArray;


    myVector() {
        vectorSize = 0;
        vectorCap = 1;
        myArray = new int[vectorCap];
    }

    myVector(size_t length) {
        assert(length > 0);
        vectorSize = 0;
        vectorCap = length;
        myArray = new int[vectorCap];
    }

    void resizeVectorUp() {
        int *tempArray = new int[2*vectorCap];
        for (unsigned int i = 0; i < vectorSize; i++) {
            *(tempArray + i) = *(myArray + i);
        }
        delete[] myArray;
        myArray = tempArray;
        vectorCap *= 2;
    }

    void resizeVectorDown() {
        int *tempArray = new int[vectorCap/4];
        for (unsigned int i = 0; i < vectorSize; i++) {
            *(tempArray + i) = *(myArray + i);
        }
        delete[] myArray;
        myArray = tempArray;
        vectorCap /= 4;
    }

    void push(int x) {
        if (vectorSize == vectorCap) {
            resizeVectorUp();
        }
        *(myArray + vectorSize) = x;
        ++vectorSize;
    }

    int get(int index) {
        return myArray[index];
    }

    void change(int index, int x) {
        if (index < vectorCap) {
            *(myArray + index) = x;
        } else {
            resizeVectorUp();
            change(index, x);
        }
    }

    void print() {
        for (int index = 0; index < vectorCap; index++) {
            cout << *(myArray + index) << " ";
        }
        cout << endl;
    }
};

struct myStack {
    myVector *myArray = new myVector();

    void push(int x) {
        myArray->push(x);
    }

    int pop() {
        --myArray->vectorSize;
        int x = myArray->get(myArray->vectorSize);
        if (myArray->vectorSize == myArray->vectorCap/4 && myArray->vectorCap/4 > 0) {
            myArray->resizeVectorDown();
        }
        return x;
    }

    void print() {
        myArray->print();
    }
};

signed main() {
    fast;
    int m;
    cin >> m;

    myStack *q = new myStack();

    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            q->push(x);
        } else if (c == 'p') {
            q->print();
        } else {
            cout << q->pop() << endl;
        }
    }

    return 0;
}
