#include <bits/stdc++.h>
using namespace std;

signed main() {
    int q; cin >> q;

    int n = 40;

    for(;q--;) {
        char t; cin >> t;
        int x; cin >> x;
        if(t == '+') n += x;
        if(t == '-') n -= x;
        if(n <= 0 or n >= 100) n = 40;
    }

    cout << n << "\n";
}
