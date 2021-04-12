//
// Created by admin on 15.03.2021.
//

#include <iostream>

#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

/*
// a + 31b = c + 31d => a - c = 31 * (d - b)
// 'a' = y, 'c' = Z, 'd' = z, 'b' = y
// hash("zZ") == hash("yy")
*/

string get(int n) {
    string hsh = "";
    int pw = 11;
    while (pw--) {
        hsh += (n & 1 ? "zZ" : "yy");
        n /= 2;
    }

    return hsh;
}

int main() {
    fast;
    int k;
    cin >> k;

    while (k--) {
        cout << get(k) << "\n";
    }

    return 0;
}