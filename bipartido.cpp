#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& marked, vector<int>& colors, int v) { 
    marked[v] = true;
    for (int u : adj[v]) {
        if (!marked[u]) {
            colors[u] = 1 - colors[v];
            if (!dfs(adj, marked, colors, u)) {
                return false;
            }
        } else if (colors[u] == colors[v]) {
            return false;
        }
    }
    return true;
}