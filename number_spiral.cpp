#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;
        long long m = max(a, b);
        long long comp = (m * m) - m + 1;
 
        if(m % 2 == 0 && a > b) {
            comp = comp + (m - b);
        } else if(m % 2 == 0 && a < b) {
            comp = comp - (m - a);
        } else if(m % 2 == 1 and a > b) {
            comp = comp - (m - b);
        } else if(m % 2 == 1 and a < b) {
            comp = comp + (m - a);
        }
        cout << comp << "\n";
    }
    return 0;
}
