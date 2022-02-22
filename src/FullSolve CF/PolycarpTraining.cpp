#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k(0),x(0);
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    bool contest = true;
    sort(array,array+n);
    while(contest){
        k++;
        while(array[x] <k && x<= n-1){
            x++;
        }

        if(x==n){
            cout << k-1;
            contest=false;
            return 0;
        }
        x++;
    }


}