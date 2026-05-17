#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

bool vis[MAXN];
vector<int> ciclo;

int dfs(int atual, int anterior, vector<vector<int>>& adj) {
    if(vis[atual]) {
        return atual;
    }
    vis[atual] = true;
    for(int u : adj[atual]) {
        if(u == anterior) {
            continue;
        }
        int fim = dfs(u, atual, adj);
        if(fim == -2) {
            return -2;
        }
        if(fim != -1) {
            ciclo.push_back(atual);
            if(atual == fim) {
                return -2;
            } else {
                return fim;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0, adj);
    for(int i : ciclo) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}