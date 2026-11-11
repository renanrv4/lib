const int MAXN = 1e6 + 5;

vector<ll> phi(MAXN);

void calc_tot() {
    for(int i = 0; i < MAXN; i++) {
        phi[i] = i; // considera que todos os valores n são do tipo gcd(n, i) = 1
    }
    for(int i = 2; i < MAXN; i++) {
        if(phi[i] == i) {
            for(int j = i; j < MAXN; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

/*

Informações uteis:
totiente é multiplicativo, ent totient de n é: tot(p1) * tot(p2) * tot(p3) * ...
p1, p2, p3 sendo primos
como p1, p2, p3 são primos, o tot de p1 ^ k, é dado a p1 ^ k - p1 ^ k -1, já que 
são os únicos valores <= a p^k que não são coprimos dele

O somatório da função phi de euler para todos os divisores de um n, é o proprio n

*/
