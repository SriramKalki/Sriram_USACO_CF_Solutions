#include <bits/stdc++.h>

using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Mountain{
    int left,right,height;
};

bool cmp(const Mountain& x, const Mountain& y){
    if(x.left == y.left){return x.right > y.right;}
    return x.left < y.left;
}
int main(){
    setIO("mountains");
    int n;
    cin >> n;
    vector<Mountain> v;
    for(int i=0; i<n; i++){
        int mp, height;
        cin >> mp >> height;
        v.push_back({mp-height,mp+height,height});

    }
    sort(begin(v), end(v), cmp);

    int answer =0;
    int maxPos = -1;
    for(int i=0; i<n; i++){
        if(maxPos < v[i].right){
            answer++;
        }
        maxPos = max(maxPos, v[i].right);
    }
    cout << answer;
}