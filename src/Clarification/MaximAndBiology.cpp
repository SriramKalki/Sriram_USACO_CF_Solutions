#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,curr,change(0),currChange(0),x(0);
    cin >> n;
    string s;
    cin >> s;
    int goal[] = {0,2,19,6};
    int string[n];
    for(int i=0; i<n; i++){
        curr = s[i];
        string[i] = int(curr) - 65;
    }
    for(int i=0; i<=n-4;i++){
        for(int j=i; j<i+4; j++){
            if(string[j] % 26 <= goal[x] % 26){
                currChange += min(goal[x] - string[j],26-goal[x] + string[j]);
            }else{
                currChange += min(-goal[x] + string[j],26-string[j]+goal[x]);
            }
            x++;
        }
        x=0;
        change = min(change,currChange);

        currChange =0;
    }

    cout << change;
}