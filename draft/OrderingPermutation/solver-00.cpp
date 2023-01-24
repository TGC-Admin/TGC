#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

signed main() {
    int n; cin >> n;
    vector<int> p(n), inv(n);
    REP(i, n) {
        cin >> p[i], --p[i];
        inv[p[i]] = i;
    }

    int ans = 0;
    REP(i, n) {
        if(p[i] == i) continue;
        swap(p[i], p[inv[i]]);
        swap(inv[p[i]], inv[p[inv[i]]]);
        ++ans;
    }

    cout << ans << "\n";
}
