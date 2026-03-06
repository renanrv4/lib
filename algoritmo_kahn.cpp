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

