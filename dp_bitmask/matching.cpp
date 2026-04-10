const int MOD = 1e9 + 7;

int n;
int matches[21][21];
ll dp[1<<21];

void tsp_iter() {
    if (n == 1) {
        cout << matches[0][0] << "\n";
        return;
    }
    dp[0] = 1;
    for(int mask = 0; mask < (1<<n); mask++) {
        int i = __builtin_popcount(mask);
        if(i >= n) {
            continue;
        }
        for(int j = 0; j < n; j++) {
            if(mask & (1<<j)) {
                continue;
            }
            if(matches[i][j] == 0) {
                continue;
            }
            dp[mask ^ (1<<j)] += dp[mask] % MOD;
        }
    }
    cout << dp[(1<<n)-1] % MOD << "\n";
}
