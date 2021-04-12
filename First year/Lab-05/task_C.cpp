//
// Created by admin on 22.02.2021.
//


#include <iostream>
#include <string>

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

    if (l->value > r->value) {
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
    if (size(node->left) + 1 <= key) {
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

void insert(int key) {
    pair<Node*, Node*> pr = split(root, key);
    root = merge(merge(pr.first, new Node(key)), pr.second);
}

void send_to_start(int l, int r) {
    pair<Node*, Node*> pr1 = split(root, r);
    pair<Node*, Node*> pr2 = split(pr1.first, l - 1);
    root = merge(pr2.first, pr1.second);
    root = merge(pr2.second, root);
    update(root);
}

void print(Node *node) {
    if (node == nullptr) return;
    print(node->left);
    cout << node->key << " ";
    print(node->right);
}


int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        insert(i + 1);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        send_to_start(l, r);
    }

    print(root);

    return 0;
}
