mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r) {
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n; cin >> n;
    map<ll, ll> mp;
    set<ll> sA, sB;
    vector<ll> A(n), B(n);
    vector<ll> prefA(n+1, 0), prefB(n+1, 0);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(!mp.count(A[i])) {
            mp[A[i]] = uniform(1, 1e18);
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i];
        if(!mp.count(B[i])) {
            mp[B[i]] = uniform(1, 1e18);
        }
    }
    for(int i = 1; i <= n; i++) {
        prefA[i] = prefA[i-1];
        if(!sA.count(A[i-1])) {
            prefA[i] ^= mp[A[i-1]];
            sA.insert(A[i-1]);
        }
        prefB[i] = prefB[i-1];
        if(!sB.count(B[i-1])) {
            prefB[i] ^= mp[B[i-1]];
            sB.insert(B[i-1]);
        }
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if(prefA[a] == prefB[b]) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    return 0;
}
