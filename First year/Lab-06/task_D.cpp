//
// Created by admin on 17.03.2021.
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
    object *next = nullptr;
    object *prev = nullptr;
    string data;

    object(string &_data, object *_prev) {
        data = _data;
        prev = _prev;
    }

    explicit object(string &_data) {
        data = _data;
    }
};

struct multi {
    vector<vector<object*>> must;
    object *tail;
    string key;
    int size;

    multi(string &_key, string &_value) {
        must = vector<vector<object*>> (223);
        tail = new object(_value);
        key = _key;
        size = 1;
    }
};

vector<vector<multi*>> hash_array(1000039);

int hash_func(string &x, int m) {
    int hsh = 0;
    for (auto i : x) {
        hsh = (hsh * 31 + i) % m;
    }
    return hsh;
}

multi* find_multi(string &x) {
    int hsh = hash_func(x, 1000039);
    for (auto i : hash_array[hsh]) {
        if (i->key == x) return i;
    }
    return nullptr;
}

object* find_object(string &x, string &y) {
    multi *muset = find_multi(x);
    if (muset == nullptr) return nullptr;

    int hsh = hash_func(y, 223);
    for (auto i : muset->must[hsh]) {
        if (i->data == y) return i;
    }
    return nullptr;
}

void insert(string &x, string &y) {
    multi *muset = find_multi(x);
    int hsh = hash_func(y, 223);

    if (muset == nullptr) {
        muset = new multi(x, y);
        muset->must[hsh].push_back(muset->tail);
        hash_array[hash_func(x, 1000039)].push_back(muset);
        return;
    }


    for (auto i : muset->must[hsh]) {
        if (i->data == y) {
            return;
        }
    }

    auto *obj = new object(y, muset->tail);
    if (muset->tail != nullptr) {
        muset->tail->next = obj;
    }

    muset->must[hsh].push_back(obj);
    muset->tail = obj;
    muset->size++;
}

void remove_multi(string &x) {
    if (find_multi(x) == nullptr) return;
    int hsh = hash_func(x, 1000039);

    for (int i = 0; i < sz(hash_array[hsh]) - 1; i++) {
        if (hash_array[hsh][i]->key == x) {
            swap(hash_array[hsh][i], hash_array[hsh][i + 1]);
        }
    }

    hash_array[hsh].pop_back();
}

void remove_from_multi(object *obj) {
    if (obj->prev != nullptr) {
        obj->prev->next = obj->next;
    }
    if (obj->next != nullptr) {
        obj->next->prev = obj->prev;
    }
}

void remove_object(string &x, string &y) {
    if (find_object(x, y) == nullptr) return;

    multi *muset = find_multi(x);

    int hsh = hash_func(y, 223), mssz = sz(muset->must[hsh]) - 1;

    for (int i = 0; i < mssz; i++) {
        if (muset->must[hsh][i]->data == y) {
            swap(muset->must[hsh][i], muset->must[hsh][i + 1]);
        }
    }

    remove_from_multi(muset->must[hsh][mssz]);
    muset->must[hsh].pop_back();
    muset->size--;

    if (muset->must[hsh][mssz] == muset->tail) {
        muset->tail = muset->tail->prev;
    }
}


int main() {
    fast;
    string cmd, x, y;

    while (cin >> cmd >> x) {
        if (cmd == "put") {
            cin >> y;
            insert(x, y);
        } else if (cmd == "get") {
            multi *muset = find_multi(x);

            if (muset == nullptr) {
                cout << 0 << '\n';
                continue;
            }

            cout << muset->size << ' ';
            object *it = muset->tail;

            while (it != nullptr) {
                cout << it->data << ' ';
                it = it->prev;
            }

            cout << '\n';
        } else if (cmd == "delete") {
            cin >> y;
            remove_object(x, y);
        } else {
            remove_multi(x);
        }
    }


    return 0;
}
