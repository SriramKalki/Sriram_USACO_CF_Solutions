#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n ;
    cin >> k;

    int array[n];
    string s;
    cin >> s;
    for(int i=0; i<n; i++){
        if(s[i] == '.'){
            array[i] =1;
        }else{
            array[i] =0;
        }
    }
    int position = n-1;
    bool jump;
    while(position >=0){
        jump = false;
        for(int i=position-1; i>position-1-k;i--){
            if(i == 0){
                cout << "YES";
                return 0;
            }
            if(array[i] == 1){
                position = i;
                jump = true;
                break;
            }
        }
        if(!jump){
            cout << "NO";
            return 0;
        }

    }


}