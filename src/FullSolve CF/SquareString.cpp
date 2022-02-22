#include <iostream>

using namespace std;

int main(){
    string s;
    int t;
    cin >> t;
    bool square = true;
    for(int i=0; i<t; i++){
        cin >>s;
        if(s.length() % 2 ==1){
            cout << "NO" << endl;

        }else {
            for (int i = 0; i < s.length() / 2; i++) {
                if(s[i] != s[i+ s.length()/2]){
                    cout << "NO" << endl;
                    square = false;
                    break;
                }

            }
            if(square) {
                cout << "YES" << endl;
            }
        }
        square = true;
    }



}