vector<int> Pi(string& t) {
    vector<int> p(t.size(), 0);
    for(int i = 1, j = 0; i < t.size(); i++) {
        while(j > 0 && t[j] != t[i]) {
            j = p[j-1];
        }
        if(t[j] == t[i]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}
