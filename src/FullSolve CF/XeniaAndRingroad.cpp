#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,m;
    cin >> n >> m;
    ll position =1;
    ll length =0;
    ll array[m];
    //m tasks
    //n houses
    for(int i=0; i<m; i++){
        cin >> array[i];
    }
    for(int i=0; i<m; i++){

        if(array[i] >= position){
            length += (array[i] - position);
            position = array[i];
        }else{
            length += (n+array[i]-position);
            position = array[i];
        }
    }
    cout << length;



}