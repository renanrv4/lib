int t = 17;
vector<int> a = {3, 4, 7, 2};
vector<bool> dp(t+1, false);
dp[0] = true;
for(auto x : a) {
    for(int i = t - x; i >= 0; i--) {
        if(dp[i]) {
            dp[i + x] = true;
        }
    }
}
if(dp[t]) {
    cout << "Sim" << "\n";
} else {
    cout << "Não" << "\n";
}
