#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>


using namespace std;



void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("measurement");
    int n;
    cin >> n;
    int a[101];
    int b[101];
    int c[101];

    for(int i=0; i<101; i++){
        a[i]=7;
        b[i]=7;
        c[i]=7;

    }
    bool previousA (true), previousB (true), previousC (true);
    bool currentA (true), currentB (true), currentC (true); //booleans to store which is in first rn
    int days;
    string name;
    int add;
    for(int i=0; i<n; i++){
        cin >> days;
        cin >> name;
        cin >> add;

        if(name == "Bessie"){

            for(int j=days; j<101; j++){
                a[j] += add;
            }
        }else if(name == "Elsie"){

            for(int j=days; j<101; j++){
                b[j] += add;
            }
        }else{

            for(int j=days; j<101; j++){
                c[j] += add;
            }
        }
    }


    int answer =0;

    for(int i=1; i<101; i++){
        previousA = currentA;
        previousB = currentB;
        previousC = currentC;
        currentA = false;
        currentB = false;
        currentC = false;
        if(a[i] >= b[i] && a[i] >= c[i]){
            currentA = true;
        }

        if(b[i] >= c[i] && b[i] >= a[i]){
            currentB = true;
        }
        if(c[i] >= a[i] && c[i] >= b[i]){
            currentC = true;
        }

        if(previousA != currentA || previousB != currentB || previousC != currentC){
            answer++;


        }

    }
    cout << answer;




}