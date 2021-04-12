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
    if (node->key <= key) {
        pair<Node*, Node*> temp = split(node->right, key);
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

void insert(int key) {
    pair<Node*, Node*> pr = split(root, key);
    root = merge(merge(pr.first, new Node(key)), pr.second);
    update(root);
}

void remove(int key) {
    pair<Node*, Node*> pr1 = split(root, key);
    update(pr1.first);
    update(pr1.second);
    pair<Node*, Node*> pr2 = split(pr1.first, key - 1);
    update(pr2.first);
    update(pr2.second);
    root = merge(pr2.first, pr1.second);
    update(root);
}

int get(Node *node, int k) {
    if (size(node->right) == k - 1) {
        return node->key;
    }
    if (k <= size(node->right)) {
        return get(node->right, k);
    }
    return get(node->left, k - size(node->right) - 1);
}


int main() {
    fast;
    int n;
    cin >> n;

    while (n--) {
        int cmd, x;
        cin >> cmd >> x;
        if (cmd == 1) {
            insert(x);
        } else if (cmd == -1) {
            remove(x);
        } else {
            cout << get(root, x) << endl;
        }
    }


    return 0;
}
