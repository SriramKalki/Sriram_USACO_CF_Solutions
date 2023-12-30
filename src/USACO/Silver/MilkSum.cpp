#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    int n,q;
    cin >> n;
    ll int ord[n],pos[n];
    ll int arr[n],pref[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    iota(ord,ord+n,0);
    sort(ord,ord+n, [&](int i , int j){
        return arr[i] < arr[j];
    });

    for(int i=0; i<n; i++){
        pos[ord[i]] = i;
    }

    sort(arr,arr+n);
    pref[0] = 0;
    ll int T = 0;
    for(int i=0; i<n; i++){
        pref[i+1] = pref[i] + arr[i];
        T += (i + 1) * arr[i];
    }

    cin >> q;
    for(int i=0; i<q; i++){
        ll ans = T;
        int idx;
        ll int val;
        cin >> idx >> val; idx--;
        idx = pos[idx];
        //updated index to refer to sorted array
        int newidx = lower_bound(arr, arr + n, val) - arr - (bool) (val > arr[idx]);
        ans -= (idx + 1) * arr[idx];
        if (newidx >= idx) 
        {
            ans -= (pref[newidx + 1] - pref[idx + 1]);
        }
        else 
        {
            ans += (pref[idx] - pref[newidx]);
        }
        ans += (newidx + 1) * val;
        cout << ans << '\n';
    }

}