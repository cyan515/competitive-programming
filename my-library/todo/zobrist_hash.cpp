#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void zobrist_hash(int n, vector<ll>& a) {

  map<int, ll> table;
  mt19937_64 rng(time(0));
  uniform_int_distribution<ll> dist(1, (1LL << 60) - 1);
  
  for (int ele : a) {
    table[ele] = dist(rng);
  }

  vector<ll> hashA(1, 0);
  set<int> setA;
  for (int ele : a) {
    if (setA.find(ele) != setA.end()) {
      hashA.push_back(hashA.back());
    } else {
      setA.insert(ele);
      hashA.push_back(hashA.back() ^ table[ele]);
    }
  }
}