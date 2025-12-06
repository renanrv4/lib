#include <bits/stdc++.h>

using namespace std;

void dp_top_down(int i, int j, vector<vector<int>>& dp, string s, string t) {
    for(int i = 0; i <= s.size(); i++) {
        for(int j = 0; j <= t.size(); j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    dp_top_down(n, m, dp, s, t);
    return 0;
}