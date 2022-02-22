#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    ll array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    ll sum = array[n-1];
    ll min = sum;

    for(int i=n-2; i>=0; i = i-1){
        if(min >=1){
            min--;
        }
        if(array[i] > min) {
            while (array[i] > min) {
                array[i]--;
            }
            sum += array[i];

            min = array[i];
        }else if (array[i] < min){
            while(array[i] < min){
                min--;
            }
            sum += array[i];
        }else{
            sum += array[i];
        }

    }
    cout << sum;



}