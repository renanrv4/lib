int n;
static const ll P1 = 31;
static const ll P2 = 37;
static const ll M1 = 1e9 + 33;
static const ll M2 = 1e9 + 93;

vector<ll> pref1, pref2;
vector<ll> pref1rv, pref2rv;

void Hasher(const string& s) {
    int n = s.size();
    pref1.assign(n+1, 0); pref2.assign(n+1, 0);
    for(int i = 0; i < n; i++) {
        ll val = s[i]-'a'+1;
        pref1[i+1] = (pref1[i]*P1+val)%M1;
        pref2[i+1] = (pref2[i]*P2+val)%M2;
    }
}
void Hasherrv(const string& s) {
    int n = s.size();
    pref1rv.assign(n+1, 0); pref2rv.assign(n+1, 0);
    for(int i = 0; i < n; i++) {
        ll val = s[i]-'a'+1;
        pref1rv[i+1] = (pref1rv[i]*P1+val)%M1;
        pref2rv[i+1] = (pref2rv[i]*P2+val)%M2;
    }
}

// Vetores de potência
vector<ll> pot1(n+1), pot2(n+1);
pot1[0] = pot2[0] = 1;
for(int i = 1; i <= n; i++) {
    pot1[i] = (pot1[i-1] * P1) % M1;
    pot2[i] = (pot2[i-1] * P2) % M2;
}

pair<ll, ll> substr_hash(int i, int j, vector<ll>& prefix1, vector<ll>& prefix2, vector<ll>& pot1, vector<ll>& pot2) {
    int len = j - i + 1;
    ll h1 = (((prefix1[j+1] - (prefix1[i] * pot1[len]) % M1) % M1) + M1) % M1;
    ll h2 = (((prefix2[j+1] - (prefix2[i] * pot2[len]) % M2) % M2) + M2) % M2;
    return {h1, h2};
}
