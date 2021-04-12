//
// Created by admin on 28.02.2021.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int p[27 * 100000];

int find(int v) {
    if (p[v] == v) return v;
    return p[v] = find(p[v]);
}


struct Node {
    int key, value, size;
    Node *left = nullptr, *right = nullptr;

    Node(int _key) {
        key = _key;
        value = rand();
        size = 1;
    }
};

int size(Node *node) {
    return node == nullptr ? 0 : node->size;
}

void update(Node *node) {
    if (node == nullptr) return;
    node->size = size(node->left) + size(node->right) + 1;
}

Node* merge(Node *l, Node *r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;

    if (l->value < r->value) {
        l->right = merge(l->right, r);
        update(l);
        return l;
    }
    r->left = merge(l, r->left);
    update(r);
    return r;
}

pair<Node*, Node*> split(Node *node, int key) {
    if (node == nullptr) return {nullptr, nullptr};
    if (size(node->left) < key) {
        pair<Node*, Node*> temp = split(node->right, key - size(node->left) - 1);
        node->right = temp.first;
        update(node);
        return {node, temp.second};
    }
    pair<Node*, Node*> temp = split(node->left, key);
    node->left = temp.second;
    update(node);
    return {temp.first, node};
}

Node *root = nullptr;

void insert(int key, int x) {
    pair<Node*, Node*> pr = split(root, key);
    root = merge(merge(pr.first, new Node(x)), pr.second);
    update(root);
}

void remove(int key) {
    pair<Node*, Node*> pr1 = split(root, key);
    pair<Node*, Node*> pr2 = split(pr1.second, 1);
    p[key] = key + 1;
    root = merge(pr1.first, pr2.second);
    update(root);
}

vector<int> result;

void precalc(Node *node) {
    if (node == nullptr) return;
    precalc(node->left);
    result.push_back(node->key);
    precalc(node->right);
}

void print() {
    precalc(root);
    int j = result.size() - 1;
    while (result[j] == 0) {
        j--;
    }

    cout << j + 1 << endl;
    for (int i = 0; i <= j; i++) cout << result[i] << " ";
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n + m; i++) {
        p[i] = i;
        root = merge(root, new Node(0));
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        remove(find(x - 1));
        insert(x - 1, i + 1);
    }

    print();

    return 0;
}
