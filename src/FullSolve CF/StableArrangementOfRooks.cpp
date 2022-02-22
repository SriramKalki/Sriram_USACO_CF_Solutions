#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        bool unstable = false;
        int n,k;
        cin >> n >> k;
        if(n %2 ==0){
            if(n/2 < k){
                cout << -1 << endl;
                unstable = true;
            }
        }else{
            if((n+1)/2 <k){
                cout << -1 << endl;
                unstable = true;
            }
        }
        if(!unstable) {
            int x(0), y(0),z(0); //k is amt of rocks
            /*  0 1 2 3 4 5
             *  1   //grid
             *  2
             *  3
             *  4
             *  5
             */
            char array[n][n];
            for (int j = 0; j < n; j++) {
                for (int e = 0; e < n; e++) {
                    if (j == x && e == y && z<k) {
                        array[j][e] = 'R';
                        x = x + 2;
                        y = y + 2;
                        z++;
                    } else {
                        array[j][e] = '.';
                    }

                }
                for (int s = 0; s < n; s++) {
                    cout << array[j][s];
                }
                cout << endl;
            }
        }

    }


}