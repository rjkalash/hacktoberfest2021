/* Link to the questoin: https://codeforces.com/1572/problem/E */
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
// CHECK_OVERFLOW64 = true can run up to 2 times slower (particularly on CF).
const bool CHECK_OVERFLOW64 = false;
 
using dist_t = long double;
 
struct point {
    int64_t x, y;
 
    point() : x(0), y(0) {}
 
    point(int64_t _x, int64_t _y) : x(_x), y(_y) {}
 
    point& operator+=(const point &other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point &other) { x -= other.x; y -= other.y; return *this; }
    point& operator*=(int64_t mult) { x *= mult; y *= mult; return *this; }
 
    point operator+(const point &other) const { return point(*this) += other; }
    point operator-(const point &other) const { return point(*this) -= other; }
    point operator*(int64_t mult) const { return point(*this) *= mult; }
 
    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }
 
    point operator-() const { return point(-x, -y); }
    point rotate90() const { return point(-y, x); }
 
    int64_t norm() const {
        return (int64_t) x * x + (int64_t) y * y;
    }
 
    dist_t dist() const {
        return sqrt(dist_t(norm()));
    }
 
    bool top_half() const {
        return y > 0 || (y == 0 && x > 0);
    }
 
    friend ostream& operator<<(ostream &os, const point &p) {
        return os << '(' << p.x << ", " << p.y << ')';
    }
};
 
int64_t cross(const point &a, const point &b) {
    return (int64_t) a.x * b.y - (int64_t) b.x * a.y;
}
 
int64_t dot(const point &a, const point &b) {
    return (int64_t) a.x * b.x + (int64_t) a.y * b.y;
}
 
int cross_sign(const point &a, const point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;
 
        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1;
    }
 
    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;
    int64_t actual = int64_t(uint64_value);
    return (actual > 0) - (actual < 0);
}
 
bool left_turn_strict(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) > 0;
}
 
bool left_turn_lenient(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) >= 0;
}
 
bool collinear(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) == 0;
}
 
// Returns twice the signed area formed by three points in a triangle. Positive when a -> b -> c is a left turn.
int64_t area_signed_2x(const point &a, const point &b, const point &c) {
    return cross(b - a, c - a);
}
 
dist_t distance_to_line(const point &p, const point &a, const point &b) {
    assert(a != b);
    return dist_t(abs(area_signed_2x(p, a, b))) / (a - b).dist();
}
 
int64_t manhattan_dist(const point &a, const point &b) {
    return (int64_t) abs(a.x - b.x) + abs(a.y - b.y);
}
 
int64_t infinity_norm_dist(const point &a, const point &b) {
    return max(abs(a.x - b.x), abs(a.y - b.y));
}
 
// Sort in increasing order of y, with ties broken in increasing order of x.
bool yx_compare(const point &a, const point &b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
}
 
// Sort in increasing order of angle to the x-axis.
bool angle_compare(const point &a, const point &b) {
    if (a.top_half() ^ b.top_half())
        return a.top_half();
 
    return cross_sign(a, b) > 0;
}
 
 
struct dp_value {
    int regions = 0;
    int64_t extra = 0;
 
    dp_value() {}
 
    dp_value(int _regions, int64_t _extra) : regions(_regions), extra(_extra) {}
 
    dp_value& operator+=(const dp_value &other) { regions += other.regions; extra += other.extra; return *this; }
    dp_value operator+(const dp_value &other) const { return dp_value(*this) += other; }
 
    bool operator<(const dp_value &other) const {
        return regions != other.regions ? regions < other.regions : extra < other.extra;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif
 
    int N, K;
    cin >> N >> K;
    vector<point> P(N);
 
    for (point &p : P)
        cin >> p.x >> p.y;
 
    auto possible = [&](int64_t cutoff) -> bool {
        auto simplify = [&](dp_value value) -> dp_value {
            return value.extra >= cutoff ? dp_value(value.regions + 1, 0) : value;
        };
 
        vector<vector<dp_value>> dp(N, vector<dp_value>(N));
 
        for (int i = N - 1; i >= 0; i--)
            for (int j = i + 2; j < N; j++)
                for (int k = i + 1; k < j; k++) {
                    dp_value option = dp[i][k] + dp[k][j];
                    option.extra += area_signed_2x(P[i], P[k], P[j]);
                    option = simplify(option);
                    dp[i][j] = max(dp[i][j], option);
                }
 
        return dp[0][N - 1].regions >= K + 1;
    };
 
    int64_t poly_area = 0;
 
    for (int i = 0; i < N; i++)
        poly_area += P[i].x * P[(i + 1) % N].y - P[i].y * P[(i + 1) % N].x;
 
    int64_t low = 0, high = poly_area;
 
    while (low < high) {
        int64_t mid = low + (high - low + 1) / 2;
 
        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }
 
    cout << low << '\n';
}
