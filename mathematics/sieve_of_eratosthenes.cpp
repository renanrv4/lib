#define ll long long

ll sieve_size;
bitset<50001> bs;
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

// Crivo de Eratóstenes para obter primos