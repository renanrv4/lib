#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define i128 __int128_t

// Usando i128 pra evitar overflow no lcm
i128 lcmgcd(ll a, ll b) {
    return (i128)a/gcd(a, b) * b;
}
// Dps checa se o lcm é maior que 1e18 e decide o que fazer (ignora ou outra coisa)

// -----------------------------------------------

// Cuidado com re-hashing do map e unordered_map
// Usar .reserve

// -----------------------------------------------

// Estratégia de random shuffle para algoritmos randomizados

void random_shuffle(vector<int>& vec, int n) {
    for(int i = 0; i < n; i++) {
        int j = rand() % (i+1);
        swap(vec[i], vec[j]);
    }
}
