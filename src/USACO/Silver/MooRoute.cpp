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
    int n;
    cin >> n;
    int a[n+1];
    for(int i=0; i<n; i++){
        cin >> a[i];
    
    }
    a[n] = 0;
    
    string s = "";
    int i=0;
    
    while(!(i==0 && a[i] == 0)){
        while(a[i] > 0){
            s += 'R';
            a[i]--;
            i++;
        }
        
        while(i > 0 && (a[i-1] > 1 || a[i] == 0 )){
            s += 'L';
            i--;
            a[i]--;
            
        }
    }
    cout << s;
}
    
