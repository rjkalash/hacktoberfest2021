#include <bits/stdc++.h>
using namespace std;

const int MAXBIT = 29;
struct Node{
    int occ;
    Node* child[2];
};

Node* create() {
    Node* nd = new Node();
    for (auto & i : nd->child) {
        i = nullptr;
    }
    nd->occ = 0;
    return nd;
}

Node* root = create();
int pres(int val) {
    bool x;
    Node* ex = root;
    for (int i = MAXBIT; i >= 0; --i) {
        x = val & (1 << i);
        if (ex->child[x] != nullptr && ex->child[x]->occ) {
            ex = ex->child[x];
        }else return -1;
    }
    return 1;
}

void add(int val, int delta) {
    if (pres(val) == delta) return;
    Node* ex = root;
    bool x;
    for (int i = MAXBIT; i >= 0; --i) {
        x = val & (1 << i);
        if (ex->child[x] == nullptr) {
            assert(delta == 1);
            ex->child[x] = create();
        }
        ex = ex->child[x];
        ex->occ += delta;
    }
}

int MinXor(int val) {
    Node* ex = root;
    int mi = 0;
    bool x;
    for (int i = MAXBIT; i >= 0; --i) {
        x = val & (1 << i);
        if (ex->child[x] != nullptr && ex->child[x]->occ) ex = ex->child[x];
        else mi += 1 << i, ex = ex->child[!x];
    }
    return mi;
}

int main() {

    int q;cin >> q;
    while (q--) {
        int op, x;cin >> op >> x;
        if (op == 0) {
            add(x, 1);
        }else if (op == 1) {
            add(x, -1);
        }else{
            cout << MinXor(x) << "\n";
        }
    }
    return 0;
}
