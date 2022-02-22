#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    sort(array,array+n);
    ll max = array[n-1];
    ll nextmax = array[n-2];
    ll difference = max - nextmax;
    cout << m*max -  (m/(k+1))* difference;




}