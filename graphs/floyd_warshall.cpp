const int n = 300 + 10;
vector<vector<ll>> dist(n+1, vector<ll>(n+1));

for(int k = 1; k <= n; k++) {
    for(int u = 1; u <= n; u++) {
        for(int v = 1; v <= n; v++) {
            if(dist[u][k] != LLONG_MAX && dist[k][v] != LLONG_MAX) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
}