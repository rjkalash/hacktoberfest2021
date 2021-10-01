template <class F>
struct AngleCompare {
    const Point<F> origin;
    const bool zero;

    explicit AngleCompare(const Point<F>& origin = Point<F>())
            : origin(origin), zero(origin == Point<F>()) {}

    template <class F1, class F2>
    bool operator () (const Point<F1>& lhs, const Point<F2>& rhs) const {
        return zero ? ccw(lhs, rhs) < 0 : ccw(lhs, rhs, origin) < 0;
    }
};

template <class Iterator, class F>
void sortByAngle(Iterator first, Iterator last, const Point<F>& origin) {
    first = partition(first, last, [&origin](const decltype(*first)& point) {
        return point == origin; });
    auto pivot = partition(first, last, [&origin](const decltype(*first)& point) {
        return point > origin; });
    AngleCompare<F> acmp(origin);
    sort(first, pivot, acmp);
    sort(pivot, last, acmp);
}
