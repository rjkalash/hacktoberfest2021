//Used for intersecting any combination of rays, segments or lines
template <int TYPE> struct EndpointChecker {};
template <> struct EndpointChecker<0> {  // no endpoint (ray)
    template <class F> bool operator ()(const F& a, const F& b) const { return true; }};
template <> struct EndpointChecker<1> {  // closed endpoint
    template <class F> bool operator ()(const F& a, const F& b) const { return a <= b; }};
template <> struct EndpointChecker<2> {  // open endpoint
    template <class F> bool operator ()(const F& a, const F& b) const { return a < b; }};

//Call this to intersect any of the above combinations
template <int LA, int LB, int RA, int RB, class F1, class F2, class F3>
bool intersectLines(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
    assert(lhs && rhs);//Makes sure that they don't reduce to points
    auto s = lhs.ab ^ rhs.ab;
    if (s == 0) return false;//If they are parallel
    auto ls = (rhs.a - lhs.a) ^ rhs.ab;
    auto rs = (rhs.a - lhs.a) ^ lhs.ab;
    if (s < 0) s = -s, ls = -ls, rs = -rs;
    bool intersect = EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) &&
                    EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
    if (intersect) res = lhs.a + lhs.ab * static_cast<F3>(ls) / s;
    return intersect;
}

//Call this if segments are guaranteed not to coincide
template <class F1, class F2, class F3>
bool intersectClosedSegments(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
    return intersectLines<1, 1, 1, 1>(lhs, rhs, res);
}

//Handles the case when segments can coincide
template <class F1, class F2, class F3>
bool intersectSegments(const Line<F1>& lhs, const Line<F2>& rhs, Line<F3>& res) {
    auto s = lhs.ab ^ rhs.ab;
    auto ls = (rhs.a - lhs.a) ^ rhs.ab;
    if (s == 0) {
        if (ls != 0) return false;
        auto lhsa = lhs.a, lhsb = lhs.b();
        auto rhsa = rhs.a, rhsb = rhs.b();
        if (lhsa > lhsb) swap(lhsa, lhsb);
        if (rhsa > rhsb) swap(rhsa, rhsb);
        res = Line<F3>(max(lhsa, rhsa), min(lhsb, rhsb));
        return res.ab >= Point<F3>();
    }
    auto rs = (rhs.a - lhs.a) ^ lhs.ab;
    if (s < 0) s = -s, ls = -ls, rs = -rs;
    //This can also be achieved by Endpoint checker but since here we are guaranteed
    //that segments are closed so we can check directly
    bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
    if (intersect)
        res = Line<F3>(lhs.a + lhs.ab * static_cast<F3>(ls) / s, Point<F3>());
    return intersect;
}
