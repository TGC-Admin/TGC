#include <bits/stdc++.h>
using namespace std;

signed main() {
    char s0, s1, s2; cin >> s0 >> s1 >> s2;
    long long k; cin >> k;

    int invs = 0;
    if(s0 > s1) ++invs;
    if(s0 > s2) ++invs;
    if(s1 > s2) ++invs;

    cout << (set({s0, s1, s2}).size() == 3 and invs <= k and invs%2 == k%2 ? "Yes" : "No") << "\n";
}
