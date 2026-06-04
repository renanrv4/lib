// Exemplo de SegTree Esparsa de mínimos
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll NEUTRO = LLONG_MAX;
const int N = 2e5 + 5;

struct Node {
    ll val;
    Node *L, *R;
    Node() {
        val = NEUTRO; L = nullptr; R = nullptr;
    }
};

Node* root = nullptr;
int n;

ll join(ll a, ll b) {
    return min(a, b);
}

ll query(Node* node, int L, int R, int l = 0, int r = n - 1) {
    if(!node || R < l || L > r) {
        return NEUTRO;
    }
    if(L <= l && r <= R) {
        return node->val;
    }
    int mid = (l+r)/2;
    return join(query(node->L, L, R, l, mid), query(node->R, L, R, mid+1, r));
}


void update(Node* &node, int i, ll val, int l = 0, int r = n-1) {
    if (!node) node = new Node();
    if(l == r) {
        node->val = val;
        return;
    }
    int mid = (l+r)/2;
    if(i <= mid) {
        update(node->L, i, val, l, mid);
    } else {
        update(node->R, i, val, mid+1, r);
    }
    ll lv = node->L ? node->L->val : NEUTRO;
    ll rv = node->R ? node->R->val : NEUTRO;
    node->val = join(lv, rv);
}

ll query(int L, int R) { return query(root, L, R); }
void update(int i, ll val) { return update(root, i, val); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int q; cin >> n >> q;
    root = nullptr;
    for(int i = 0; i < n; i++) {
        ll num; cin >> num;
        update(i, num);
    }
    while(q--) {
        ll l, r; cin >> l >> r; l--, r--;
        cout << query(l, r) << "\n";
    }
    return 0;
}
