#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;

    cin >> n;

    int array[n];

    for(int i=0; i<n; i++){

        cin >> array[i];

    }

    sort(array,array+n);
    cout << min(array[n-2] - array[0], array[n-1] - array[1]);


}