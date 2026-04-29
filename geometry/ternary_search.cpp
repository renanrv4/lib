int l = 0, r = LIM;
while(r - l > 5) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    double resm1 = F(m1);
    double resm2 = F(m2);
    if(resm1 < resm2) {
        r = m2 - 1;
    } else {
        l = m1 + 1;
    }
}

// Outra forma de fazer busca ternária (maximizando a função também)

double l = 0, r = LIM;
for(int i = 0; i < 100; i++) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double res1 = F(m1);
    double res2 = F(m2);
    if(res1 < res2) {
        l = m1;
    } else {
        r = m2;
    }
}
double f = (l+r)/2;
double res = F(f);
