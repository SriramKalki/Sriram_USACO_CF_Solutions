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
        int n,k;
        cin >> n >> k;
        int array[n];
        for(int j=0; j<n; j++){
            cin >> array[j];
        }
        sort(array, array + n);
        int ans(0);
        //n-2k with n-k
        for(int j=0; j<k; j++){
            ans += floor((double) array[n-2*k+j]/(double) array[n-k+j]);
        }
        for(int j=0; j < n - 2*k; j++){
            ans += array[j];
        }

        cout << ans << endl;



    }
}