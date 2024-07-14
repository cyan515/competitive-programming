#include <bits/stdc++.h>
using namespace std;

// 座標圧縮
class coordinate_compression {
public:
  coordinate_compression(const vector<long long>& data) {
    _sorted = data;
    sort(_sorted.begin(),_sorted.end());
    _sorted.erase(unique(_sorted.begin(),_sorted.end()),_sorted.end());
  }
  
  /**
   * @fn
   * 受け取った値を座標圧縮した場合いくつになるかを返す。
   * 計算量 O(logN)
   * 
   * @param val 圧縮前の値
   */
  long long compress(const long long& val) const {
    long long ret = lower_bound(_sorted.begin(),_sorted.end(),val) - _sorted.begin();
    return ret;
  }
  
private:
  vector<long long> _sorted;
};
