ll vals[N];
int tin[N], tout[N];
vector<vector<int>> adj(N);
int timer = 0;

void euler(int node, int prev) {
    tin[node] = timer++;
    for(int v : adj[node]) {
        if(v != prev) {
            euler(v, node);
        }
    }
    tout[node] = timer;
}

bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
