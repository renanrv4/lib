// Ray casting algorithm
bool isInside(vector<Point>& polygon, Point p) {
    int count = 0;
    for(int i = 0, j = polygon.size() - 1; i < polygon.size(); j = i++) {
        if(((polygon[i].y > p.y) != (polygon[j].y > p.y)) && 
            (p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / 
            (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            count++;
        }
    }
    return count % 2 != 0;
}

// Complexidade: O(N)
