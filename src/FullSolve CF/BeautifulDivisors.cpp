#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int answer;
    int generation[] = {1,6,28,120,496,2016,8128,32640};
    for(int i=0; i<8; i++){
        if(n%generation[i] == 0){
            answer = generation[i];
        }

    }
    cout << answer;
}