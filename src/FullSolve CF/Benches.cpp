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
    int finalMaximum = array[n-1]+m;
    //Algorithm:
    //To find the minimum, we increment all elements that are less than the current maximum. To find the maximum, we find the highest element and simply add m


    int x=0;
    while(m > 0){

        if(x == n-1){
            array[x]++;
            m--;
            x =0;
        }else{
            m -= (array[n-1]-array[x]);
            array[x] = array[n-1];
            x++;
        }
    }

    cout << array[n-1] << endl << finalMaximum;

}