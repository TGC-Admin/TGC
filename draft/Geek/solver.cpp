#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    int q; cin >> q;

    unordered_map<ll,int> states;

    for(;q--;) {
        int t; cin >> t;
        ll x; cin >> x;
        if(t == 1) {
            if(states.count(x)) continue;
            states[x] = 0;
        }
        if(t == 2) {
            if(not states.count(x)) continue;
            ++states[x];
        }
    }

    cout << accumulate(states.begin(), states.end(), 0, [](int a, auto& p) { return a + p.second;  }) << "\n";
}
