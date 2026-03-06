#include <bits/stdc++.h>

using namespace std;

#define ll long long

// =====================================
// Aritmética Modular
// =====================================

const int MOD = 1e9 + 7;

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

// =====================================
// Fatorial e Inverso Fatorial
// =====================================

#define MAX_K 1005

ll fact[MAX_K], invfact[MAX_K];

void precompute() {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < MAX_K; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

ll binomial(ll n, ll k) {
    if(k > n || k < 0) {
        return 0;
    }
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

// =====================================
// Definindo matrizes
// =====================================

#define MAX_N 2

const int MOD = 1e9 + 7;

struct Matriz
{
    ll mat[MAX_N][MAX_N];
};

Matriz matMul(Matriz a, Matriz b) {
    Matriz ans; int i, j, k;
    for(i = 0; i < MAX_N; i++) {
        for(j = 0; j < MAX_N; j++) {
            for(ans.mat[i][j] = k = 0; k < MAX_N; k++) {
                ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD;
                ans.mat[i][j] = ans.mat[i][j] % MOD;
            }
        }
    }
    return ans;
}

Matriz matPow(Matriz base, ll p) {
    Matriz ans; int i, j;
    for(i = 0; i < MAX_N; i++) {
        for(j = 0; j < MAX_N; j++) {
            ans.mat[i][j] = (i == j);
        }
    }
    while(p) {
        if(p & 1) {
            ans = matMul(ans, base);
        }
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

// =====================================
// Como usar matrizes na main?
// =====================================

Matriz ans;
Matriz ans_final;
ans = matPow(a, n-2);
ans_final = matMul(ans, b);

// =====================================
// Crivo e Crivo segmentado
// =====================================

#define ll long long

ll sieve_size;
bitset<1000001> bs;
vector<ll> primes;

void sieve(ll upperbound) {
    sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= sieve_size; i++) {
        if(bs[i]) {
            for(ll j = i * i; j <= sieve_size; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

ll segmented_sieve(ll L, ll R) {
    vector<bool> isPrime(R - L + 1, true);
    for(ll i : primes) {
        for(ll j = max(i * i, (L + i - 1)/i*i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }
    if (L == 1) {
        isPrime[0] = false;
    }
    for(int i = 0; i < isPrime.size(); i++) {
        if(isPrime[i]) {
            return L + i;
        }
    }
    return -1;
}

// =====================================
// Número de divisores e divisor máximo
// =====================================

int getDivs(int n) {
    vector<int> divs;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(i != n/i) {
                divs.push_back(n/i);
            }
        }
    }
    return divs.size();
}

ll maxDiv(ll n) {
    ll maxd = 1;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            maxd = max(maxd, max(i, n/i));
        }
    }
    return maxd;
}
