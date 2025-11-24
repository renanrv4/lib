vector<vector<ll>> C(51, vector<ll>(51));
for(int i = 0; i < 51; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
}
for(int i = 1; i < 51; i++) {
    for(int j = 1; j < i; j++) {
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

// Gerar coeficientes binomiais com DP