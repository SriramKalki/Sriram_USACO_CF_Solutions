#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("outofplace");
    int n;
    cin >> n;

    int array[n],array2[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
        array2[i] = array[i];
    }
    sort(array2,array2+n);
    int answer =-1;
    for(int i=0; i<n; i++){
        if(array[i] != array2[i]){
            answer++;
        }
    }
    cout << answer;
}