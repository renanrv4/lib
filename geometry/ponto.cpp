const double EPS = 1e-9;

int cmp(double a, double b) {
    if (fabs(a - b) < EPS) {
        return 0;
    }
    if(a < b) {
        return -1;
    }
    return 1;
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point(const Point& p): x(p.x), y(p.y) {}
    
    bool operator < (const Point& p) const {
        if(cmp(x, p.x) != 0) {
            return x < p.x;
        }
        return cmp(y, p.y) < 0;
    }
    bool operator == (const Point& p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
    bool operator != (const Point& p) const { return !(p == *this); }

    Point operator + (const Point& p) const { return Point(x+p.x, y+p.y); }
    Point operator - (const Point& p) const { return Point(x-p.x, y-p.y); }
    Point operator * (const double k) const { return Point(x*k, y*k); }
    Point operator / (const double k) const { return Point(x/k, y/k); }
};
