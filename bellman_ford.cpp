#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<pair<int, int>>> wormholes(n, vector<pair<int, int>>());
        for(int i = 0; i < m; i++) {
            int x, y, t; cin >> x >> y >> t;
            wormholes[x].push_back({y, t});
        }
        vector<int> dist(n, INT_MAX); dist[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                for (int j = 0; j < (int)wormholes[u].size(); j++) {
                    auto v = wormholes[u][j];
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
                }
            }
        }
        // Checando por ciclos negativos
        bool hasNegativeCycle = false;
        for (int u = 0; u < n; u++) {
            for (int j = 0; j < (int)wormholes[u].size(); j++) {
                auto v = wormholes[u][j];
                if (dist[v.first] > dist[u] + v.second) {
                    hasNegativeCycle = true;
                }
            }
        }
        if(hasNegativeCycle) {
            cout << "possible" << "\n";
        } else {
            cout << "not possible" << "\n";
        }
    }
    return 0;
}