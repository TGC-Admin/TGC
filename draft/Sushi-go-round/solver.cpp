#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

signed main() {
    int n; cin >> n;
    vector<int> inv(n);
    REP(i, n) {
        int p; cin >> p;
        inv[--p] = i;
    }

    int prv = -1, ans = 0;
    REP(i, n) {
        int nxt = inv[i];
        if(nxt < prv) ++ans;
        prv = nxt;
    }

    cout << ans << "\n";
}
