int n;
int costs[10][10];
int dp[1<<10][10];

void tsp_iter() {    
    const int inf = 2e9;
    for(int mask = 0; mask < (1<<n); mask++) {
        for(int i = 0; i < n; i++) {
            dp[mask][i] = inf;
        }
    }
    dp[1][0] = 0;
    for(int mask = 1; mask < (1<<n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) { // visitando
                for(int j = 0; j < n; j++) {
                    if(mask & (1<<j)) { // já visitado
                        continue;
                    }
                    // atualiza o custo mínimo para o estado
                    dp[mask ^ (1<<j)][j] = min(dp[mask ^ (1<<j)][j], dp[mask][i] + costs[i][j]);
                }
            }
        }
    }
    int best = inf;
    for(int i = 1; i < n; i++) {
        best = min(best, dp[(1<<n) - 1][i] + costs[i][0]);
    }
    cout << best << "\n";
}
