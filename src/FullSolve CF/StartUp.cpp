#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0; i< s.length(); i++){
        if(s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'F' || s[i] == 'G' || s[i] == 'J' ||  s[i] == 'K' ||  s[i] == 'L' ||  s[i] == 'N' ||  s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S' || s[i] == 'Z' ){
            cout << "NO";
            return 0;
        }

    }

    if(s.length() % 2 == 0){
        //s[0] , s[s.length-1];
        int a(0), b(s.length()-1);
        while( a < b){
            if(s[a] != s[b]){
                cout << "NO";
                return 0;
            }else{
                a++;
                b--;
            }
        }
        cout << "YES";
        return 0;
    }else{
        int a(0), b(s.length()-1);
        while( a <= b){
            if(s[a] != s[b]){
                cout << "NO";
                return 0;
            }else{
                a++;
                b--;
            }
        }
        cout << "YES";
        return 0;


    }

}