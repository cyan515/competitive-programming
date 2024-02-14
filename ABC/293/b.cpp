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
    int n;cin>>n;
    vector<int> a(n);
    set<int> called;
    vector<int> ans;
    for(int i=0;i<n;i++) {
        cin>>a.at(i);
        a.at(i)--;
    }

    for(int i=0;i<n;i++) {
        if(called.find(i)==called.end()) called.insert(a.at(i));
    }

    for(int i=0;i<n;i++) {
        if(called.find(i)==called.end()) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++) {
        cout << ans.at(i)+1;
        if(i==ans.size()-1) cout << endl;
        else cout << " ";
    }

    exit(0);
}
