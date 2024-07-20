#include <bits/stdc++.h>
using namespace std;

/**
 * @fn
 * ret[i][c] = s の i 文字目以降で最初に文字 c が登場する index となる二次元配列を返す。
 * 計算量 O(N)
 * 
 * @param s 文字列
 * @param base 基準となる文字。英大文字なら 'A' を、数字なら '0' を渡すなど。
 * @see https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
 */
vector<vector<int>> calc_next(const string& s, const char& base = 'a') {
  int n = s.size();
  vector<vector<int>> res(n+1,vector<int>(26,n));
  for(int i=n-1;i>=0;i--) {
    for(int j=0;j<26;j++) res.at(i).at(j) = res.at(i+1).at(j);
    res.at(i).at(s.at(i)-base) = i;
  }
  return res;
}
