#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    int lengths[3];


    for(int i=0; i<t; i++) {
        for (int i = 0; i < 3; i++) {
            cin >> lengths[i];

        }
        sort(lengths, lengths + 3, greater<>());
        //greatest to least

        if (lengths[0] == lengths[1]) {
            if (lengths[2] % 2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (lengths[1] == lengths[2]) {
            if (lengths[0] % 2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (lengths[0] == lengths[1] + lengths[2]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}