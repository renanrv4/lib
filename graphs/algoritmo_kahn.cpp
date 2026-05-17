// Ordenação Topológica

stack<int> toposort;
bool cycle = false;

void DFS(vector<vector<int>>& adj, vector<bool>& mark, int v, vector<bool>& seen) {
    mark[v] = true;
    seen[v] = true;
    for(int i : adj[v]) {
        if(mark[i] == false) {
            DFS(adj, mark, i, seen);
        } else if(seen[i]) {
            cycle = true;
        }
    }
    seen[v] = false;
    toposort.push(v);
}

// Kahn Toposort

vector<int> deg(26, 0);
bool cycle = false;
string new_abc;
string abc = "abcdefghijklmnopqrstuvwxyz";

void BFS(vector<vector<int>>& adj) {
    queue<int> queue_visit;
    for(int i = 0; i < 26; i++) {
        if(deg[i] == 0) {
            queue_visit.push(i);
        }
    }
    while(!queue_visit.empty()) {
        int v = queue_visit.front(); queue_visit.pop();
        new_abc += abc[v];
        for(int i : adj[v]) {
            deg[i]--;
            if(deg[i] == 0) {
                queue_visit.push(i);
            }
        }
    }
}
