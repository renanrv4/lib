struct Node {
    ll open, close, pairs;
};
Node make_node(char c) {
    Node nd;
    nd.open = 0, nd.close = 0, nd.pairs = 0;
    if(c == '(') {
        nd.open = 1;
    } else if(c == ')') {
        nd.close = 1;
    }
    return nd;
}

Node join(Node L, Node R) {
    Node LR;
    int pairs_now = min(L.open, R.close);
    LR.open = L.open + R.open - pairs_now;
    LR.close = L.close + R.close - pairs_now;
    LR.pairs = L.pairs + R.pairs + pairs_now;
    return LR;
}
