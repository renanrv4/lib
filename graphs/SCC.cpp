#include <bits/stdc++.h>

using namespace std;

// Algoritmo de Kosaraju

vector<bool> visited;

vector<int> outdeg; // opcional

void dfs(int v, vector<vector<int>> const& adj, vector<int>& topo_sort) {
    visited[v] = true;
    for(auto u : adj[v]) {
        if(!visited[u]) {
            dfs(u, adj, topo_sort);
        }
    }
    topo_sort.push_back(v);
}


void scc(const vector<vector<int>>& adj, vector<vector<int>>& tree_components, vector<vector<int>>& components, vector<int>& comp_id) {
    int n = adj.size();
    components.clear(); tree_components.clear();
    vector<int> order;
    visited.assign(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, order);
        }
    }
    vector<vector<int>> adj_reverse(n);
    for(int v = 0; v < n; v++) {
        for(auto u : adj[v]) {
            adj_reverse[u].push_back(v);
        }
    }
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    
    vector<int> roots(n, 0); // dá o vértice raiz de um vértice da SCC ** opcional

    for(auto v : order) {
        if(!visited[v]) {
            vector<int> component;
            dfs(v, adj_reverse, component);
            components.push_back(component);
            // opcional: usar se o problema requisitar root
            int root = *component.begin();
            for(auto u : component) {
                roots[u] = root;
            }
        }
    }

    // opcional para identificar componentes com um id
    comp_id.assign(n, -1);
    for(int i = 0; i < components.size(); i++) {
        for(int v : components[i]) {
            comp_id[v] = i;
        }
    }

    // criando grafo condensado
    tree_components.assign(components.size(), {});
    
    // outdeg é opcional caso seja necessário percorrer os componentes novamente com dfs
    outdeg.assign(components.size(), 0);
    for(int v = 0; v < n; v++) {
        for(int u : adj[v]) {
            if (roots[v] != roots[u]) {
                tree_components[roots[v]].push_back(roots[u]);
            }
            /*
            if(comp_id[v] != comp_id[u]) {

                possível forma de criar SCC com comp_id: 
                (nesse caso v é o vértice de origem da aresta, mas isso depende do problema)
                tree_components[comp_id[v]].push_back({comp_id[u], v});
                tree_components[comp_id[u]].push_back({comp_id[v], v});
                outdeg[comp_id[v]]++;
            }
            */
        }
    }
}
