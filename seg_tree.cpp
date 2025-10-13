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

//Lógica para contar a frequência durante o intervalo
pair<long long, int> combine(pair<long long, int> a, pair<long long, int> b) {
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    return {a.first, a.second + b.second};
}

void update(vector<pair<long long, int>>& base, int i, int val, int n) {
    i += n;
    base[i] = {val, 1};
    for (int j = i; j > 1; j /= 2) {
        base[j/2] = combine(base[j], base[j ^ 1]);
    }
}

pair<long long, int> query(vector<pair<long long, int>>& base, int a, int b, int n) {
    int l = a + n;
    int r = b + n;
    pair<long long, int> resp = {1e18, 0};
    
    for (; l < r; l /= 2, r /= 2) {
        if (l % 2 == 1) {
            resp = combine(resp, base[l++]);
        }
        if (r % 2 == 1) {
            resp = combine(resp, base[--r]);
        }
    }
    return resp;
}
