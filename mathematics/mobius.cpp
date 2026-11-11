const int MAXN = 1e6 + 5;

vector<int> mu(MAXN, 0);
bitset<MAXN> comp;
vector<ll> primes;

// Inclusão Exclusão sobre os primos

void mobius() {
    mu[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        if(!comp[i]) {
            primes.push_back(i), mu[i] = -1;
        }
        for(int p : primes) {
            if(i * p >= MAXN) {
                break;
            }
            comp[i * p] = 1;
            if(i % p == 0) {
                mu[i * p] = 0;
                break;
            }
            mu[i * p] = -mu[i];
        }
    }
}
