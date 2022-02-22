#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int array[6];
    int sum(0);
    for(int i=0; i<6; i++){
        cin >> array[i];
        sum += array[i];
    }
    if(sum ==0){
        cout << "YES";
        return 0;
    }
    for(int a=0; a<4; a++){
        for(int b=a+1; b<5; b++){
            for(int c=b+1; c<6; c++){
                if(array[a]+array[b]+array[c] != 0) {
                    if (sum % (array[a] + array[b] + array[c]) == 0 && sum / (array[a] + array[b] + array[c]) == 2) {
                        cout << "YES";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO";
}