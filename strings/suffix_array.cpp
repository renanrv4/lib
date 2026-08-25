/*

Suffix Array -
Construction O(N log N)

Uses:

1- Finding the smallest cyclic shift
2- Finding a substring in a string
3- Comparing two substrings of a string
4- Longest common prefix of two substrings with additional memory
5- Longest common prefix of two substrings without additional memory (Kasai)
6- Number of different substrings

*/

const int INF = 1e9;

vector<int> lcp_array;

vector<int> suffixArray(vector<int> s) {
    s.push_back(-INF); // se s for string então: int n = (s += "!").size();
    int n = s.size();
    vector<int> sf(n), ord(n), aux(n), cnt(n);
    iota(begin(sf), end(sf), 0);
    sort(begin(sf), end(sf), [&](int i, int j) { return s[i] < s[j]; });

    int cur = ord[sf[0]] = 0;
    for(int i = 1; i < n; i++) {
        ord[sf[i]] = s[sf[i]] == s[sf[i-1]] ? cur : ++cur;
    }
    for(int k = 1; cur+1 < n && k < n; k <<= 1) {
        cnt.assign(n, 0);
        for(auto &i : sf) {
            i = (i - k + n) % n, cnt[ord[i]]++;
        }
        for(int i = 1; i < n; i++) {
            cnt[i] += cnt[i-1];
        }
        for(int i = n-1; i >= 0; i--) {
            aux[--cnt[ord[sf[i]]]] = sf[i];
        }
        sf.swap(aux);
        aux[sf[0]] = cur = 0;
        for(int i = 1; i < n; i++) {
            aux[sf[i]] = ord[sf[i]] == ord[sf[i-1]] && ord[(sf[i]+k) % n] == ord[(sf[i-1]+k) % n] ? cur : ++cur;
        }
        ord.swap(aux);
    }
    return vector<int>(begin(sf)+1, end(sf));
}

// LCP Kasai algorithm
vector<int> LCP(vector<int>& s, vector<int>& sf) {
    int n = s.size();
    vector<int> lcp(n), pof(n);
    for(int i = 0; i < n; i++) {
        pof[sf[i]] = i; 
    }
    for(int i = 0, j, k = 0; i < n; k ? --k : k, i++) {
        if(!pof[i]) {
            continue;
        }
        j = sf[pof[i]-1];
        while(i + k < n && j + k < n && s[i+k] == s[j+k]) {
            k++;
        }
        lcp[pof[i]] = k;
    }
    return lcp;
}
