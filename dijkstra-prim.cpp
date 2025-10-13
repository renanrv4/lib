void dijkstra(vector<vector<pair<int, int>>>& graph ,int s) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    
    vector<bool> marked(graph.size(), false);
    vector<int> distances(graph.size(), INT_MAX);
    vector<int> parents(graph.size(), -1);

    // Para prim: heap.push(make_tuple(0, 0, 0)); distances[s] = 0;
    heap.push(make_tuple(0, s, s)); distances[s] = 0;
    for(int i = 0; i < graph.size(); i++) {
        if(heap.empty()) { break; }
        int p = -1, v = -1;
        do {
            p = get<2>(heap.top());
            v = get<1>(heap.top()); heap.pop();
            if(!marked[v]) { break; }
        } while(!heap.empty());
        
        if(v == -1) { break; }
        marked[v] = true; parents[v] = p;

        for(auto [w, weight] : graph[v]) {
            if(marked[w] != true && distances[w] > distances[v] + weight) { // Para prim: distances[w] = weight; 
                distances[w] = distances[v] + weight; // Para prim: distances[w] = weight; 
                heap.push(make_tuple(distances[w], w, v));
            }
            
        }
    }
}
