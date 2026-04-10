const int MOD = 1e9 + 7;

ll mod_add(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}

ll mod_sub(ll a, ll b) {
    return ((a % MOD - b % MOD) + MOD) % MOD;
}

ll mod_mul(ll a, ll b) {
    return (a % MOD * b % MOD) % MOD;
}

ll fexp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b&1) {
            res = mod_mul(res, a);
        }
        a = mod_mul(a, a);
        b>>=1;
    }
    return res%MOD;
}

ll inv(ll a) {
    return fexp(a, MOD-2);
}
