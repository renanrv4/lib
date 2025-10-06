#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Fenwick {
    private:
        vector<int> ft;
    public:
        Fenwick(int n) { ft.resize(n+1, 0); }

        // RSQ(1, b)
        int range_sum_query(int b) {
            int sum = 0; for(; b; b -= (b & (-b))) {
                sum += ft[b];
            }
            return sum;
        }

        // RSQ(a, b)
        int range_sum_query(int a, int b) {
            return range_sum_query(b) - (a == 1 ? 0 : range_sum_query(a - 1));
        }

        // Ajusta o valor do elemento na posição k com v 
        void adjust(int k, int v) {
            for(; k < (int)ft.size(); k += (k & (-k))) { ft[k] += v; }
        }
};