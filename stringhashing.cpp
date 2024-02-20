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
    string s;
    cin>>s;
    int q, n;
    cin>>q;
    n = s.length();
    vector<i128> pre(n + 1), ps(n);
    i128 p = 997, m = 61589783609796811;
    ps[0] = 1;
    for (int i = 1; i < n; i++) ps[i] = (ps[i - 1] * p) % m;
    for (int i = 0; i < n; i++) pre[i + 1] = (pre[i] + (ps[i] * (i128)(s[i] - 'a' + 1)) % m) % m;
    while (q--) {
        int l,r;
        cin>>l>>r;
        i128 v = pre[r] - pre[l];
        while (v < 0) v += m;
        v = (v * pow_mod(ps[l], m - 2, m)) % m;
        cout << (ll)v << "\n";
    }
    return 0;
}