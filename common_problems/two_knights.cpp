#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int k; cin >> k;
    for(long long i = 1; i <= k; i++) {
        long long res = ((i * i * (i * i - 1)) / 2) - (4 * (i-1) * (i - 2));
        cout << res << "\n";
    }
    return 0;
}
