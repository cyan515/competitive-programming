#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main()
{
    string s;cin>>s;
    string ans = "";
    for(int i=0;i<s.length();i++) {
        if(i%2==0) {
            ans += s.at(i+1);
            ans += s.at(i);
        }
    }
    cout << ans << endl;

    exit(0);
}
