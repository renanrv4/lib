#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5 + 5;
int n;
ll seg[4*N];
ll lazy[4*N];
vector<ll> elements;

ll join(ll a, ll b) {
    return a + b;
}

void propagate(int no, int i, int j) {
    if(lazy[no] == 0) return;
    seg[no] += lazy[no] * (j - i + 1);
    if(i != j) {
        lazy[no*2+1] += lazy[no];
        lazy[no*2+2] += lazy[no];
    }
    lazy[no] = 0;
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
    propagate(idx, l, r);
    if(R < l || L > r) {
        return 0;
    }
    if(L <= l && r <= R) {
        return seg[idx];
    }
    int mid = (l+r)/2;
    return join(query(L, R, l, mid, 2*idx+1), query(L, R, mid+1, r, 2*idx+2));
}

void update_range(int L, int R, ll val, int l = 0, int r = n-1, int idx = 0) {
    propagate(idx, l, r);
    if(R < l || L > r) {
        return;
    }
    if(L <= l && r <= R) {
        lazy[idx] += val;
        propagate(idx, l, r);
        return;
    }
    int mid = (l+r)/2;
    update_range(L, R, val, l, mid, 2*idx+1);
    update_range(L, R, val, mid+1, r, 2*idx+2);
    seg[idx] = join(seg[2*idx+1], seg[2*idx+2]);
}

// 0-indexed
