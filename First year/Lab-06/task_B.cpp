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
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

vector<vector<pair<string, string>>> hash_array(1000039);

int hash_func(string &x) {
    int hsh = 0;
    for (auto i : x) {
        hsh = (hsh * 31 + i) % 1000039;
    }
    return hsh;
}

string find(string &x) {
    int hsh = hash_func(x);
    for (const auto &i : hash_array[hsh]) {
        if (i.F == x) return i.S;
    }
    return "none";
}

void insert(string &x, string &y) {
    int hsh = hash_func(x);
    for (auto &i : hash_array[hsh]) {
        if (i.F == x) {
            i.S = y;
            return;
        }
    }
    hash_array[hsh].push_back({x, y});
}

void remove(string &x) {
    if (find(x) == "none") return;

    int hsh = hash_func(x);
    for (int i = 0; i < sz(hash_array[hsh]) - 1; i++) {
        if (hash_array[hsh][i].F == x) {
            swap(hash_array[hsh][i], hash_array[hsh][i + 1]);
        }
    }
    hash_array[hsh].pop_back();
}

int main() {
    string cmd, x, y;
    fast;

    while (cin >> cmd >> x) {
        if (cmd == "put") {
            cin >> y;
            insert(x, y);
        } else if (cmd == "get") {
            cout << find(x) << "\n";
        } else {
            remove(x);
        }
    }


    return 0;
}
