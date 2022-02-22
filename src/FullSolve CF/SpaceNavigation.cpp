#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int u(0),d(0),r(0),l(0);
        string s;
        int x,y;
        cin >> x >> y;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            if(s[j] == 'U'){
                u++;
            }else if(s[j] == 'D'){
                d++;
            }else if(s[j] == 'R'){
                r++;
            }else{
                l++;
            }

        }

        //x direction
        int currX = r-l;
        bool verdict1 = false;
        bool verdict2 = false;
        bool alreadyOutputFalse = false;
        if(currX > x){
            if(currX -x > r){
                cout << "NO" << endl;
                verdict1 = true;
                alreadyOutputFalse = true;
            }
        }else{
            if(x-currX > l){
                cout << "NO" << endl;
                verdict1 = true;
                alreadyOutputFalse = true;
            }
        }
        //y direction
        int currY = u-d;
        if(currY > y){
            if(currY - y > u){
                if(!alreadyOutputFalse) {
                    cout << "NO" << endl;
                }

                verdict2 = true;


            }
        }else{
            if(y-currY > d){
                if(!alreadyOutputFalse) {
                    cout << "NO" << endl;
                }
                verdict2 = true;
            }
        }

        if(!verdict2 && !verdict1){
            cout << "YES"<<endl;
        }




    }

}