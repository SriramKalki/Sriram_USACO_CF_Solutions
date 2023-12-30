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
    setIO("sleepy");
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >>a[i];
    }
    
    int ans= n;
    ans--;
    for(int i=n-1; i>=0; i--){
        if(a[i] > a[i-1]){
            ans--;
        }else{
            break;
        }
    }
    cout << ans;
}
