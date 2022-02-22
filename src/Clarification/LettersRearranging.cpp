#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool palindrome(string s){
    if(s.length() %2 ==0){
        for(int i=0; i<s.length()/2; i++){
            if(s[i] != s[s.length()-i-1]){
                return false;
            }

        }
        return true;
    }else{
        for(int i=0; i<(s.length()-1)/2;i++){
            if(s[i] != s[s.length()-i-1]){
                return false;
            }
        }
        return true;
    }

}

int main(){
    int t;
    cin >> t;
    string s;
    int a,b;
    bool similar = true;
    int loc;
    for(int i=0;i<t;i++){
        cin >> s;
        if(s.length() ==1){
            cout << -1 << endl;
            break;
        }
        if(palindrome(s)){
            cout << "PALINDROME";
            if(s.length() % 2 ==0) {
                for (int j = 0; j < (s.length() / 2)-1; i++){
                    if(s[j] != s[j+1]){
                        similar = false;
                        loc =j;
                        break;

                    }
                }
                if(!similar){
                    swap(s[loc],s[loc+1]);
                    for(int j=0; j<s.length();j++){
                        cout << s[j];

                    }
                    cout << endl;
                    similar = true;
                }else{
                    cout << -1 << endl;
                    similar = true;
                }
            }else{
                for (int j = 0; j < ((s.length()-1) / 2); i++){
                    if(s[j] != s[j+1]){
                        similar = false;
                        loc =j;
                        break;

                    }
                }
                if(!similar){
                    a= s[loc];
                    b= s[loc+1];
                    s[loc+1] = a;
                    s[loc] =b;

                    for(int j=0; j<s.length();j++){
                        cout << s[j];

                    }
                    cout << endl;
                    similar = true;
                }else{
                    cout << -1 << endl;
                    similar = true;
                }




            }
        }else{
            for(int j=0; j<s.length();j++){
                cout << s[j];

            }
            cout << endl;
        }
    }


}