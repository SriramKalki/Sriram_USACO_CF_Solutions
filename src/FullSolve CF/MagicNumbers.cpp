#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int oneconsec(0),fourconsec(0);

    for(int i=0; i< s.length(); i++){
        if(s[i] == '1'){
            oneconsec++;
            fourconsec=0;
        }else if(s[i] == '4'){
            oneconsec=0;
            fourconsec++;
        }else{
            //some other number has been detected
            cout << "NO";
            return 0;

        }
        if(fourconsec > 2 || s[0] == '4'){
            cout << "NO";
            return 0;
        }


    }
    cout << "YES";
    return 0;


}