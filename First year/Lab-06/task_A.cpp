//
// Created by admin on 15.03.2021.
//

#include <iostream>
#include <vector>

#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;

vector<vector<int>> hash_array(1000039);

int find(int x) {
    int hsh = abs(x) % 1000039;
    for (int i : hash_array[hsh]) {
        if (i == x) return true;
    }
    return false;
}

void insert(int x) {
    if (find(x)) return;
    int hsh = abs(x) % 1000039;
    hash_array[hsh].push_back(x);
}

void remove(int x) {
    int hsh = abs(x) % 1000039, n = sz(hash_array[hsh]) - 1;
    for (int i = 0; i < sz(hash_array[hsh]); i++) {
        if (hash_array[hsh][i] == x) {
            swap(hash_array[hsh][i], hash_array[hsh][n]);
            hash_array[hsh].pop_back();
            return;
        }
    }
}

int main() {
    string cmd;
    int x;
    fast;

    while (cin >> cmd >> x) {
        if (cmd == "insert") {
            insert(x);
        } else if (cmd == "exists") {
            cout << (find(x) ? "true\n" : "false\n");
        } else {
            remove(x);
        }
    }


    return 0;
}
