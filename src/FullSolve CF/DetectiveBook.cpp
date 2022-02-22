#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int pages;
    cin >> pages;
    int mystery[pages];
    bool ongoing[pages];

    for(int i=0; i<pages; i++){
        cin >> mystery[i];
        mystery[i]--;
        ongoing[i] = false;
    }
    int days =0;
    bool caseClosed = false;
    for(int i=0; i<pages; i++){
        //i is current page
        ongoing[i] = true;
        for(int j=0; j<=i; j++){
            if(mystery[j] == i){
                ongoing[j] = false;
            }
        }
        caseClosed = true;
        for(int k=0; k<=i; k++){
            if(ongoing[k]){
                caseClosed = false;
                break;
            }

        }
        if(caseClosed){
            days++;
        }



    }
    cout << days;



}