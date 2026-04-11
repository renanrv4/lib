struct Node {
    array<Node*, 2> nxt;
    Node* parent;
    int terminal = 0;
    ll val = -1;
    int query_time = -1;
    Node() { nxt.fill(NULL); parent = NULL; }
};

int all_time = 0;

struct Trie {
    Node* root;
    Trie(){ root = new Node(); }
    
    void add(string &s, ll plus, ll modc){
        Node* t = root;
        for(auto c : s){
            int ind;
            if(c == 'R') {
                ind = 1;
            } else {
                ind = 0;
            }
            if(!t->nxt[ind]) {
                t->nxt[ind] = new Node();
            }
            t->nxt[ind]->parent = t;
            t = t->nxt[ind];
        }
        t->val = plus;
        t->terminal++;
        t->query_time = all_time;
    }
    ll last_parent(string &s, ll modc) {
        Node* t = root;
        ll lastp = t->val;
        ll best_color = -1;
        int best_time = -1;
        int best_pos = 0;
        int try_pos = 0;
        for(int i = 0; i < s.size(); i++){
            int ind = (s[i] == 'R');
            if(!t->nxt[ind]) {
                break;
            }
            t = t->nxt[ind];
            try_pos++;
            if(t->val != -1 && t->query_time > best_time){
                best_time = t->query_time;
                best_color = t->val;
                best_pos = try_pos;
            }
        }
        if(best_color == -1) {
            return -1;
        }
        ll color = best_color;
        for(int j = best_pos; j < s.size(); j++){
            if(s[j] == 'L') {
                color++;
            } else {
                color--;
            }
            color = (color % modc + modc) % modc;
        }
        return color;
    }
};
