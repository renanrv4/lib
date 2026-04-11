#define ll long long

struct Node {
    array<Node*, 26> nxt;
    int terminal = 0;
    int pref = 0; 
    Node() { nxt.fill(NULL); }
};

struct Trie {
	Node* root;
	Trie(){ root = new Node(); }
	
	void add(string &s){
		Node* t = root;
		for(auto c : s){
            c -= 'a';
			if(!t->nxt[c]) {
				t->nxt[c] = new Node();
            }
			t = t->nxt[c];
            t->pref++;
		}
		t->terminal++;
	}

	int count(string &s){
		Node* t = root;
		for(auto c : s){ c -= 'a';
			if(!t->nxt[c]) {
                return 0;
            }
            t = t->nxt[c];
		}
		return t->terminal;
	}

    int pref_count(string &s) {
        Node* t = root;
        for(auto c : s) {
            c -= 'a';
            if(!t->nxt[c]) {
                return 0;
            }
            t = t->nxt[c];
        }
        return t->pref;
    }
};
