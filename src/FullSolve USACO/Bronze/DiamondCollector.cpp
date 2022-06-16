#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>


using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("diamond");
    int n,k;
    cin >> n >> k;
    int array[n];
    int answer(0),current(1),val;
    for(int i=0; i<n; i++){
        cin >> array[i];


    }
    sort(array,array+n);
    for(int i=0; i<n-1; i++){
        val = array[i];

        for(int j=i+1; j<n; j++){
            if(array[j] <= val + k){
                current++;
            }else{
                break;
            }


        }
        answer = max(answer,current);
        current = 1;


    }
    cout << answer;




}