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

    for(int i=0; i<t; i++){
        ll int k,x; cin >> k >> x;
        if(k * k <= x){
            cout << 2 * k - 1 << endl;
            continue;
        }
        ll int low(1),high(2*k-1);
        ll int mid(-1);
        ll int ans(-1);
        while(low <= high){
            mid = (low + high) / 2;
            ll int total(0);
            if(mid > k){
                total += k * k - (2*k-mid-1)*(2*k-mid)/2;
            }else{
                total += mid * (mid + 1)/2;
            }

            if(total >= x){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        cout << ans << endl;

    }
}