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

// Encontrando ciclo em grafo funcional

vector<int> nxt;
vector<int> state;
vector<int> pos;
vector<int> path;
vector<bool> ciclo;
 
void dfs(int v) {
    state[v] = 1;
    pos[v] = path.size();
    path.push_back(v);
 
    int u = nxt[v];
    if(state[u] == 0) {
        dfs(u);
    } else if(state[u] == 1) {
        for(int i = pos[u]; i < path.size(); i++) {
            ciclo[path[i]] = true;
        }
    }
    path.pop_back();
    state[v] = 2;
}
