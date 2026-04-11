vector<Point> convexHull(vector<Point>& points, bool sorted = false) {
    int n = points.size();
    if(!sorted) {
        sort(points.begin(), points.end());
    }
    vector<Point> lower(n+1), upper(n+1);
    int s = 0;
    for(int i = 0; i < n; i++) {
        lower[s++] = points[i];
        while(s >= 3) {
            Point a = lower[s-3], b = lower[s-2], c = lower[s-1];
            Point v1 = b-a, v2 = c-b;
            if(cross(v1, v2) >= 0) {
                break;
            }
            lower[s-2] = lower[s-1];
            s--;
        }
    }
    lower.resize(s);
    s = 0;
    for(int i = 0; i < n; i++) {
        upper[s++] = points[i];
        while(s >= 3) {
            Point a = upper[s-3], b = upper[s-2], c = upper[s-1];
            Point v1 = b-a, v2 = c-b;
            if(cross(v1, v2) <= 0) {
                break;
            }
            upper[s-2] = upper[s-1];
            s--;
        }
    }
    upper.resize(s-1);
    reverse(upper.begin(), upper.end());
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}
