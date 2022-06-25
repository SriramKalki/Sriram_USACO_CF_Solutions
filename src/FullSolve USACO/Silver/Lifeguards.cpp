#include <bits/stdc++.h>

using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main(){
    setIO("lifeguards");
    int n;
    cin >> n;
    vector<array<int,2>> x;
    x.push_back({0,0});

    for(int i=0; i<n; i++){
        int l,r;
        cin >> l >> r;
        x.push_back({l,r});
    }

    x.push_back({1000000000,1000000000});

    sort(x.begin(),x.end());
    int l_end,r_end,tot(0),l_far(-1),mn(1000000000);
    for(int i=1; i<= n; i++){
        l_end = max(x[i-1][1],x[i][0]);
        r_end = min(x[i+1][0],x[i][1]);
        l_far = max(l_far, l_end);
        mn = min(mn,max(0,r_end-l_end));
        tot += max(0,x[i][1] - l_far);
    }
    cout << tot - mn << endl;
}