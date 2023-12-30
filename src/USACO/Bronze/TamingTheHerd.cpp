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
    setIO("taming");
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    if(a[0] == -1){
        a[0] = 0;
    }else if(a[0] != 0){
        cout << -1;
        return 0;
    }
    
    for(int i=n-1; i>=0; i--){
        if(a[i] == -1 || a[i] == 0) continue;
        if(a[i-1] == -1){
            a[i-1] = a[i] - 1;
        }else if(a[i-1] != a[i] -1){
            cout << -1;
            return 0;
        }
    }
    
    int zeros = 0;
    int unknowns = 0;
    for(int i=0; i <n; i++){
        if(a[i] == 0) zeros++;
        if(a[i] == -1) unknowns++;
    }
    
    cout << zeros << " " << zeros + unknowns;
    
}
