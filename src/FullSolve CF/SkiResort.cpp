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
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        ll int n,k,q; cin >> n >> k >> q;
        ll int a[n];
        for(int j = 0; j<n; j++){
            cin >> a[j];
        }

        ll int answer = 0;
        ll int streak = 0;

        for(int j=0; j<n; j++){
            if(a[j] > q){
                if(streak >= k){
                    answer += (streak - k + 1)*(streak -k + 2) / 2;
                }
                streak = 0;
            }else{
                streak++;
            }
        }

        if(streak >= k){
            answer += (streak - k + 1)*(streak -k + 2) / 2;
        }

        cout << answer << endl;
    }
}