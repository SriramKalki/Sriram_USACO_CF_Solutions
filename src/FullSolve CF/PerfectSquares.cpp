#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
bool isPerfect(int x){
    if(x <0){
        return false;
    }else{
        for(int i=0; i * i <= x; i++){
            if(i*i == x){
                return true;
            }

        }
        return false;

    }

}
int main(){
    int n;
    cin >> n;
    int regular[n];
    bool array[n];
    for(int i=0; i<n; i++){
        cin >> regular[i];

    }
    sort(regular,regular+n,greater<>());
    for(int i=0; i<n; i++){
        array[i] = isPerfect(regular[i]);
    }
    for(int i=0; i<n; i++){
        if(!array[i]){
            cout << regular[i];
            return 0;

        }

    }


}