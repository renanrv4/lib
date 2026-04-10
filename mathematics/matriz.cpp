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
Matriz a, b;
a.mat[0][0] = 1, a.mat[0][1] = 1, a.mat[1][0] = 1, a.mat[1][1] = 0;
b.mat[0][0] = valb, b.mat[1][0] = vala;
Matriz ans;
Matriz ans_final;
ans = matPow(a, n-2);
ans_final = matMul(ans, b);
