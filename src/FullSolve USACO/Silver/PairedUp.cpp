#include <bits/stdc++.h>

#define ll long long
using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Data{
    int t; int x;
};

bool cmp(const Data& x, const Data& y){
    return x.x < y.x;
}

int main(){
    setIO("pairup");
    int n;
    cin >> n;
    vector<Data> v;

    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        int x; cin >> x;
        v.push_back({t,x});

    }
    sort(begin(v),end(v),cmp);

    int ans = -1;
    int left(0), right(v.size()-1);

    while(left <= right){
        int max_pair(min(v[left].t,v[right].t));

        if(left == right){
            max_pair = v[left].t/2;
            ans = max(v[left].x + v[right].x,ans);
            break;
        }

        v[left].t-= max_pair; v[right].t-= max_pair;

        ans = max(v[left].x + v[right].x,ans);

        if(v[left].t == 0){
            left++;
        }

        if(v[right].t == 0){
            right--;
        }
    }
    cout << ans;
}