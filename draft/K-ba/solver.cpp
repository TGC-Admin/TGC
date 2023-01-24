#include <bits/stdc++.h>
using namespace std;

#include <atcoder/fenwicktree>

#define REP(i,n) for(int i=0, i##_length=int(n); i<i##_length; ++i)

using ll = long long;

namespace Lib {

template<class T> struct Compression : vector<int> {
  protected:
    vector<T> values;

  public:
    Compression() {}
    template<class I> Compression(const I first, const I last) {
        this->values.assign(first, last);
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        this->resize(distance(first, last));
        for(auto itr=begin(*this),val=values.begin(),e=first; e!=last; ++itr,++val,++e) {
            *itr = distance(values.begin(), lower_bound(values.begin(), values.end(), *e));
        }
    }
    inline T operator()(const int val) const {
        return values[val];
    }
};

} // namespace Lib

signed main() {
    int k, t; cin >> k >> t;
    vector<ll> d(k), v(k);

    REP(i, k) cin >> d[i];
    REP(i, k-1) {
        int r; cin >> r;
        v[i+1] = v[i] + r;
    }

    vector<ll> s(k);
    REP(i, k) s[i] = d[i] - t*v[i];

    Lib::Compression<ll> comp_s(s.begin(), s.end());
    atcoder::fenwick_tree<int> bit(k+1);

    int ans = 0;
    REP(i, k) {
        ans += i - bit.sum(0, comp_s[i]+1);
        bit.add(comp_s[i], 1);
    }

    cout << ans << "\n";
}
