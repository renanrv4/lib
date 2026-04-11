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

// Checar se o ponto está dentro do hull
bool isInside(const vector<Point>& hull, Point p) {
    int n = hull.size();
    Point v0 = p - hull[0], v1 = hull[1] - hull[0], v2 = hull[n-1] - hull[0];
    if(cross(v0, v1) > 0 || cross(v0, v2) < 0) {
        return false;
    }
    int l = 1, r = n-1;
    while(l != r) {
        int mid = (l + r + 1)/2;
        Point p0 = p - hull[0], p1 = hull[mid] - hull[0];
        if(cross(p0, p1) < 0) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    v0 = hull[(l+1)%n] - hull[l], v1 = p - hull[l];
    return cross(v0, v1) >= 0;
}
