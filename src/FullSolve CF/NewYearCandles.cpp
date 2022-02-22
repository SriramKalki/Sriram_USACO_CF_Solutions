#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int answer =a;
    //a should be the current candles
    while(a / b >=1){
        answer += floor(a/b);
        a = floor(a/b) + a - b * floor(a/b);
    }
    cout << answer;




}