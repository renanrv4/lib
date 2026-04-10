int i = n, j = m;
string res;
while(i > 0 && j > 0) {
    if(s[i-1] == t[j-1]) {
        res += s[i-1];
        i--; j--;
    } else {
        if(dp[i-1][j] >= dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
}
reverse(res.begin(), res.end());
cout << res << "\n";
