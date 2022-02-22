#include <iostream>
#include <bits/stdc++.h>
//accepted first try ggs - Sriram Kalki
using namespace std;
int main(){
    string goal;
    cin >> goal;
    int n;
    cin >> n;
    string s;
    string current;
    for(int i=0; i<n;i++){
        cin >> current;
        if(current == goal){
            cout << "YES";
            return 0;
        }
        s += current;

    }
    char letter1 = goal[0];
    char letter2 = goal[1];
    bool found1 = false;
    bool found2 = false;

    for(int i=1; i<s.length(); i=i+2){
        if(s[i] == letter1){
            found1 = true;
            break;
        }
    }
    for(int i=0; i<s.length(); i=i+2){
        if(s[i] == letter2){
            found2 = true;
            break;
        }
    }
    if(found1 && found2){
        cout << "YES";
    }else{
        cout << "NO";
    }
}