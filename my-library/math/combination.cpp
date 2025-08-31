#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

// https://drken1215.hatenablog.com/entry/2018/06/08/210000
vector<mint> fac, finv, inv;

/// nCk 計算のための前計算処理
/// 計算量は O(n)
void init_comb(int n, int mod) {
  fac.resize(n);
  finv.resize(n);
  inv.resize(n);
  fac.at(0) = fac.at(1) = 1;
  finv.at(0) = finv.at(1) = 1;
  inv.at(1) = 1;
  for (int i = 2; i < n; i++) {
    fac.at(i) = fac.at(i-1) * i;
    inv.at(i) = mod - inv.at(mod%i) * (mod / i);
    finv.at(i) = finv.at(i-1) * inv.at(i);
  }
}

/// nCk を計算して返す。
/// 計算量は O(1)
mint comb(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac.at(n) * finv.at(k) * finv.at(n-k);
}

/// nHk を計算して返す。
/// 計算量は O(1)
mint hom(int n, int k) {
  return comb(n+k-1, k);
}
