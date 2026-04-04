#define ll long long

struct BIT {
    ll n;
    vector<ll> bit;

    BIT(ll N) {
        n = N;
        bit.assign(n+1, 0);
    }

    ll query(ll x) {
        ll res = 0;
        while(x > 0) {
            res += bit[x];
            x -= (x & -x);
        }
        return res;
    }
    void update(ll x, ll val) {
        while(x <= n) {
            bit[x] += val;
            x += (x & -x);
        }
    }

    // Encontrar o K-ésimo elemento com BIT de frequência
    int findKth(int k) {
        int l = 1, r = n;
        int pos = 0;
        while(l <= r) {
            int mid = (l+r)/2;
            if(query(mid) >= k) {
                pos = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return pos;
    }
};

// Compressão de Coordenadas
vector<ll> nums(n, 0);
BIT bit(n);
for(int i = 0; i < n; i++) {
    cin >> nums[i];
}
vector<ll> coord_compr = nums;
sort(coord_compr.begin(), coord_compr.end());
for(int i = 0; i < n; i++) {
    nums[i] = lower_bound(coord_compr.begin(), coord_compr.end(), nums[i]) - coord_compr.begin() + 1;
}

// Contar Inversões
ll qtd_invs = 0;
for(int i = n -1; i >= 0; i--) {
    qtd_invs += bit.query(crossings[i]);
    bit.update(crossings[i], 1); 
}
cout << qtd_invs << "\n";
