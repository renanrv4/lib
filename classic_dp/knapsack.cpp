vector<ll> knapsack(W+1);
for(int i = 0; i < n; i++) {
    for(int k = W - w[i]; k >= 0; k--) {
        knapsack[k + w[i]] = max(knapsack[k + w[i]], knapsack[k] + v[i]);
    }
}
cout << knapsack[W] << "\n";
// Outro jeito de fazer knapsack:
vector<vector<ll>> dp(n+1, vector<ll>(w+1));
for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= w; j++) {
        if(i == 0 || j == 0) {
            dp[i][j] = 0;
        } else if(weights[i] <= j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
        } else {
            dp[i][j] = dp[i-1][j];
        }
    }
}
