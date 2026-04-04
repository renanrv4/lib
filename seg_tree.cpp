// Exemplo de uma Seg Tree de mínimos
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5 + 5;
int n;
ll seg[4*N];
vector<ll> elements;

ll join(ll a, ll b) {
    return min(a, b);
}

void build(int l = 0, int r = n - 1, int idx = 0) {
    if(l == r) {
        seg[idx] = elements[l];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*idx+1);
    build(mid+1, r, 2*idx+2);
    seg[idx] = join(seg[2*idx+1], seg[2*idx+2]);
}

ll query(int L, int R, int l = 0, int r = n - 1, int idx = 0) {
    if(R < l || L > r) {
        return LLONG_MAX;
    }
    if(L <= l && r <= R) {
        return seg[idx];
    }
    int mid = (l+r)/2;
    return join(query(L, R, l, mid, 2*idx+1), query(L, R, mid+1, r, 2*idx+2));
}

void update(int i, ll val, int l = 0, int r = n-1, int idx = 0) {
    if(l == r) {
        seg[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    if(i <= mid) {
        update(i, val, l, mid, 2*idx+1);
    } else {
        update(i, val, mid+1, r, 2*idx+2);
    }
    seg[idx] = join(seg[2*idx+1], seg[2*idx+2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int q; cin >> n >> q;
    elements.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    build();
    while(q--) {
        int l, r; cin >> l >> r; l--; r--;
        cout << query(l, r) << "\n";
    }
    return 0;
}
