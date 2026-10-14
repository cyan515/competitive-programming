#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 階乗の事前計算
  vector<mint> fact(n + 1, 1);
  for(int i = 1; i <= n; i++){
    fact[i] = fact[i - 1] * i;
  }

  mint ans = 0;

  if (n <= 20) {
    rep(bit, 1 << n) {
      ll s = 0;
      rep(i, n) {
        if ((bit & (1 << i)) != 0) s += a[i];
      }
      if (s < x) continue;

      mint cnt = 0;
      rep(i, n) {
        if ((bit & (1 << i)) != 0) {
          if (s - a[i] < x) cnt++;
        }
      }

      if (cnt.val() == 0) continue;

      ll d = __builtin_popcount(bit);
      
      // その集合と「最後の一回」が特定の組み合わせになる確率
      mint prob = fact[d - 1] * fact[n - d] / fact[n];
      
      // 合計金額 × 条件を満たす最後の要素の候補数 × その発生確率
      ans += prob * cnt * s;
    }
  }

  cout << ans.val() << endl;

  return 0;
}