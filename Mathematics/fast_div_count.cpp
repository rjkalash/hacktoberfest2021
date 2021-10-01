const int N = 1000000;
int lp[N+1];
vector<int> pr, cnt;

void computePrimes() {
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void div_count() {
    computePrimes();
    cnt.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        int ans = 1, n = i;
        for(int p: pr) {
            long long pi = p;
            if (pi * pi * pi > n) {
                break;
            }
            int c = 1;
            while (n % p == 0) {
                n /= p;
                c++;
            }
            ans *= c;
        }
        int x = sqrt(n);
        if (lp[n] == n) ans *= 2;
        else if (lp[x] == x && x * x == n) ans *= 3;
        else if (n != 1) ans *= 4;
        cnt[i] = ans;
    }
}
