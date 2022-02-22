#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
    int base=1;
    int n;
    int i=1;
    int length =0;



    int sum =0;
    while(base <= 100){
        base++;
        for(int d=1; d<100; d++){
            n = d*d;
            length =0;
            i = 1;
            sum =0;
            while(n >= i){
                i*= base;
                length++;

            }
            i /=base;
            for(int j=0; j<length; j++){

                sum += floor(n/i);
                n -= i*floor(n/i);

                i /=base;
            }
            if(d == sum){
                cout << d << " is a digital number in base " << base << endl;
            }

        }
        cout << "__________________________" << endl;
    }



}