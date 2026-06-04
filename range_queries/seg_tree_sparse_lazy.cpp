// Exemplo de SegTree Esparsa com lazy propagation de soma
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll NEUTRO = 0;

struct Node {
    ll val, lazy;
    Node *L, *R;
    Node() {
        val = NEUTRO; lazy = 0; L = nullptr; R = nullptr;
    }
};

Node* root = nullptr;
ll n;

ll join(ll a, ll b) {
    return a + b;
}

void propagate(Node* node, ll i, ll j) {
    if(!node || node->lazy == 0) {
        return;
    }
    node->val += node->lazy * (j - i + 1);
    if(i != j) {
        if(!node->L) {
            node->L = new Node;
        }
        if(!node->R) {
            node->R = new Node;
        }
        node->L->lazy += node->lazy;
        node->R->lazy += node->lazy;
    }
    node->lazy = 0;
}

ll query(Node* node, ll L, ll R, ll l = 0, ll r = n - 1) {
    if(!node || R < l || L > r) {
        return NEUTRO;
    }
    propagate(node, l, r);
    if(L <= l && r <= R) {
        return node->val;
    }
    ll mid = (l+r)/2;
    return join(query(node->L, L, R, l, mid), query(node->R, L, R, mid+1, r));
}


void update_range(Node* &node, ll L, ll R, ll val, ll l = 0, ll r = n-1) {
    if(!node) {
        node = new Node();
    }
    if(R < l || L > r) {
        return;
    }
    propagate(node, l, r);
    if(L <= l && r <= R) {
        node->lazy += val;
        propagate(node, l, r);
        return;
    }
    ll mid = (l+r)/2;
    update_range(node->L, L, R, val, l, mid);
    update_range(node->R, L, R, val, mid+1, r);
    ll lv = node->L ? node->L->val : NEUTRO;
    ll rv = node->R ? node->R->val : NEUTRO;
    node->val = join(lv, rv);
}

ll query(ll L, ll R) { return query(root, L, R); }
void update_range(ll l, ll r, ll val) { return update_range(root, l, r, val); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int q; cin >> n >> q;
    root = nullptr;
    for(ll i = 0; i < n; i++) {
        ll l, r, num; cin >> l >> r >> num; l--; r--;
        update_range(l, r, num);
    }
    while(q--) {
        int type_q; cin >> type_q;
        ll l, r; cin >> l >> r; l--, r--;
        if(type_q == 1) {
            cout << query(l, r) << "\n";
        } else {
            ll val; cin >> val;
            update_range(l, r, val);
        }
    }
    return 0;
}
