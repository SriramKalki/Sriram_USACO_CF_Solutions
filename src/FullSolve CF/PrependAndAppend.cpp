#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for(int i=0; i<n/2; i++){
            if((s[i] == '0' && s[n-i - 1] == '1') || (s[i] == '1' && s[n - i - 1] == '0')){
                ans -=2;
            }else{
                break;
            }
        }

        cout << ans << endl;

    }
}