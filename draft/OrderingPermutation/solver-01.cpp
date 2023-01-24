#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

signed main() {
    int n; cin >> n;
    dsu uf(n);
    REP(i, n) {
        int p; cin >> p, --p;
        uf.merge(i, p);
    }

    auto groups = uf.groups();

    cout << accumulate(groups.begin(), groups.end(), 0, [](int acc, auto& group) { return acc + group.size() - 1; } ) << "\n";
}
