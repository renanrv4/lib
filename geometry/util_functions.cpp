double dot(const Point& p, const Point& q) { return p.x*q.x + p.y*q.y; }
double cross(const Point& p, const Point& q) { return p.x*q.y - p.y*q.x; }
double norm(const Point& p) { return hypot(p.x, p.y); }
double dist(const Point& p, const Point& q) { return hypot(p.x-q.x, p.y-q.y); }
double dist2(const Point& p, const Point& q) { return dot(p-q, p-q); }
Point normalize(const Point& p) { return p/hypot(p.x, p.y); }
double angle(const Point& p, Point& q) { return atan2(cross(p, q), dot(p, q)); }
double angle(const Point& p) { return atan2(p.y, p.x); }

// Perpendicular ao ponto p
Point perp(const Point& p) {
    return Point(-p.y, p.x); // 90 graus
}
