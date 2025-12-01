#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<int> ans;
    ans.push_back(vec[0]);
    for(int i = 1; i < n; i++) {
        if(vec[i] > ans.back()) {
            ans.push_back(vec[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(), vec[i]) - ans.begin();
            ans[low] = vec[i];
        }
    }
    cout << ans.size() << "\n";
    return 0;
}