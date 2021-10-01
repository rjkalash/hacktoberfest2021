/*
 * Inclusion tests. Returns
 * -1 if the point is strictly inside the polygon;
 * 0 if the point is on the boundary;
 * 1 if the point is outside the polygon.
 */
template <class F1, class F2>
int pointVsTriangle(const Point<F1>& point, const Polygon<F2>& triangle) {
    assert(triangle.size() == 3);
    int signs[3];
    for (int i = 0; i < 3; ++i)
        signs[i] = sgn(ccw(point, triangle[next(i, 3)], triangle[i]));
    if (signs[0] == signs[1] && signs[1] == signs[2]) return -1;
    for (int i = 0; i < 3; ++i) if (signs[i] * signs[next(i, 3)] == -1) return 1;
    return 0;
}

template <class F1, class F2>
int pointVsConvexPolygon(const Point<F1>& point, const Polygon<F2>& poly, int top) {
    if (point < poly[0] || point > poly[top]) return 1;
    auto orientation = ccw(point, poly[top], poly[0]);
    if (orientation == 0) {
        if (point == poly[0] || point == poly[top]) return 0;
        return top == 1 || top + 1 == poly.size() ? 0 : -1;
    } else if (orientation < 0) {
        auto itRight = lower_bound(begin(poly) + 1, begin(poly) + top, point);
        return sgn(ccw(itRight[0], point, itRight[-1]));
    } else {
        auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
        return sgn(ccw(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
    }
}

template <class F1, class F2>
int pointVsPolygon(const Point<F1>& point, const Polygon<F2>& poly) {
    int n = static_cast<int>(poly.size()), windingNumber = 0;
    for (int i = 0; i < n; ++i) {
        if (point == poly[i]) return 0;
        int j = next(i, n);
        if (poly[i].y == point.y && poly[j].y == point.y) {
            if (min(poly[i].x, poly[j].x) <= point.x &&
                point.x <= max(poly[i].x, poly[j].x)) return 0;
        } else {
            bool below = poly[i].y < point.y;
            if (below != (poly[j].y < point.y)) {
                auto orientation = ccw(point, poly[j], poly[i]);
                if (orientation == 0) return 0;
                if (below == (orientation > 0)) windingNumber += below ? 1 : -1;
            }
        }
    }
    return windingNumber == 0 ? 1 : -1;
}
