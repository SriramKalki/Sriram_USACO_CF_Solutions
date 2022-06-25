#include <bits/stdc++.h>

using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main(){

    setIO("diamond");
    int n; cin >> n;
    int k; cin >> k;
    int array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    sort(array, array +n);

    //max number of diamonds in case when i is the smallest diamond
    vector<int> amtAbvi(n);

    //max number of diamonds in case when i is the largest diamond
    vector<int> amtBeli(n);

    int left(0),right(0);

    while(right < n){
        if(array[right] - array[left] <= k){
            amtAbvi[left] = right - left +1;
            amtBeli[right] = right - left +1;
            right++;

        }else left++;
    }

    int maxBel(0), ans(0);
    for(int i = 1; i < n; i ++ ){
        maxBel = max(maxBel, amtBeli[i-1]);
        ans = max(ans, maxBel + amtAbvi[i]);
    }
    cout << ans;
}