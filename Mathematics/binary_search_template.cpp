template<typename T, typename U>
int less_than_or_equal_to(T val, const vector<U> &a) {
    int n = a.size();
    int l = -1, r = n, mid;
    while (r > l + 1) {
        mid = (l + r) / 2;
        if (a[mid] <= val) l = mid;
        else r = mid;
    }
    return l;
}

template<typename T, typename U>
int less_than(T val, const vector<U> &a) {
    int n = a.size();
    int l = -1, r = n, mid;
    while (r > l + 1) {
        mid = (l + r) / 2;
        if (a[mid] < val) l = mid;
        else r = mid;
    }
    return l;
}

template<typename T, typename U>
int greater_than_or_equal_to(T val, const vector<U> &a) {
    int n = a.size();
    int l = -1, r = n, mid;
    while (r > l + 1) {
        mid = (l + r) / 2;
        if (a[mid] < val) l = mid;
        else r = mid;
    }
    return r;
}

template<typename T, typename U>
int greater_than(T val, const vector<U> &a) {
    int n = a.size();
    int l = -1, r = n, mid;
    while (r > l + 1) {
        mid = (l + r) / 2;
        if (a[mid] <= val) l = mid;
        else r = mid;
    }
    return r;
}
