#include <bits/stdc++.h>
using namespace std;

/**
 * @fn
 * k = 0,1,...,n について nCk を計算して返す。
 * ret[i][j] = iCj の値。
 * 計算量 O(N^2)
 * @param n 総数
 * @param mod 法
 */
vector<vector<long long>> comb(const int& n, const int& mod) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k])%mod;
    }
  }
  return v;
}
