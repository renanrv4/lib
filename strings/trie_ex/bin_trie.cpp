#define ll long long
#define BITS 32

struct Node {
    array<Node*, 2> nxt;
    ll val;
    Node() { nxt.fill(NULL); val = 0; }
};

struct Trie {
	Node* root;
	Trie(){ root = new Node(); }
	
	void add(ll pref_v){
		Node* t = root;
        for(int i = BITS-1; i >= 0; i--) {
            bool bit = pref_v & (1<<i);
            if(t->nxt[bit] == NULL) {
                t->nxt[bit] = new Node();
            }
            t = t->nxt[bit];
        }
        t->val = pref_v;
	}

    ll query(ll num) {
        Node* t = root;
        for(int i  = BITS-1; i >= 0; i--) {
            bool bit = num & (1<<i);
            if(t->nxt[1-bit] != NULL) {
                t = t->nxt[1-bit];
            } else if(t->nxt[bit] != NULL){
                t = t->nxt[bit];
            }
        }
        return num^(t->val);
    }
};
