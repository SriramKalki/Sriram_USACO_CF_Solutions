#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

#define f float


using namespace std;


int main(){
    int n,t;
    cin >> n >> t;
    int x=1;
    for(int i=0; i<n; i++){
        x *=10;
    }

    if(n==1 && t ==10){
        cout << -1;
    }else if(n>=2 && t==10){
        cout << 1;
        for(int i=0; i< n-1; i++){
            cout << 0;
        }

    }else{
        for(int i=0; i<n; i++){
            cout << t;
        }


    }





}