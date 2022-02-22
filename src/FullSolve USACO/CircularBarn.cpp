#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}



int main(){
    setIO("cbarn");
    int n;
    cin >> n;
    int array[n];

    for(int i=0; i<n;i++){
        cin >> array[i];
    }
    int ans=100000000;
    int curr=0;
    int x=0;
    for(int i=0; i<n;i++){
        //this is the door value (i)
        for(int j=0; j<n; j++){
            if(i>j){
                curr += (n+j-i)*array[j];
            }else if(i<j){
                curr += (j-i)*array[j];
            }else{
                curr +=0;
            }
        }
        ans = min(ans,curr);
        curr=0;
    }
    cout << ans;



}

