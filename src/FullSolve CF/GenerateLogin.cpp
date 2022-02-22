#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    string first,last;
    cin >> first >> last;

    cout << first[0];
    for(int i=1; i<first.length(); i++) {
        if ( first[i] < last[0]) {
            cout << first[i];

        }else{
            break;
        }
    }
    cout << last[0];

}