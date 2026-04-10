struct Node {
    pair<ll, ll> bests;
    map<ll, int> freq; 
};
Node join(Node L, Node R) {
    Node LR;
    set<ll> ord; ord.insert(L.bests.first); ord.insert(L.bests.second); ord.insert(R.bests.first); ord.insert(R.bests.second); ord.insert(0);
    ll best = 0;
    for(auto it : ord) {    
        best = max(best, it);
    }
    ord.erase(best);
    ll sec_best = 0;
    for(auto it : ord) {    
        sec_best = max(sec_best, it);
    }
    LR.bests.first = best; LR.bests.second = sec_best;
    LR.freq[LR.bests.first] = L.freq[LR.bests.first] + R.freq[LR.bests.first];
    LR.freq[LR.bests.second] = L.freq[LR.bests.second] + R.freq[LR.bests.second]; 
    return LR;
}
void build(int l = 0, int r = n - 1, int idx = 0) {
    if(l == r) {
        seg[idx].bests.first = elements[l]; seg[idx].bests.second = 0;
        seg[idx].freq[elements[l]]++;
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*idx+1);
    build(mid+1, r, 2*idx+2);
    seg[idx] = join(seg[2*idx+1], seg[2*idx+2]);
}
