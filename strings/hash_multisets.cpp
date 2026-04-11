mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r) {
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    map<ll, pair<ll, ll>> mp;
    vector<ll> A(n), B(n);
    vector<pair<ll, ll>> prefA(n+1, {0, 0}), prefB(n+1, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(!mp.count(A[i])) {
            mp[A[i]] = {uniform(1, 1e18), uniform(1, 1e18)};
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> B[i];
        if(!mp.count(B[i])) {
            mp[B[i]] = {uniform(1, 1e18), uniform(1, 1e18)};
        }
    }
    for(int i = 1; i <= n; i++) {
        prefA[i].first = prefA[i-1].first + mp[A[i-1]].first;
        prefB[i].first = prefB[i-1].first + mp[B[i-1]].first;
        prefA[i].second = prefA[i-1].second + mp[A[i-1]].second;
        prefB[i].second = prefB[i-1].second + mp[B[i-1]].second;
    }
    for(int i = 0; i < q; i++) {
        int l, r, L, R; cin >> l >> r >> L >> R;
        pair<ll, ll> val1 = {prefA[r].first - prefA[l-1].first, prefA[r].second - prefA[l-1].second};
        pair<ll, ll> val2 = {prefB[R].first - prefB[L-1].first, prefB[R].second - prefB[L-1].second};
        if(val1 == val2) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    return 0;
}
