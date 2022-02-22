#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//lower time complexity :) problem 427B
int main(){
    int n,t,c;
    cin >> n >> t >> c;
    int array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];

    }

    int answer =0;
    bool illegal = false;
    for(int i=0; i<=n-c; i++){
        for(int j=i; j<i+c; j++){
            if(array[j] > t){
                illegal = true;
                break;
            }
        }
        if(!illegal){
            answer++;

        }
        illegal = false;

    }
    cout << answer;

}