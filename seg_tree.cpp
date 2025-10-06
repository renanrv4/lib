#include <bits/stdc++.h>

using namespace std;

// Variáveis de inicialização
const int N = 1e5;
int n;
int t[2*N];

// Constrói a árvore usando os filhos que estão no range de n até 2n
void build() {
    for(int i = n - 1; i > 0; --i) { t[i] = t[i<<1] + t[i<<1|1]; }
}

// Modifica o valor da posição p para value e atualiza o resto da árvore
void modify(int p, int value) {
    p += n;
    for(t[p] = value; p > 1; p >>= 1) {
        t[p>>1] = t[p] + t[p^1];
    }
}

// Calcula o valor da soma que contém todos os elementos de l até r
int query(int l, int r) {
    int res = 0;
    l += n;
    r += n;
    for(l, r; l < r; l >>= 1, r >>= 1) {
        if(l&1) {
            res += t[l++];
        }
        if(r&1) {
            res += t[--r];
        }
    }
    return res;
}
