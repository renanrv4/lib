// Estrutura Básica de um Sweep line
bool comp(pair<int, int> inter1, pair<int, int> inter2) {
    if(inter1.second < inter2.second) {
        return true;
    }
    return false;
}

vector<pair<int, int>> intervals(n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), comp);
    int endnow = -1;
    int count = 0;
    for(auto [st, end] : intervals) {
        if(st >= endnow) {
            count++;
            endnow = end;
        }
    }
    cout << count << "\n";

//Estrutura de um Sweep Line com compressão de coordenadas
vector<pair<int, int>> intervals(n, {0, 0});
vector<int> times;
for(int i = 0; i < n; i++) {
    cin >> intervals[i].first >> intervals[i].second;
    times.push_back(intervals[i].first);
    times.push_back(intervals[i].second);
}
sort(times.begin(), times.end());
times.erase(unique(times.begin(), times.end()), times.end());

vector<int> cont(times.size()+1, 0);
vector<int> ps(times.size()+1, 0);
for(auto it : intervals) {
    int st = lower_bound(times.begin(), times.end(), it.first) - times.begin();
    int end = lower_bound(times.begin(), times.end(), it.second) - times.begin();
    cont[st]++; cont[end]--;
}