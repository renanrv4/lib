struct Node {
    ll sum, pref, suff, best;
};
Node make_node(ll v) {
    Node nd;
    nd.sum = v;
    nd.pref = nd.suff = nd.best = max(0LL, v); 
    return nd;
}

Node join(Node L, Node R) {
    Node LR;
    LR.sum = L.sum + R.sum;
    LR.pref = max(L.pref, L.sum + R.pref);
    LR.suff = max(R.suff, R.sum + L.suff);
    LR.best = max({L.best, R.best, L.suff + R.pref});
    return LR;
}
