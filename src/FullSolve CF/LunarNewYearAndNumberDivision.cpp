#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ll n;
    cin >> n;
    ll array[n];
    for(int i=0;i<n;i++){
        cin >> array[i];
    }

    sort(array,array+n);
    ll sum(0);
    for(int i=0; i< n/2;i++){
        sum += (array[i] + array[n-1-i])*(array[i] + array[n-1-i]);
    }
    cout << sum;


}
