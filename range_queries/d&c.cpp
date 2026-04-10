// Exemplo de Divide and Conquer com queries de mínimos
vector<int> nums;
vector<int> ans;

struct Query {
    int l, r, idx;
};

void dnc(int l, int r, vector<Query>& queries) {
    if(l > r || queries.empty()) {
        return;
    }
    int m = (l+r)/2;
    vector<Query> left, right, cur;
    for(Query q : queries) {
        if(q.l <= m && m <= q.r) {
            cur.push_back(q);
        } else if(q.r < m) {
            left.push_back(q);
        } else {
            right.push_back(q);
        }
    }
    dnc(l, m - 1, left);
    dnc(m + 1, r, right);
    vector<int> suf = {nums[m]}, pref = {nums[m]};
    for(int i = m - 1; i >= l; i--) {
        suf.push_back(min(nums[i], suf.back()));
    }
    for(int i = m + 1; i <= r; i++) {
        pref.push_back(min(nums[i], pref.back()));
    }
    for(Query q : cur) {
        ans[q.idx] = min(suf[m - q.l], pref[q.r - m]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<Query> queries;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--; r--;
        queries.push_back({l, r, i});       
    }
    ans.resize(q);
    dnc(0, n-1, queries);
    for(int x : ans) {
        cout << x << "\n";
    }
    return 0;
}
