#include<iostream>
#include<cmath>
#include<numeric>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    int n;
    int j=0;
    cin >>t;
    bool flag = false;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int i =2; i<n; i++){
            j= n-i-1;
            if(__gcd(i,j) ==1 && i!=j && j!=1){
                cout << i << " " << j << " " << __gcd(i,j) << endl;
                flag =true;
            }


            if(flag){
                break;
            }
        }
        flag = false;


    }




}

