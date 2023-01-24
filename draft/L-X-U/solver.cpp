#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

signed main() {
    int n; cin >> n;
    string s; cin >> s;

    int l_max = INT32_MIN, r_min = INT32_MAX;

    REP(i, n) {
        int a; cin >> a;
        if(s[i] == 'L') l_max = max(l_max, a);
        if(s[i] == 'U') r_min = min(r_min, a);
    }

    cout << max(0, r_min - l_max + 1) << "\n";
}
