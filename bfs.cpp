bool BFS(vector<vector<int>>& adj, vector<bool>& mark, int v, int v2) {
    queue<int> queue_visit;
    queue_visit.push(v);
    mark[v] = true;
    int vbegin = v;
    stack<int> path;
    while(queue_visit.size() > 0) {
        v = queue_visit.front(); queue_visit.pop();
        for(int i : adj[v]) {
            if(mark[i] == false) {
                mark[i] = true;
                queue_visit.push(i);
            }
        }
    }
    return false;
}

void graphTraverse(vector<vector<int>>& adj, int v, int v2) {
    vector<bool> mark(adj.size(), false);
    bool found = false;
    found = BFS(adj, mark, v, v2);
    if(!found) {
        cout << -1 << "\n";
    }
}
