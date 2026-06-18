// Exemplo de questão em que a atualização ocorre em ambos os lados
// ******* USANDO DUAS SEGS PARA PROPAGAR DIREITA E ESQUERDA COM BASE NA CONTRIBUIÇÃO ********

// Nesse exemplo cada valor posto contribuía com um fator de iluminação, sua contribuição para cada posição é dada por: bright * (factor ^ |x - i|) | x sendo a posição da lampâda e i sendo a posição atual
// Como a ideia é fazer um somatório de contribuições, podemos multiplicar o fator r^x no final
// Ou seja os nós de cada seg guardam r^-i ou r^i, indicando sua contribuição.

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// TAMBÉM DÁ PRA FAZER COM DUAS BITS
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
#define ll long long

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

// =========================
// VERSÃO COM DUAS SEGS
// =========================

int n;
const int N = 2e5 + 5;
ll segleft[4*N], segright[4*N];
vector<ll> powp, invpowp;

ll join(ll a, ll b) {
    return (a + b) % MOD;
}

ll query_left(int L, int R, int l = 0, int r = n - 1, int idx = 0) {
    if(R < l || L > r) {
        return 0;
    }
    if(L <= l && r <= R) {
        return segleft[idx];
    }
    int mid = (l+r)/2;
    return join(query_left(L, R, l, mid, 2*idx+1), query_left(L, R, mid+1, r, 2*idx+2));
}

ll query_right(int L, int R, int l = 0, int r = n - 1, int idx = 0) {
    if(R < l || L > r) {
        return 0;
    }
    if(L <= l && r <= R) {
        return segright[idx];
    }
    int mid = (l+r)/2;
    return join(query_right(L, R, l, mid, 2*idx+1), query_right(L, R, mid+1, r, 2*idx+2));
}

void update(int i, ll val, int l = 0, int r = n-1, int idx = 0) {
    if(l == r) {
        segleft[idx] = (segleft[idx] + mod_mul(val, invpowp[i])) % MOD;
        segright[idx] = (segright[idx] + mod_mul(val, powp[i])) % MOD;
        return;
    }
    int mid = (l+r)/2;
    if(i <= mid) {
        update(i, val, l, mid, 2*idx+1);
    } else {
        update(i, val, mid+1, r, 2*idx+2);
    }
    segleft[idx] = join(segleft[2*idx+1], segleft[2*idx+2]);
    segright[idx] = join(segright[2*idx+1], segright[2*idx+2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int q; double p; cin >> n >> q >> p;
    powp.resize(n+1); invpowp.resize(n+1);
    p *= 1000000;
    ll p_ll = llround(p);
    ll pdef = mod_mul(1000000 - p_ll, inv(1000000));
    ll pdef_inv = inv(pdef);
    powp[0] = 1; invpowp[0] = 1;
    for(int i = 1; i <= n; i++) {
        powp[i] = mod_mul(powp[i-1], pdef);
        invpowp[i] = mod_mul(invpowp[i-1], pdef_inv);
    }
    while(q--) {
        char op; cin >> op;
        if(op == '?') {
            int x; cin >> x; x--;
            ll left = query_left(0, x);
            ll right = query_right(x+1, n-1);
            ll ans = (mod_mul(powp[x], left) + mod_mul(invpowp[x], right)) % MOD;
            cout << ans << "\n";
        } else {
            ll b; int x; cin >> b >> x; x--;
            if(op == '-') {
                update(x, MOD - b);
            } else {
                update(x, b);
            }
        }
    }
    return 0;
}

// =====================
// VERSÃO COM DUAS BITS
// =====================

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, q; double p; cin >> n >> q >> p;
    vector<ll> powp(n+1), invpowp(n+1);
    BIT bitleft(n), bitright(n);
    p *= 1000000;
    ll p_ll = llround(p);
    ll pdef = mod_mul(1000000 - p_ll, inv(1000000));
    ll pdef_inv = inv(pdef);
    powp[0] = 1; invpowp[0] = 1;
    for(int i = 1; i <= n; i++) {
        powp[i] = mod_mul(powp[i-1], pdef);
        invpowp[i] = mod_mul(invpowp[i-1], pdef_inv);
    }
    while(q--) {
        char op; cin >> op;
        if(op == '?') {
            int x; cin >> x;
            ll sum_left = bitleft.query(x);
            ll sum_right = (bitright.query(n) - bitright.query(x) + MOD) % MOD;
            ll res = (mod_mul(powp[x], sum_left) + mod_mul(invpowp[x], sum_right)) % MOD;
            cout << res << "\n";
        } else {
            ll b; int x; cin >> b >> x;
            if(op == '-') {
                bitleft.update(x, mod_mul(MOD - b, invpowp[x]));
                bitright.update(x, mod_mul(MOD - b, powp[x]));
            } else {
                bitleft.update(x, mod_mul(b, invpowp[x]));
                bitright.update(x, mod_mul(b, powp[x]));
            }
        }
    }
    return 0;
}
