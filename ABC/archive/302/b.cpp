#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s.at(i);
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      vector<string> t(8, "");
      for(int k=0;k<5;k++) {
        if(i+k<h) t.at(0)+=s.at(i+k).at(j);//0
        if(i-k>=0) t.at(1)+=s.at(i-k).at(j);//1
        if(j+k<w) t.at(2)+=s.at(i).at(j+k);//2
        if(j-k>=0) t.at(3)+=s.at(i).at(j-k);//3
        if(i+k<h&&j+k<w) t.at(4)+=s.at(i+k).at(j+k);//4
        if(i+k<h&&j-k>=0) t.at(5)+=s.at(i+k).at(j-k);//5
        if(i-k>=0&&j+k<w) t.at(6)+=s.at(i-k).at(j+k);//6
        if(i-k>=0&&j-k>=0) t.at(7)+=s.at(i-k).at(j-k);//7
      }
      for(int k=0;k<8;k++) {
        if(t.at(k)=="snuke") {
          if(k==0) {
            for(int l=0;l<5;l++) cout << i+l+1 << " " << j+1 << endl;
          } else if(k==1) {
            for(int l=0;l<5;l++) cout << i-l+1 << " " << j+1 << endl;
          } else if(k==2) {
            for(int l=0;l<5;l++) cout << i+1 << " " << j+l+1 << endl;
          } else if(k==3) {
            for(int l=0;l<5;l++) cout << i+1 << " " << j-l+1 << endl;
          } else if(k==4) {
            for(int l=0;l<5;l++) cout << i+l+1 << " " << j+l+1 << endl;
          } else if(k==5) {
            for(int l=0;l<5;l++) cout << i+l+1 << " " << j-l+1 << endl;
          } else if(k==6) {
            for(int l=0;l<5;l++) cout << i-l+1 << " " << j+l+1 << endl;
          } else {
            for(int l=0;l<5;l++) cout << i-l+1 << " " << j-l+1 << endl;
          }

          exit(0);
        }
      }
    }
  }

  exit(0);
}
