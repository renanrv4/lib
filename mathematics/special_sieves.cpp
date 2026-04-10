const int LIM = 1e6;

// Soma de todos os divisores no intervalo de 1 até LIM
ll sumDivisors[LIM];
void sieve() {
    for(int i = 1; i < LIM; i++) {
        for(int j = i; j < LIM; j += i) {
            sumDivisors[j] += i;
        }
    }
}

// Quantidade de divisores de todos os números no intervalo de 1 até LIM
ll numDivisors[LIM];
ll sieve2() {
    for(int i = 1; i < LIM; i++) {
        for(int j = i; j < LIM; j += i) {
            numDivisors[j]++;
        }
    }
}
