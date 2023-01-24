#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;

    int ans = 0;
    for(;n--;) {
        int a; cin >> a;
        ans += a % 3 != 0;
    }

    cout << ans << "\n";
}
