#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef __int128_t i128;

i128 pow_mod(i128 x, i128 n, i128 m) {
    i128 y = 1;
    while (n > 0) {
        if (n % 2 == 1) y = (y * x) % m;
        n = n / 2;
        x = (x * x) % m;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true) {
        string s;
        cin>>s;
        if (s == ".") break;
        int n = s.length();
        i128 p = 997, m = 61589783609796811;
        vector<i128> pre(n + 1), ps(n);
        ps[0] = 1;
        for (int i = 1; i < n; i++) ps[i] = (ps[i - 1] * p) % m;
        for (int i = 0; i < n; i++) pre[i + 1] = (pre[i] + (ps[i] * (i128)(s[i] - 'a' + 1)) % m) % m;
        for (int l = 1; l <= n; l++) {
            if (n % l) continue;
            i128 v = pre[l];
            i128 parts = n / l, t = ps[l];
            i128 numerator = (pow_mod(t, parts, m) + m - 1) % m;
            i128 denominator = pow_mod((t + m - 1) % m, m - 2, m);
            i128 geom_sum = (((numerator * denominator) % m) * v) % m;
            if (geom_sum == pre[n]) {
                cout << n / l << "\n";
                break;
            }
        }
    }
    return 0;
}   