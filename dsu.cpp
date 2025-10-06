#include <bits/stdc++.h>

using namespace std;

class DSU {
    private: 
        vector<int> parents;
        vector<int> sizes;
    public:
        DSU(int size) {
            parents.resize(size); sizes.resize(size, 1);
            for(int i = 0; i < size; i++) {
                parents[i] = i;
            }
        }
        
        int find(int x) {
            if(parents[x] == x) {
                return x;
            } else {
                return parents[x] = find(parents[x]);
            }
        }

        bool union_(int x, int y) {
            int xr = find(x);
            int yr = find(y);
            if(xr == yr) { return false; }

            if(sizes[xr] < sizes[yr]) {
                swap(xr, yr); 
            }
            sizes[xr] += sizes[yr];
            parents[yr] = xr;
            return true;
        }

        bool connected(int x, int y) {
            return find(x) == find(y);
        }
};