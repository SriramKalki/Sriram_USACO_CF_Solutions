#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int minimum[n],maximum[n];
    int a,b;
    for(int i=0; i<n; i++){

        cin >> a >> b;
        minimum[i] = min(a,b);
        maximum[i] = max(a,b);

    }
    bool flag = false;
    int minimalDistance = 1000000000;
    for(int i=minimum[0]; i<= maximum[0]; i++){
        for(int j=0; j<n; j++){
            if (!(minimum[j] <= i && maximum[j] >= i)){
                flag = true;
                break;
            }


        }
        if(!flag){
            minimalDistance = min(minimalDistance,abs(x-i));

        }
        flag = false;


    }
    if(minimalDistance == 1000000000){
        cout << -1;
    }else{
        cout << minimalDistance;
    }



}