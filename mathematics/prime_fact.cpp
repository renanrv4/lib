#define ll long long

vector<pair<ll, int>> prime_factors(ll num) {
    vector<pair<ll, int>> factors;
    for(ll i = 2; i * i <= num; i++) {
        int count = 0;
        while(num % i == 0) {
            num /= i;
            count++;
        }
        if(count > 0) {
            factors.push_back({i, count});
        }
    }
    if(num > 1) {
        factors.push_back({num, 1});
    }
    return factors;
}

vector<ll> prime_factors(ll num) {
    vector<ll> factors;
    ll pf_idx = 0, pf = primes[pf_idx];
    while(pf * pf <= num) {
        while(num % pf == 0) {
            num /= pf;
            factors.push_back(pf);
        }
        pf_idx++;
        pf = primes[pf_idx];
    }
    if(num != 1) {
        factors.push_back(num);
    }
    return factors;
}

// Usar o Crivo de Eratóstenes para obter os primos necessários
