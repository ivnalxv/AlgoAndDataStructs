//
// Created by admin on 16.03.2021.
//


#include <iostream>
#include <vector>

#define F first
#define S second
#define all(a) a.begin(), (a).end()
#define rall(a) a.rbegin(), (a).rend()
#define sz(a) int((a).size())
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

struct object {
    object *next, *prev;
    string key, val;

    object(string _key, string _value, object *_prev) {
        key = std::move(_key);
        val = std::move(_value);
        prev = _prev;
        next = nullptr;
    }
};

vector<vector<object*>> hash_array(1000039);
object *link = nullptr;

int hash_func(string &x) {
    int hsh = 0;
    for (auto i : x) {
        hsh = (hsh * 31 + i) % 1000039;
    }
    return hsh;
}

object* find_object(string &x) {
    int hsh = hash_func(x);
    for (auto i : hash_array[hsh]) {
        if (i->key == x) return i;
    }
    return nullptr;
}

string find(string &x) {
    auto *obj = find_object(x);
    if (obj == nullptr) return "none";
    return obj->val;
}

void insert(string &x, string &y) {
    int hsh = hash_func(x);
    for (auto i : hash_array[hsh]) {
        if (i->key == x) {
            i->val = y;
            return;
        }
    }

    auto *obj = new object(x, y, link);
    if (link != nullptr) {
        link->next = obj;
    }
    link = obj;

    hash_array[hsh].push_back(link);
}

void remove_from_link(object *obj) {
    if (obj->prev != nullptr) {
        obj->prev->next = obj->next;
    }
    if (obj->next != nullptr) {
        obj->next->prev = obj->prev;
    }
    if (obj == link) {
        link = link->prev;
    }
}

void remove(string &x) {
    if (find_object(x) == nullptr) return;

    int hsh = hash_func(x), hasz = sz(hash_array[hsh]) - 1;
    for (int i = 0; i < hasz; i++) {
        if (hash_array[hsh][i]->key == x) {
            swap(hash_array[hsh][i], hash_array[hsh][i + 1]);
        }
    }

    remove_from_link(hash_array[hsh][hasz]);
    hash_array[hsh].pop_back();
}


int main() {
    fast;
    string cmd, x, y;

    while (cin >> cmd >> x) {
        if (cmd == "put") {
            cin >> y;
            insert(x, y);
        } else if (cmd == "get") {
            cout << find(x) << "\n";
        } else if (cmd == "delete") {
            remove(x);
        } else {
            auto *obj = find_object(x);
            if (obj != nullptr) {
                obj = (cmd == "prev" ? obj->prev : obj->next);
            }
            cout << (obj == nullptr ? "none" : obj->val) << "\n";
        }
    }


    return 0;
}
