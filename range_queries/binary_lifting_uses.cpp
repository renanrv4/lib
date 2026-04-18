// LCA
const int MAXN = 2e5 + 5;
int n, LOG;
vector<vector<int>> adj(MAXN);

int timer = 0;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> depth(MAXN);

void dfs(int v, int prev) {
    tin[v] = ++timer;
    if(v != prev) {
        depth[v] = depth[prev] + 1;
    }
    up[v][0] = prev;
    for(int i = 1; i <= LOG; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u : adj[v]) {
        if(u != prev) {
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void preprocess(int root) {
    tin.resize(n); tout.resize(n);
    timer = 0;
    LOG = ceil(log2(n));
    up.assign(n, vector<int>(LOG+1));
    depth[root] = 0;
    dfs(root, root);
}

int lca(int u, int v) {
    if(ancestor(u, v)) {
        return u;
    } else if(ancestor(v, u)) {
        return v;
    }
    for(int i = LOG; i >= 0; i--) {
        if(!ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

// K steps
int n;
const int LOG = 31;
const int MAXN = 2e5 + 5;

int up[LOG][MAXN];
void bin_lift() {
    for(int i = 1; i < LOG; i++) {
        for(int j = 0; j < n; j++) {
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }
}

int kSteps(int v, int k) {
    for(int i = 0; i < LOG; i++) {
        if(k & (1LL << i)) {
            v = up[i][v];
        }
    }
    return v;
}
