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
    char *myArray;


    myVector() {
        vectorSize = 0;
        vectorCap = 1;
        myArray = new char[vectorCap];
    }

    myVector(size_t length) {
        assert(length > 0);
        vectorSize = 0;
        vectorCap = length;
        myArray = new char[vectorCap];
    }

    void resizeVectorUp() {
        char *tempArray = new char[2*vectorCap];
        for (unsigned int i = 0; i < vectorSize; i++) {
            *(tempArray + i) = *(myArray + i);
        }
        delete[] myArray;
        myArray = tempArray;
        vectorCap *= 2;
    }

    void resizeVectorDown() {
        char *tempArray = new char[vectorCap/4];
        for (unsigned int i = 0; i < vectorSize; i++) {
            *(tempArray + i) = *(myArray + i);
        }
        delete[] myArray;
        myArray = tempArray;
        vectorCap /= 4;
    }

    void push(char x) {
        if (vectorSize == vectorCap) {
            resizeVectorUp();
        }
        *(myArray + vectorSize) = x;
        ++vectorSize;
    }

    char get(int index) {
        return myArray[index];
    }

    void change(int index, char x) {
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

    void push(char x) {
        myArray->push(x);
    }

    int stackSize() {
        return myArray->vectorSize;
    }

    char pop() {
        --myArray->vectorSize;
        char x = myArray->get(myArray->vectorSize);
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
    string s;

    while (getline(cin, s)) {
        bool ans = 1;
        myStack *st = new myStack();
        for (auto i : s) {
            if (i == '[' || i == '(') {
                st->push(i);
            } else {
                if (st->stackSize() == 0) {
                    ans = 0;
                    break;
                }
                char c = st->pop();
                if ((c != '[' && i == ']') || (c != '(' && i == ')')) {
                    ans = 0;
                    break;
                }
            }
        }
        if (st->stackSize() > 0) ans = 0;
        cout << (ans ? "YES" : "NO") << endl;
    }



    return 0;
}
