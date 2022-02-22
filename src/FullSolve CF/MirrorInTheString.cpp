#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    string previousString;
    cin >> t;
    int length,loc;
    bool all = true;
    for(int i=0; i<t; i++){
        cin >> length >> previousString;
        if(previousString[0] > previousString[1]){
            for(int j=1; j<previousString.length()-1;j++){
                if(previousString[j] < previousString[j+1]){
                    loc = j+1;
                    all =false;
                    break;
                }

            }
            if(all){
                loc = previousString.length();


            }
            all = true;
        }else if(previousString[0] <= previousString[1]){
            loc =1;

        }
        for(int j=0; j<loc;j++){
            cout << previousString[j];
        }
        for(int j = loc -1; j>=0; j--){
            cout << previousString[j];
        }
        cout << endl;

    }

}