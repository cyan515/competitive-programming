#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

bool isAtcoder(char c) {
  return c=='a'
    || c=='t'
    || c=='c'
    || c=='o'
    || c=='d'
    || c=='e'
    || c=='r';
}

int main() {
  string s,t;cin>>s>>t;
  map<char,int> sm;
  map<char,int> tm;

  int n = s.length();

  int sat = 0;
  int tat = 0;
  for(int i=0;i<n;i++) {
    if(s.at(i)!='@') sm[s.at(i)]++;
    else sat++;
    if(t.at(i)!='@') tm[t.at(i)]++;
    else tat++;
  }

  bool flg = true;
  for(char c='a';c<='z';c++) {
    
    if(sm[c]>tm[c]) {
      if(!isAtcoder(c)) flg = false;
      tat -= abs(sm[c]-tm[c]);
    } else if(sm[c]<tm[c]) {
      if(!isAtcoder(c)) flg = false;
      sat -= abs(sm[c]-tm[c]);
    }
    if(tat<0 || sat<0) flg = false;
  }

  if(flg) cout << "Yes";
  else cout << "No";
  cout << endl;


  exit(0);
}
