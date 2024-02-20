#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string pattern, text;
    while (getline(cin, pattern)) {
        getline(cin, text);
        if (pattern.length() > text.length()) {
            cout << "\n";
            continue;
        }
        ll p = 31, m = 1e9 + 7, pv = 0, v = 0;
        vector<ll> ps = {1};
        for (int i = 0; i < pattern.length() - 1; i++) ps.push_back((ps.back() * p) % m);
        reverse(ps.begin(), ps.end());
        for (int i = 0; i < pattern.length(); i++) pv = (pv + ps[i] * (ll)(pattern[i] - ' ')) % m;
        for (int i = 0; i < pattern.length(); i++) v = (v + ps[i] * (ll)(text[i] - ' ')) % m;
        vector<int> ans;
        if (v == pv) ans.push_back(0);
        for (int i = pattern.length(); i < text.length(); i++) {
            v = v - ((ll)(text[i - pattern.length()] - ' ') * ps[0]) % m;
            while (v < 0) v += m;
            v = (v * p) % m;
            v = (v + (ll)(text[i] - ' ')) % m;
            if (v == pv) ans.push_back(i - pattern.length() + 1);
        }
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}