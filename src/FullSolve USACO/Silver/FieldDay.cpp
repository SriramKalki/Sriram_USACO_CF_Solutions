#include<bits/stdc++.h>

#define ll long long
using namespace std;




int main(){
    int n,t;
    cin >> n >> t;

    vector<string> a(t);
    for(int i=0; i<t; i++) cin >> a[i];

    vector<ll int> bitmask(t);
    for(int i=0; i<t; i++) {
        //conv to binary
        ll int res (0);
        for(int j=0; j<a[i].length(); j++){
            char curr = a[i][j];
            res = (curr == 'G') ? (res << 1) | 1 : (res << 1) | 0;
        }
        bitmask[i] = res;
    }

    for(int i=0; i<t; i++){
        int diff = 0;

        for(int j =0; j<t; j++){
            if(i == j) continue;
            diff = max(diff, __builtin_popcount(bitmask[i]^bitmask[j]));
        }

        cout << diff << endl;
    }
}