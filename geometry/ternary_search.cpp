int l = 0, r = n-1;
while(r - l > 5) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    double resm1 = costWestEast(west, east, lens, distOAi, m1, j);
    double resm2 = costWestEast(west, east, lens, distOAi, m2, j);
    if(resm1 < resm2) {
        r = m2 - 1;
    } else {
        l = m1 + 1;
    }
}
