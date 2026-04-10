ll score(string s, string t, int n, int m, vector<vector<ll>>& dp, ll a, ll b, ll c) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == 0) {
                dp[0][j] = j * a;
            } else if(j == 0) {
                dp[i][0] = i * b;
            } else if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                ll option1 = dp[i-1][j-1] + c;
                ll option2 = dp[i-1][j] + b;
                ll option3 = dp[i][j-1] + a;
                dp[i][j] = min({option1, option2, option3});
            }
        }
    }
    return dp[n][m];
}
