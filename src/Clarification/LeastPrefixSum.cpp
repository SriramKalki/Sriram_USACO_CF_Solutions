#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,m;
        cin >> n >> m;
        m--; //ONE INDEX

        ll int a[n];
        ll int psum[n];

        cin >> a[0];
        psum[0] = a[0];

        ll int greatest(0);

        for(int i=1; i<n; i++){
            cin >> a[i];
            if(a[i] >= a[greatest]){
                greatest = i;
            }
            psum[i] = psum[i-1] + a[i];
        }

        priority_queue<ll int> first;
        for(ll int i = greatest + 1; i <= m; i++){
            first.push(a[i]);
        }



        ll int swaps(0);




        cout << swaps << endl;

    }
}