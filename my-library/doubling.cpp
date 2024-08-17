#include <bits/stdc++.h>
using namespace std;

vector<int> doubling(const vector<int>& graph, const long long k) {
  int n = graph.size();
  vector<vector<int>> doubling(60, vector<int>(n));
  
  for (int v = 0; v < n; v++) {
    doubling.at(0).at(v) = graph.at(v);
  }
  
  for (int i = 1; i < 60; ++i) for (int v = 0; v < n; v++) {
    doubling.at(i).at(v) = doubling.at(i-1).at(doubling.at(i-1).at(v));
  }
  
  vector<int> result(n);
  for (int v = 0; v < n; v++) {
    int current = v;
    for (int i = 0; i < 60; i++) {
      if (k & (1LL << i)) {
        current = doubling.at(i).at(current);
      }
    }
    result.at(v) = current;
  }
  
  return result;
}
