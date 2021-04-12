//
// Created by admin on 23.02.2021.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<pair<pair<int, int>, int>> xy, ans;

struct Node {
    int key, value, num;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;

    Node(int _key, int _value, int _num) {
        key = _key;
        value = _value;
        num = _num;
    }
};

void inline upd(Node *node, Node *par) {
    if (node == nullptr) return;
    node->parent = par;
}

void inline update(Node *node) {
    upd(node->left, node);
    upd(node->right, node);
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

Node* ins(int key, int prior, int num, Node* pont) {
    Node *node = new Node(key, prior, num);
    if (pont == nullptr) {
        return node;
    }
    if (node->value > pont->value) {
        node->parent = pont;
        update(node);
        pont->right = node;
        update(pont);
        return node;
    }

    while (pont->parent != nullptr && pont->parent->value > node->value) {
        pont = pont->parent;
    }

    if (pont->parent == nullptr) {
        pont->parent = node;
        node->left = pont;
        update(pont);
        update(node);
        return node;
    }
    pont->parent->right = node;
    update(pont->parent);
    node->parent = pont->parent;
    pont->parent = node;
    node->left = pont;
    update(pont);
    update(node);
    return node;
}

void insert(int key, int prior, int num) {
    pair<Node*, Node*> pr = split(root, key);
    root = merge(pr.first, new Node(key, prior, num));
    update(root);

    root = merge(root, pr.second);
    update(root);
    root->parent = nullptr;
}

int get(Node *node) {
    if (node == nullptr) return 0;
    return node->num;
}

void make_print_great_again(Node *node) {
    if (node == nullptr) return;
    ans[node->num] = {{get(node->parent), get(node->left)}, get(node->right)};
    make_print_great_again(node->left);
    make_print_great_again(node->right);
}


int main() {
    fast;
    int n;
    cin >> n;

    ans = vector<pair<pair<int, int>, int>> (n + 1, {{0, 0}, 0});
    xy = vector<pair<pair<int, int>, int>> (n, {{0, 0}, 0});


    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        xy[i] = {{a, b}, i + 1};
    }

    sort(all(xy));

    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
        root = ins(xy[i].first.first, xy[i].first.second, xy[i].second, root);
    }

    while (root->parent != nullptr) {
        root = root->parent;
    }

    make_print_great_again(root);

    for (int i = 1; i <= n; i++) {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
    }


    return 0;
}
