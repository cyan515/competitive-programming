#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  ll l, n, m;
  cin >> l >> n >> m;
  vector<pair<ll, ll>> upper(n);
  vector<pair<ll, ll>> lower(m);
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    upper.at(i) = make_pair(a, b);
  }
  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    lower.at(i) = make_pair(a, b);
  }

  ll cnt = 0;
  ll i = -1;
  ll ri = 0;
  ll j = -1;
  ll rj = 0;
  while (1) {
    if (ri == rj) {
      if (ri == l) break;
      i++;
      j++;
      ri += upper.at(i).second;
      rj += lower.at(j).second;
      int uv = upper.at(i).first;
      int lv = lower.at(j).first;
      if (uv == lv) cnt += min(upper.at(i).second, lower.at(j).second);
    } else if (ri < rj) {
      i++;
      ri += upper.at(i).second;
      int uv = upper.at(i).first;
      int lv = lower.at(j).first;
      if (uv == lv)
        cnt += min(upper.at(i).second, rj - ri + upper.at(i).second);
    } else if (ri > rj) {
      j++;
      rj += lower.at(j).second;
      int uv = upper.at(i).first;
      int lv = lower.at(j).first;
      if (uv == lv)
        cnt += min(lower.at(j).second, ri - rj + lower.at(j).second);
    }
  }
  cout << cnt << endl;

  exit(0);
}
