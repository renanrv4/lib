// PS 2D
const int MAXN = 505;
int ps[MAXN][MAXN];

void calc_ps2d() {
    for(int i = 1; i < MAXN; i++) { ps[0][i] += ps[0][i-1]; }
    for(int i = 1; i < MAXN; i++) { ps[i][0] += ps[i-1][0]; }

    for(int i = 1; i < MAXN; i++) {
        for(int j = 1; j < MAXN; j++) {
            ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }
}

int query_ps2d(int xi, int yi, int xf, int yf) {
    return ps[xf][yf] - ps[xf][yi-1] - ps[xi-1][yf] + ps[xi-1][yi-1];
}
