#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    bool segment = false;

    if(2*max(max(a,b),c) < a+b+c||2*max(max(a,b),d) < a+b+d||2*max(max(a,c),d) < a+c+d||2*max(max(b,c),d) < b+c+d){
        cout << "TRIANGLE";
    }else if(2*max(max(a,b),c) == a+b+c||2*max(max(a,b),d) == a+b+d||2*max(max(a,c),d) == a+c+d||2*max(max(b,c),d) == b+c+d){
        cout << "SEGMENT";
    }else{
        cout << "IMPOSSIBLE";
    }




}