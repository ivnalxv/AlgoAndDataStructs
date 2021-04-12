//
// Created by admin on 21.02.2021.
//


#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key, value;
    Node *left = nullptr, *right = nullptr;

    Node(int _key) {
        key = _key;
        value = rand();
    }
};

Node* merge(Node *l, Node *r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;

    if (l->value > r->value) {
        l->right = merge(l->right, r);
        return l;
    }
    r->left = merge(l, r->left);
    return r;
}

pair<Node*, Node*> split(Node *node, int key) {
    if (node == nullptr) return {nullptr, nullptr};
    if (node->key <= key) {
        pair<Node*, Node*> temp = split(node->right, key);
        node->right = temp.first;
        return {node, temp.second};
    }
    pair<Node*, Node*> temp = split(node->left, key);
    node->left = temp.second;
    return {temp.first, node};
}

void dfs(Node *node) {
    if (node == nullptr) return;

    cout << "key: " << node->key << ", value: " << node->value << endl;

    if (node->left == nullptr && node->right == nullptr) {
        cout << "UP" << endl;
        return;
    }

    if (node->right != nullptr) {
        cout << "R" << endl;
        dfs(node->right);
    }

    if (node->left != nullptr) {
        cout << "L" << endl;
        dfs(node->left);
    }

    cout << "UP" << endl;
}

Node *root = nullptr;

void insert(int key) {
    pair<Node*, Node*> temp_pair = split(root, key);
    Node *temp = new Node(key);
    root = merge(merge(temp_pair.first, temp), temp_pair.second);
}

bool find(int key) {
    Node *it = root;

    while (it != nullptr && it->key != key) {
        if (it->left != nullptr && key <= it->key) {
            it = it->left;
        } else if (it->right != nullptr && it->key < key) {
            it = it->right;
        } else {
            return false;
        }
    }

    return (it != nullptr);
}

void remove(Node* &node, int key) {
    if (node == nullptr) return;

    if (node->key == key) {
        node = merge(node->left, node->right);
        return;
    }

    remove(key < node->key ? node->left : node->right, key);
}

int min(Node *node) {
    if (node->left == nullptr) return node->key;
    return min(node->left);
}

int max(Node *node) {
    if (node->right == nullptr) return node->key;
    return max(node->right);
}

int next_min(Node *node, int key) {
    while (node != nullptr && node->key <= key) {
        node = node->right;
    }

    if (node == nullptr) return key + 1;

    int mn = next_min(node->left, key);
    if (find(mn)) return mn;
    return node->key;

    /*
    while (node != nullptr && node->key < key) {
        node = node->right;
    }

    if (node == nullptr) return -1;

    int mn = next_min(node->left, key);
    if (find(mn)) return mn;
    return node->key;*/
}

int prev_max(Node *node, int key) {
    /*
    if (node == nullptr) return key + 1;
    if (key <= node->key) return prev_max(node->left, key);
    if (node->right != nullptr && key > node->right->key) return prev_max(node->right, key);
    return node->key;
     */

    while (node != nullptr && node->key >= key) {
        node = node->left;
    }

    if (node == nullptr) return key - 1;

    int mn = prev_max(node->right, key);
    if (find(mn)) return mn;
    return node->key;
}

int max_deepness(Node *node, int dp = 0) {
    if (node == nullptr) return dp - 1;
    return max(max_deepness(node->left, dp + 1), max_deepness(node->right, dp + 1));
}

bool check(Node *node) {
    if (node == nullptr) return true;
    if (node->left != nullptr && node->left->key > node->key) {
        return false;
    }
    if (node->right != nullptr && node->right->key <= node->key) {
        return false;
    }

    return check(node->left) && check(node->right);
}


int main() {
    string cmd;
    int x;

    while (cin >> cmd) {
        cin >> x;

        if (cmd == "insert" || cmd == "ins") {
            if (!find(x)) insert(x);
        } else if (cmd == "delete" || cmd == "remove") {
            remove(root, x);
        } else if (cmd == "exists" || cmd == "find") {
            cout << (find(x) ? "true" : "false") << endl;
        } else if (cmd == "next") {
            int nxt = next_min(root, x);
            if (find(nxt)) cout << nxt << endl;
            else cout << "none" << endl;
        } else if (cmd == "prev") {
            int prv = prev_max(root, x);
            if (find(prv)) cout << prv << endl;
            else cout << "none" << endl;
        } else if (cmd == "deep") {
            cout << max_deepness(root) << endl;
        } else if (cmd == "dfs") {
            dfs(root);
        } else if (cmd == "ch") {
            cout << (check(root) ? "true" : "false") << endl;
        } else {
            return 0;
        }
    }


    return 0;
}
