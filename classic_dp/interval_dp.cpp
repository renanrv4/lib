#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;

int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> balls(n);
    for(int i = 0; i < n; i++) {
        cin >> balls[i];
    }
    // init dp
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    // intervals should be independent
    for(int len = 2; len <= n; len++) {
        for(int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = 1 + dp[l+1][r]; // base case where the ball is just removed and the interval is summed up
            for(int mid = l+1; mid <= r; mid++) {
                if(balls[l] != balls[mid]) {
                    continue;
                }
                dp[l][r] = min(dp[l][r], dp[l+1][mid-1] + dp[mid+1][r]); // calculate the cost trying to make two balls of the same color collide using intervals between
                // b | c i p c | b | a t q
                // l = 0, r = 5, len = 6
                // trying to make two b's collide for example  
            }
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}
