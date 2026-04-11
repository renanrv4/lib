int qtd_patterns(vector<int>& seq, vector<int>& org) {
    vector<int> p = Pi(seq);
    int qtd = 0;
    for(int i = 0, j = 0; i < org.size(); i++) {
        while(j > 0 && org[i] != seq[j]) {
            j = p[j-1];
        }
        if(org[i] == seq[j]) {
            j++;
        }
        if(j == seq.size()) {
            qtd++; j = p[j-1];
        }
    }
    return qtd;
}
