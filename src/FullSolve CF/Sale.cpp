#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    sort(array,array+n);
    int ans(0);
    for(int i=0; i<m; i++){
        if(array[i] <=0)
            ans +=array[i];
    }
    cout << ans*(-1);

}