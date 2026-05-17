bool BFS(vector<vector<int>>& adj, vector<bool>& mark, int v, int v2) {
    queue<int> queue_visit;
    vector<int> predecessors(adj.size(), -1);
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
                predecessors[i] = v;
            }
            if(i == v2) {
                path.push(v2);
                while(v2 != vbegin) {
                    path.push(predecessors[v2]);
                    v2 = predecessors[v2];
                }
                while(path.size() > 0) {
                    if(path.size() == 1) {
                        cout << path.top() << "\n";
                    } else {
                        cout << path.top() << " ";
                    }
                    path.pop();
                }
                return true;
            }
        }
    }
    return false;
}
