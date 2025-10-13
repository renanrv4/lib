void DFS(vector<vector<int>>& adj, vector<bool>& mark, int v) {
    mark[v] = true;
    for(int i : adj[v]) {
        if(mark[i] == false) {
            DFS(adj, mark, i);
        }
    }
}

int graphTraverse(vector<vector<int>>& adj) {
    vector<bool> mark(adj.size(), false);
    int sub = 0;
    for(int i = 0; i < adj.size(); i++) {
        if(mark[i] == false) {
            DFS(adj, mark, i);
            sub++;
        }
    }
    return sub;
}
